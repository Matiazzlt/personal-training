// rush02.h — la "table des matières" du projet.
// Version simplifiée : un seul argument (le nombre),
// dictionnaire fixe "numbers.dict".
// Fonctions autorisées : write, malloc, free, open, read, close.

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h> // write, read, close
# include <stdlib.h> // malloc, free
# include <fcntl.h>  // open, O_RDONLY

// Nombre max d'entrées du dico (largement assez pour numbers.dict)
# define MAX_ENTRIES 128

// Une entrée = une ligne du dico : "42: forty two"
// key -> "42" / val -> "forty two"
// (ce sont des pointeurs DANS le buffer du fichier, pas des copies)
typedef struct s_entry
{
	char	*key;
	char	*val;
}	t_entry;

// Le dictionnaire complet : un tableau fixe + le nb d'entrées
typedef struct s_dict
{
	t_entry	tab[MAX_ENTRIES];
	int		size;
}	t_dict;

// --- ft_utils.c ---
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_strcmp(char *a, char *b);
void	ft_put_word(char *val, int *first);

// --- ft_dict.c ---
char	*ft_read_file(char *path);
int		ft_dict_parse(char *buf, t_dict *d);
char	*ft_lookup(t_dict *d, char *key);

// --- ft_say.c ---
int		ft_put_key(int v, t_dict *d, int *first);
int		ft_say_number(char *n, t_dict *d, int *first);

#endif
