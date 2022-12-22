SRC = main.c utils1.c utils2.c utils3.c print_stack.c manage_input.c small_stack.c

OBJ = $(SRC:.c=.o)

PUSHSWAP = push_swap

CFLAGS = -Werror -Wall -Wextra

all: $(PUSHSWAP)

$(PUSHSWAP): $(SRC)
	make bonus -C libft
	gcc $(CFLAGS) -o $(PUSHSWAP) libft/libft.a $^

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(PUSHSWAP)

re: fclean all
