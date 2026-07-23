/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:04:02 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/22 11:33:39 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	pl;
	int	*tab;

	i = 0;
	pl = max - min + 1;
	if (min > max)
		return (NULL);
	tab = malloc(sizeof(int) * pl);
	if (!tab)
		return (NULL);
	while (i < pl)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*int	main(void)
{
	int	*tab;
	int	i;

	i = 0;
	tab = ft_range(122, 633);
	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/
