/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 02:28:43 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/10 12:04:41 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	total;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	total = 1;
	while (nb > 1)
	{
		total = total * nb;
		nb--;
	}
	return (total);
}

//int	main(void)
//{
//	printf("%d", ft_iterative_factorial(7));
//}
