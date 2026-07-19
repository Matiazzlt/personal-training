#include "rush02.h"

static int	ft_count_lines(char *s)
{
	int	c;

	c = 1;
	while (*s)
	{
		if (*s == '\n')
			c++;
		s++;
	}
	return (c);
}

static int	ft_add_entry(char *line, int len, t_dict *d)
{
	int	i;
	int	r;

	i = 0;
	r = ft_get_key(line, len, &i, &d->tab[d->size]);
	if (r <= 0)
		return (r);
	if (ft_get_val(line, len, i, &d->tab[d->size]) < 0)
	{
		free(d->tab[d->size].key);
		return (-1);
	}
	d->size++;
	return (1);
}

int	ft_dict_parse(char *buf, t_dict *d)
{
	int	i;
	int	start;

	d->size = 0;
	d->tab = malloc(sizeof(t_entry) * ft_count_lines(buf));
	if (!d->tab)
		return (0);
	i = 0;
	while (buf[i])
	{
		start = i;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (ft_add_entry(buf + start, i - start, d) < 0)
			return (0);
		if (buf[i] == '\n')
			i++;
	}
	return (1);
}

void	ft_dict_free(t_dict *d)
{
	int	i;

	i = 0;
	while (i < d->size)
	{
		free(d->tab[i].key);
		free(d->tab[i].val);
		i++;
	}
	free(d->tab);
	d->tab = 0;
	d->size = 0;
}

char	*ft_lookup(t_dict *d, char *key)
{
	int	i;

	i = 0;
	while (i < d->size)
	{
		if (ft_strcmp(d->tab[i].key, key) == 0)
			return (d->tab[i].val);
		i++;
	}
	return (0);
}
