/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:17:16 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/19 15:18:28 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// Vérifie que l'argument est un nombre valide :
// uniquement des chiffres, et au moins un.
// pas de '+' ni d'espaces acceptés)
static int	ft_check_number(char *s)
{
	int	i;

	if (s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Affiche un message d'erreur et retourne 1 (code de sortie "échec").
// Permet d'écrire "return (ft_error(...));" en une ligne.
static int	ft_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

// Convertit et affiche le nombre.
// Cas spécial : "0" tout seul -> on affiche "zero" directement,
// car ft_say_number ne dit rien pour zéro.
// first = 1 au départ : c'est lui qui gère les espaces entre mots.
static int	ft_convert(char *num, t_dict *d)
{
	int	first;

	first = 1;
	while (num[0] == '0' && num[1] != '\0')
		num++;
	if (num[0] == '0' && num[1] == '\0')
	{
		if (!ft_put_key(0, d, &first))
			return (0);
	}
	else if (!ft_say_number(num, d, &first))
		return (0);
	write(1, "\n", 1);
	return (1);
}

// Étapes : valider l'argument -> lire le dico -> le parser ->
// convertir. Le seul malloc est le buffer du fichier : on le
// free avant chaque sortie, succès comme erreur.
int	main(int argc, char **argv)
{
	t_dict	d;
	char	*buf;

	if (argc != 2)
		return (ft_error("Error\n"));
	if (!ft_check_number(argv[1]))
		return (ft_error("Error\n"));
	buf = ft_read_file("numbers.dict");
	if (!buf)
		return (ft_error("Dict Error\n"));
	if (!ft_dict_parse(buf, &d) || !ft_convert(argv[1], &d))
	{
		free(buf);
		return (ft_error("Dict Error\n"));
	}
	free(buf);
	return (0);
}
