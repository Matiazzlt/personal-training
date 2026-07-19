#include "sky_scrapers.h"

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_number(char c)
{
	if (c < '1' || c > '4')
		return (0);
	return (1);
}

int	ft_check_input(char *str, int strlen)
{
	int	i;

	i = 0;
	while (i < strlen)
	{
		if (!ft_is_number(str[i]))
			return (1);
		i += 2;
	}
	return (0);
}

int	ft_check_arg(int size, char **str)
{
	int	str_len;

	if (size != 2)
		return (1);
	str_len = ft_str_len(str[1]);
	if (str_len != 31)
		return (1);
	if (ft_check_input(str[1], str_len))
		return (1);
	return (0);
}

void	ft_print_error(void)
{
	write(1, "Error\n", 6);
}
