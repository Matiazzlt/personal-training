/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:24:51 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/20 14:34:16 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
/*
int	ft_square(int nb)
{
	while(nb != 60)
	{
		nb = nb * nb;
		return(nb);
	}
	return (nb);
}
*/
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*r;

	i = 0;
	r = (int *)malloc(sizeof(int) * length);
	if (!r)
		return (NULL);
	while (i < length)
	{
		r[i] = f(tab[i]);
		i++;
	}
	return (r);
}
/*
int	main(void)
{
	int	tab[] = {1, 89, 3, 4, 5};
	int	*res;
	int	i;
	
	i = 0;
	res = ft_map(tab, 5, &ft_square);
	while (i < 5)
	{
		printf("%d ", res[i]);
		i++;
	}
	free(res);
	return (0);
}*/
