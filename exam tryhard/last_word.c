/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:30:42 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 15:28:45 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Un programme donc juste un main.
// Si il y a plus de deux arguments \n
// Si on est pas arrive a la fin de la string on avance
// On ecris le dernier mot
// retour a la ligne

int	main(int argc, char **argv)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
    	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' && argv[1][i + 1] != ' ' && argv[1][i + 1] != '\0')
			start = i + 1;
		i++;
	}
	while (argv[1][start] != ' ' && argv[1][start] != '\0')
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return 0;
}
