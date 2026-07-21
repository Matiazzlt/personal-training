/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:48:42 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/21 15:35:54 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_container(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	ft_any(char **tab, int (*f)(char*))
{
	int	c;

	c = 0;
	while (tab[c])
	{
		if (f(tab[c]))
			return (1);
		c++;
	}
	return (0);
}

int	main(void)
{
	char	*tab[] = {"hello", "world", "numanumaye", NULL};
	char	*tab2[] = {"numa numa ye", NULL};
	char	*tab3[] = {"iop", NULL};

	printf("%d\n", ft_any(tab, ft_container));
	printf("%d\n", ft_any(tab2, ft_container));
	printf("%d\n", ft_any(tab3, ft_container));
}
