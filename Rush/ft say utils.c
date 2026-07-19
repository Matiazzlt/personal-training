#include "rush02.h"

void	ft_put_word(char *val, int *first)
{
	if (!first)
		return ;
	if (!*first)
		write(1, " ", 1);
	ft_putstr(val);
	*first = 0;
}

int	ft_put_key(int v, t_dict *d, int *first)
{
	char	buf[4];
	int		i;
	char	*val;

	i = 3;
	buf[3] = '\0';
	if (v == 0)
		buf[--i] = '0';
	while (v > 0)
	{
		buf[--i] = v % 10 + '0';
		v /= 10;
	}
	val = ft_lookup(d, buf + i);
	if (!val)
		return (0);
	ft_put_word(val, first);
	return (1);
}

int	ft_say_two(int v, t_dict *d, int *first)
{
	if (v == 0)
		return (1);
	if (v <= 20 || v % 10 == 0)
		return (ft_put_key(v, d, first));
	if (!ft_put_key(v / 10 * 10, d, first))
		return (0);
	return (ft_put_key(v % 10, d, first));
}
