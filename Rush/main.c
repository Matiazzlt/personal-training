#include "rush02.h"

static int	ft_error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

static int	ft_try(char *num, t_dict *d, int *first)
{
	if (num[0] == '0' && num[1] == '\0')
		return (ft_put_key(0, d, first));
	return (ft_say_number(num, ft_strlen(num), d, first));
}

static int	ft_convert(char *num, t_dict *d)
{
	int	first;

	while (num[0] == '0' && num[1] != '\0')
		num++;
	if (!ft_try(num, d, 0))
		return (0);
	first = 1;
	ft_try(num, d, &first);
	write(1, "\n", 1);
	return (1);
}

static int	ft_run(char *path, char *arg)
{
	t_dict	d;
	char	*buf;
	char	*num;

	if (!ft_check_number(arg, &num))
		return (ft_error("Error\n"));
	buf = ft_read_file(path);
	if (!buf)
		return (ft_error("Dict Error\n"));
	if (!ft_dict_parse(buf, &d))
	{
		ft_dict_free(&d);
		free(buf);
		return (ft_error("Dict Error\n"));
	}
	if (!ft_convert(num, &d))
	{
		ft_dict_free(&d);
		free(buf);
		return (ft_error("Dict Error\n"));
	}
	ft_dict_free(&d);
	free(buf);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (ft_run("numbers.dict", argv[1]));
	if (argc == 3)
		return (ft_run(argv[1], argv[2]));
	ft_putstr("Error\n");
	return (1);
}
