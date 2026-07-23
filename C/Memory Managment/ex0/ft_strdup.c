/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:59:22 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/22 11:33:52 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}*/

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (src == 0)
		return (0);
	len = ft_strlen(src);
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	char	*src;
	char	*res;

	src = "NUMANUMAYE";
	res = ft_strdup(src);
	printf("%s\n", res);
	free(res);
	return (0);
}*/
