/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:01:24 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/13 11:01:03 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	cursor;
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[b] < tab[a])
			{
				cursor = tab[a];
				tab[a] = tab[b];
				tab[b] = cursor;
			}
			b++;
		}
		a++;
	}
}

//int	main(void)
//{
//	int	string[] = {21, 55, 88, 64, 10, 9};
//	int	a;
//	int	size;
//
//	size = 6;
//	a = 0;
//	ft_sort_int_tab(string, size);
//	while (a < 6)
//	{
//		printf("%d", string[a]);
//		a++;
//	}
//}
