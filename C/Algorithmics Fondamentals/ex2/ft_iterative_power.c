/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:30:58 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/08 15:54:02 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	total;

	total = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		total = total * nb;
		power--;
	}
	return (total);
}

//int	main(void)
//{
//	printf("%d", ft_iterative_power(0, 0));
//	printf("%d", ft_iterative_power(7, 10));
//	printf("%d", ft_iterative_power(1, 8888888));
//}
