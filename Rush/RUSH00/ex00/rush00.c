/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantoszc <aantoszc@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:12:35 by aantoszc          #+#    #+#             */
/*   Updated: 2026/07/05 17:12:42 by aantoszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	ycmp;
	int	xcmp;

	if (x <= 0 || y <= 0)
		ft_putchar('\n');
	ycmp = 1;
	while (ycmp <= y)
	{
		xcmp = 1;
		while (xcmp <= x)
		{
			if ((xcmp == 1 || xcmp == x) && (ycmp == y || ycmp == 1))
				ft_putchar('o');
			else if (xcmp == 1 || xcmp == x)
				ft_putchar('|');
			else if (1 == ycmp || ycmp == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			xcmp++;
		}
		ft_putchar('\n');
		ycmp++;
	}
}
