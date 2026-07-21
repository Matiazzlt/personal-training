/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:55:58 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/21 12:56:37 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*int	ft_container(char *str)
{
	while (str[0] != '\0')
		return (1);
	return (0);
}*/

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	c;
	int	count;

	c = 0;
	count = 0;
	while (c < length)
	{
		if (f(tab[c]) != 0)
			count++;
		c++;
	}
	return (count);
}

/*int	main(void)
{
	char	*tab1[] = {"hello", "world", "numanumoye", "NULL"};
	char	*tab2[] = {"numanumaye", "NULL"};
	char	*tab3[] = {"iop"};

	printf("%d\n", ft_count_if(tab1, 4, ft_container));
	printf("%d\n", ft_count_if(tab2, 2, ft_container));
	printf("%d\n", ft_count_if(tab3, 1, ft_container));
}*/
