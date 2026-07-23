/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:35:35 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/22 18:33:00 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * len);
	if (!(*range))
		return (-1);
	while (i < len)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	int	*arr;
	int	res;

	res = ft_ultimate_range(&arr, 5, 10);
	printf("%i", res);
	return (0);
}*/
