/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:15:39 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/14 10:34:12 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("NUMANUMAYE"));
	printf("%d\n", ft_str_is_lowercase("petiteslettres"));
	printf("%d\n", ft_str_is_lowercase("123"));
	printf("%d\n", ft_str_is_lowercase("az bin"));
	printf("%d\n", ft_str_is_lowercase(""));
}*/
