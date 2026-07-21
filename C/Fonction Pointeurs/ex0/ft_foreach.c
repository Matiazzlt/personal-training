/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:42:24 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/20 13:21:55 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*void	ft_putnbr(int nb)
{
	char	res1;

	if (nb > 9)
		ft_putnbr(nb / 10);
	res1 = nb % 10 + '0';
	write(1, &res1, 1);
}*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*int	main(void)
{
	int	tab[] = {1, 67, 2, 3, 4};

	ft_foreach(tab, 4, &ft_putnbr);
	write(1, "\n", 1);
	return (0);
}*/
