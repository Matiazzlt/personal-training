/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:30:49 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 13:40:03 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Lui il est tout con mais je prefere le mettre quand meme
// On va simplement incrementer la valeur pointee par *ptr

void	ft_inc(int *ptr)
{
	(*ptr)++;
}

// Je me suis dis que vu cet exo est simple autant essayer
// d'experimenter dans un printf, et cette formulation fonctionne.

int	main(void)
{
	int	num;

	num = 5;
	printf("Before increment ; %d\n", num);
	ft_inc(&num);
	printf("After increment ; %d\n", num);
	return (0);
}
