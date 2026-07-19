#include "rush02.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static char	*ft_copy_val(char *l, int i, int end)
{
	char	*val;
	int		j;

	val = malloc(end - i + 1);
	if (!val)
		return (0);
	j = 0;
	while (i < end)
	{
		if (ft_is_space(l[i]))
		{
			val[j++] = ' ';
			while (i < end && ft_is_space(l[i]))
				i++;
		}
		else
			val[j++] = l[i++];
	}
	val[j] = '\0';
	return (val);
}

int	ft_get_key(char *l, int len, int *i, t_entry *e)
{
	int	ks;
	int	ke;

	while (*i < len && ft_is_space(l[*i]))
		(*i)++;
	if (*i == len)
		return (0);
	if (l[*i] == '+')
		(*i)++;
	ks = *i;
	while (*i < len && l[*i] >= '0' && l[*i] <= '9')
		(*i)++;
	if (*i == ks)
		return (-1);
	ke = *i;
	while (*i < len && ft_is_space(l[*i]))
		(*i)++;
	if (*i == len || l[*i] != ':')
		return (-1);
	(*i)++;
	while (ks < ke - 1 && l[ks] == '0')
		ks++;
	e->key = ft_strndup(l + ks, ke - ks);
	if (!e->key)
		return (-1);
	return (1);
}

int	ft_get_val(char *l, int len, int i, t_entry *e)
{
	int	end;

	while (i < len && ft_is_space(l[i]))
		i++;
	end = len;
	while (end > i && ft_is_space(l[end - 1]))
		end--;
	e->val = ft_copy_val(l, i, end);
	if (!e->val)
		return (-1);
	return (1);
}
