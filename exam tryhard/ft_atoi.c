/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:51:50 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 10:54:06 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Atoi va d'abord ecarter tout ce aui st espace tab ou autres
//
// Ensuite il va comter le nombre de '-' et de '+' pour estimer
// si le nombre est positif ou negatif (-- = negatif, - = positif)
//
// Apres ca, on va compter le nombre de chiffres (si [i] n'est plus
// un chiffre, return) il va stocker la veleur de la chaine dans
// rep, multiplier par 10 et convertir.

int	ft_atoi(char *str)
{
	int	i;
	int	rep;
	int	sign;

	i = 0;
	rep = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rep = rep * 10 + (str[i] - '0');
		i++;
	}
	return (rep * sign);
}

int	main(void)
{
	char	str[] = " ---+--+1234ab567";	
	printf("%d\n", ft_atoi(str));
	return (0);
}
