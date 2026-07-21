# Nom de l'exécutable, compilateur, et options de compilation
# (-Wall -Wextra = tous les warnings, -Werror = warning -> erreur)
NAME	= rush-02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Les fichiers sources, et la même liste en .o (fichiers objets)
SRCS	= main.c ft_utils.c ft_dict.c ft_say.c
OBJS	= $(SRCS:.c=.o)

# Règle par défaut quand on tape "make" : construire l'exécutable
all: $(NAME)

# L'exécutable a besoin de tous les .o, qu'on relie (link) ensemble
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Comment fabriquer un .o depuis son .c ($< = source, $@ = cible).
# Dépend du header : si rush02.h change, tout recompile.
%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

# clean = supprime les .o ; fclean = clean + l'exécutable ;
# re = tout nettoyer puis tout reconstruire
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Dit à make que ces noms sont des commandes, pas des fichiers
.PHONY: all clean fclean re
