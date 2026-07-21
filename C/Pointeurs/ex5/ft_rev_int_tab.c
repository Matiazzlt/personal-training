/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:35:44 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/13 10:53:58 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	cursor;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		cursor = tab[start];
		tab[start] = tab[end];
		tab[end] = cursor;
		start++;
		end--;
	}
}

/*int	main(void)
{
	int	string[] = {1, 2, 3, 4 ,5, 6};
	int	size;
	int	i;

	i = 0;
	size = 6;
	ft_rev_int_tab(string, size);
	while (i < size)
	{
		printf("%d", string[i]);
		i++;
	}
	return (0);
}*/
