NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT = libft/libft.a

SRC = \
	main/main.c \
	main/exec.c \
	main/path.c \
	main/error.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(OBJS) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re