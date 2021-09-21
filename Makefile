NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -I.
ARFLAGS = rcs
SRC = trynewstuff.c process_ss.c process_rr.c process_rrr.c process_papb.c threerandnum.c comparealgo.c

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
