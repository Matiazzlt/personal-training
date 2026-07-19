#include "rush02.h"

static char	*ft_append(char *old, int oldlen, char *chunk, int n)
{
	char	*res;
	int		i;

	res = malloc(oldlen + n + 1);
	if (!res)
	{
		free(old);
		return (0);
	}
	i = -1;
	while (++i < oldlen)
		res[i] = old[i];
	i = -1;
	while (++i < n)
		res[oldlen + i] = chunk[i];
	res[oldlen + n] = '\0';
	free(old);
	return (res);
}

static char	*ft_read_loop(int fd, char *buf)
{
	char	chunk[4096];
	int		n;
	int		len;

	len = 0;
	n = read(fd, chunk, 4096);
	while (n > 0)
	{
		buf = ft_append(buf, len, chunk, n);
		if (!buf)
			return (0);
		len += n;
		n = read(fd, chunk, 4096);
	}
	if (n < 0)
	{
		free(buf);
		return (0);
	}
	return (buf);
}

char	*ft_read_file(char *path)
{
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(1);
	if (!buf)
	{
		close(fd);
		return (0);
	}
	buf[0] = '\0';
	buf = ft_read_loop(fd, buf);
	close(fd);
	return (buf);
}
