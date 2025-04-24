NAME=minishell

CC=cc
LIBFT =  libft/libft.a
CFLAGS = -Wall -Wextra -Werror -lreadline

SRC=main.c mini_functions.c lexer.c

OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)
	
$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): 
	make -C libft all

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean:clean
	make -C libft fclean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re
