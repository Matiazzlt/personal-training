#include "rush02.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

char	*ft_strndup(char *s, int n)
{
	char	*r;
	int		i;

	r = malloc(n + 1);
	if (!r)
		return (0);
	i = 0;
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	r[n] = '\0';
	return (r);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

int	ft_check_number(char *s, char **start)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	*start = s + i;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}
