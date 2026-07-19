#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_entry
{
	char	*key;
	char	*val;
}	t_entry;

typedef struct s_dict
{
	t_entry	*tab;
	int		size;
}	t_dict;

int		ft_strlen(char *s);
void	ft_putstr(char *s);
char	*ft_strndup(char *s, int n);
int		ft_strcmp(char *a, char *b);
int		ft_check_number(char *s, char **start);
char	*ft_read_file(char *path);
int		ft_dict_parse(char *buf, t_dict *dict);
void	ft_dict_free(t_dict *dict);
int		ft_get_key(char *l, int len, int *i, t_entry *e);
int		ft_get_val(char *l, int len, int i, t_entry *e);
char	*ft_lookup(t_dict *dict, char *key);
void	ft_put_word(char *val, int *first);
int		ft_put_key(int v, t_dict *d, int *first);
int		ft_say_two(int v, t_dict *d, int *first);
int		ft_say_small(char *n, int len, t_dict *d, int *first);
int		ft_say_number(char *n, int len, t_dict *d, int *first);

#endif
