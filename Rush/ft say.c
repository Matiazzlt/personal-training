#include "rush02.h"

int	ft_say_small(char *n, int len, t_dict *d, int *first)
{
	int	v;
	int	i;

	v = 0;
	i = 0;
	while (i < len)
		v = v * 10 + (n[i++] - '0');
	if (v >= 100)
	{
		if (!ft_put_key(v / 100, d, first))
			return (0);
		if (!ft_put_key(100, d, first))
			return (0);
		return (ft_say_two(v % 100, d, first));
	}
	return (ft_say_two(v, d, first));
}

static int	ft_put_scale(int g, t_dict *d, int *first)
{
	char	*key;
	char	*val;
	int		i;

	key = malloc(3 * g + 2);
	if (!key)
		return (0);
	key[0] = '1';
	i = 0;
	while (i < 3 * g)
	{
		key[1 + i] = '0';
		i++;
	}
	key[3 * g + 1] = '\0';
	val = ft_lookup(d, key);
	free(key);
	if (!val)
		return (0);
	ft_put_word(val, first);
	return (1);
}

int	ft_say_number(char *n, int len, t_dict *d, int *first)
{
	int	head;
	int	g;

	while (len > 1 && *n == '0')
	{
		n++;
		len--;
	}
	if (len == 1 && *n == '0')
		return (1);
	if (len <= 3)
		return (ft_say_small(n, len, d, first));
	g = (len - 1) / 3;
	head = len - g * 3;
	if (!ft_say_small(n, head, d, first))
		return (0);
	if (!ft_put_scale(g, d, first))
		return (0);
	return (ft_say_number(n + head, len - head, d, first));
}
