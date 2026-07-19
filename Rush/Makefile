NAME	= rush-02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c ft_utils.c ft_read_file.c ft_dict_line.c \
		  ft_dict_parse.c ft_say_utils.c ft_say.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
