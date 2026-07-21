/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:53:31 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/08 15:53:49 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_power(nb, power -1));
	}
}

//int	main(void)
//{
//	printf("%d", ft_recursive_power(5, 5));
//	printf("%d", ft_recursive_power(1, 6));
//	printf("%d", ft_recursive_power(0, 0));
//}
