/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:12:12 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/21 13:39:36 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*int	ft_test(int a, int b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	else
		return (0);
}*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	des;

	i = 0;
	asc = 0;
	des = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			des = 1;
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 1;
		i++;
	}
	if (asc == 1 && des == 1)
		return (0);
	return (1);
}

/*int	main(void)
{
	int	tab[] = {6, 4, 3, 5, 0};
	int	tab1[] = {1, 2, 3, 4, 5, 6};
	int     tab2[] = {55, 78, 21, 63, 54};

	printf("%d\n", ft_is_sort(tab, 5, ft_test));
	printf("%d\n", ft_is_sort(tab1, 6, ft_test));
	printf("%d\n", ft_is_sort(tab2, 5, ft_test));
}*/
