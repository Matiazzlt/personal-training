#include "rush02.h"

// Compte la longueur d'une chaîne : on avance jusqu'au '\0'.
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Affiche une chaîne d'un coup avec write.
void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

// Compare deux chaînes.
// Retourne 0 si identiques, sinon la différence du 1er caractère qui diffère.
int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

// Affiche un mot, avec un espace AVANT sauf si c'est le premier mot.
// *first vaut 1 au départ, puis passe à 0 dès le premier mot affiché.
// Résultat : "four hundred two" sans espace parasite au début/à la fin.
void	ft_put_word(char *val, int *first)
{
	if (!*first)
		write(1, " ", 1);
	ft_putstr(val);
	*first = 0;
}
