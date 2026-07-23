/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:16:47 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 13:28:47 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// On utilise un putchar pour se faciliter la tache lors de l'affichage 
// du nombre final

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Putnbr va gerer le int min (-2147483648) qui si non preciser pose
// probleme, puis on gere les nombres negatifs en affichant un '-'
// puis on fini par diviser les nombres pour les reafficher dans
// l'ordre avec modulo dans un putchar tout en les convertissant
// en char pour aue write puisse les ecrire.

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int	main(void)
{
	ft_putnbr(58);
	write(1, "\n", 1);
	ft_putnbr(-32);
	write(1, "\n", 1);
	ft_putnbr(789654);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
}
