PUSH_SWAP = push_swap
CHECKER = checker
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -I.
ARFLAGS = rcs

SRC = ps_program/*.c printAB.c processes/*.c\

SRC1 = ps_checker/checker.c ps_program/checkerror.c processes/*.c\

OBJ = $(SRC:c=o)
OBJ1 = $(SRC1:c=o)

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):	$(OBJ) 
		@$(MAKE) all -C ./libft
		@gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(PUSH_SWAP)
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

$(CHECKER):		$(OBJ)
		@gcc $(CFLAGS) $(SRC1) $(LIBFT) -o $(CHECKER)
		@rm -f $(OBJ1)

clean:
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

fclean:	clean
			@$(MAKE) fclean -C ./libft
			@rm -f $(PUSH_SWAP)
			@rm -f $(CHECKER)

re:		fclean all

.PHONY: all clean fclean re bonus
