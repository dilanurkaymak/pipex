NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c exec.c path.c error.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
