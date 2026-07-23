/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 11:10:14 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/23 11:28:53 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// un putnbr habituel t'as capte fratelo, juste sans putchar

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

// Pour faire simple, on commence a 1, si ;
//  - Si c'est un multiple de 3 ET 5 = fizzbuzz;
//  - Si c'est un multiple de 3 = fizz;
//  - Si c'est un multiple de 5 = buzz;
// Puis un retour a la ligne.
// VOILA UN MOMENT IL EST FACILE LUI TU CAPTES

void	fizzbuzz(void)
{
	int	nb;

	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(nb);
		write(1, "\n", 1);
		nb++;
	}
}

int	main(void)
{
	fizzbuzz();
}
