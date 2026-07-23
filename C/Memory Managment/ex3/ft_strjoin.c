/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-t <mlopez-t@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:53:50 by mlopez-t          #+#    #+#             */
/*   Updated: 2026/07/22 19:07:14 by mlopez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//Compte la longueur de str
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
//Recopie tout str avec les separateurs en plus
char	*ft_copy(char **strs, char *str, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while ((i < size - 1) && sep[j] != '\0')
		{
			str[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s1;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (size == 0)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
		return (s1);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1);
	s1 = malloc((sizeof(char) * len) + 1);
	s1 = ft_copy(strs, s1, size, sep);
	return (s1);
}

int	main(void)
{
	char	*str;
	char	*arguments[6] = {"vrm", "archi", "flemme", "de", "bosser", ""};

	str = ft_strjoin(5, arguments, "--");
	printf("%s\n", str);
	return (0);
}
