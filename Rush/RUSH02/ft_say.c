#include "rush02.h"

// Convertit un petit nombre (0 à 999) en texte ("42") puis cherche
// ce texte dans le dico et affiche le mot trouvé.
// On écrit les chiffres à l'envers dans buf : v % 10 donne le dernier
// chiffre, puis on divise par 10, et on recommence.
// Retourne 1 si le mot existe dans le dico, 0 sinon.
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

// Dit un nombre de 0 à 99.
// - 0 : on ne dit rien (le "00" de 400 est muet)
// - jusqu'à 20, ou dizaine ronde : le mot existe tel quel ("fifteen")
// - sinon : dizaine + unité, ex 42 -> "forty" + "two"
static int	ft_say_two(int v, t_dict *d, int *first)
{
	if (v == 0)
		return (1);
	if (v <= 20 || v % 10 == 0)
		return (ft_put_key(v, d, first));
	if (!ft_put_key(v / 10 * 10, d, first))
		return (0);
	return (ft_put_key(v % 10, d, first));
}

// Dit un groupe de 1 à 3 chiffres (0 à 999).
// On reconvertit d'abord le texte en int (v = v * 10 + chiffre).
// Si v >= 100 : centaine + "hundred" + le reste. Sinon : ft_say_two.
static int	ft_say_small(char *n, int len, t_dict *d, int *first)
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

// Affiche le mot d'échelle du groupe g :
// g = 1 -> clé "1000" (thousand), g = 2 -> "1000000" (million)...
// Ces nombres sont trop grands pour un int, donc on construit la
// clé en TEXTE : un '1' suivi de 3 * g zéros, dans un buffer fixe.
static int	ft_put_scale(int g, t_dict *d, int *first)
{
	char	buf[64];
	int		i;
	char	*val;

	buf[0] = '1';
	i = 0;
	while (i < 3 * g)
		buf[1 + i++] = '0';
	buf[3 * g + 1] = '\0';
	val = ft_lookup(d, buf);
	if (!val)
		return (0);
	ft_put_word(val, first);
	return (1);
}

// LA fonction principale : dit un nombre de taille illimitée.
// On travaille sur du TEXTE (jamais un int) pour ne pas être limité.
// Idée : découper en groupes de 3 chiffres.
// "1234567" -> "1" | "234" | "567"
//           -> "one" "million" + "two hundred thirty four" "thousand"
//              + "five hundred sixty seven"
// head = taille du 1er groupe (1 à 3 chiffres), g = nb de groupes
// qui suivent (donne l'échelle). Puis on RECOMMENCE sur le reste
// (récursion), après avoir sauté les zéros de tête du reste.
int	ft_say_number(char *n, t_dict *d, int *first)
{
	int	len;
	int	head;
	int	g;

	while (n[0] == '0' && n[1] != '\0')
		n++;
	if (n[0] == '0')
		return (1);
	len = ft_strlen(n);
	if (len <= 3)
		return (ft_say_small(n, len, d, first));
	g = (len - 1) / 3;
	head = len - g * 3;
	if (!ft_say_small(n, head, d, first))
		return (0);
	if (!ft_put_scale(g, d, first))
		return (0);
	return (ft_say_number(n + head, d, first));
}
