#include "rush02.h"

// Taille max du fichier dico qu'on accepte (simplification :
// un seul malloc d'un gros buffer, au lieu d'agrandir en boucle)
#define BUF_SIZE 16384

// Lit TOUT le fichier dans un seul buffer malloc'é.
// read() retourne : >0 = octets lus, 0 = fin de fichier, <0 = erreur.
// On boucle jusqu'à la fin, puis on termine la chaîne par '\0'.
// Retourne le buffer (à free plus tard), ou 0 en cas d'erreur.
char	*ft_read_file(char *path)
{
	char	*buf;
	int		fd;
	int		len;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = malloc(BUF_SIZE);
	if (!buf)
		return (0);
	len = 0;
	n = read(fd, buf + len, BUF_SIZE - 1 - len);
	while (n > 0)
	{
		len += n;
		n = read(fd, buf + len, BUF_SIZE - 1 - len);
	}
	close(fd);
	if (n < 0)
	{
		free(buf);
		return (0);
	}
	buf[len] = '\0';
	return (buf);
}

// Retire les espaces/tabs au début ET à la fin d'une chaîne.
// Astuce : on ne copie rien, on avance juste le pointeur de départ,
// et on écrit un '\0' juste après le dernier vrai caractère.
static char	*ft_trim(char *s)
{
	char	*end;

	while (*s == ' ' || *s == '\t')
		s++;
	end = s + ft_strlen(s);
	while (end > s && (end[-1] == ' ' || end[-1] == '\t'))
		end--;
	*end = '\0';
	return (s);
}

// Traite UNE ligne (déjà terminée par '\0') et l'ajoute au dico.
// On cherche le ':' qui sépare clé et valeur, on le remplace par '\0' :
// la ligne devient DEUX chaînes ("42" et " forty two"), qu'on nettoie.
// Ligne vide -> ignorée. Pas de ':' ou clé vide -> erreur (0).
static int	ft_add_line(char *line, t_dict *d)
{
	char	*colon;
	char	*key;

	colon = line;
	while (*colon && *colon != ':')
		colon++;
	if (*colon != ':')
	{
		if (*ft_trim(line) == '\0')
			return (1);
		return (0);
	}
	*colon = '\0';
	key = ft_trim(line);
	while (key[0] == '0' && key[1] >= '0' && key[1] <= '9')
		key++;
	if (*key == '\0' || d->size >= MAX_ENTRIES)
		return (0);
	d->tab[d->size].key = key;
	d->tab[d->size].val = ft_trim(colon + 1);
	d->size++;
	return (1);
}

// Découpe le buffer en lignes : chaque '\n' devient un '\0',
// puis chaque ligne passe dans ft_add_line.
// Retourne 1 si tout le dico est valide, 0 sinon.
int	ft_dict_parse(char *buf, t_dict *d)
{
	char	*line;

	d->size = 0;
	while (*buf)
	{
		line = buf;
		while (*buf && *buf != '\n')
			buf++;
		if (*buf == '\n')
			*buf++ = '\0';
		if (!ft_add_line(line, d))
			return (0);
	}
	return (1);
}

// Cherche une clé dans le dico (recherche simple, entrée par entrée).
// Retourne la valeur ("forty") si trouvée, sinon 0.
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
