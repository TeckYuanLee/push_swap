NAME = push_swap
LIBFT = libft/libft.a
CFLAGS =  -Wall -Werror -Wextra -I.
ARFLAGS = rcs
SRC = push_swap.c processes.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME):	$(OBJ) 
		@$(MAKE) bonus -C ./libft
		@gcc $(CFLAGS) $(LIBFT) $(SRC) -o $(NAME)

clean:
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

fclean:	clean
			@$(MAKE) fclean -C ./libft
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
