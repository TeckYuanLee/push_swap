NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -I.
ARFLAGS = rcs
SRC = main.c processes/process_ss.c processes/process_rr.c processes/process_rrr.c processes/process_papb.c quick_sort_helper.c printAB.c threerandnum.c checkerror.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME):	$(OBJ) 
		@$(MAKE) all -C ./libft
		@gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

clean:
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

fclean:	clean
			@$(MAKE) fclean -C ./libft
			@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
