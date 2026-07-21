/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 17:07:24 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/18 17:50:03 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	a;
	char	b;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			a = "0123456789abcdef"[str[i] / 16];
			b = "0123456789abcdef"[str[i] % 16];
			write(1, &a, 1);
			write(1, &b, 1);
		}
		i++;
	}
}
/*
int	main(void)
{
	char	*str = "\b \n \t \0";

	ft_putstr_non_printable(str);
	return (0);
}*/
