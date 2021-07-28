NAME		= libftprintf.a
LIBFT		= libft/libft.a
CFLAGS		= -Wall -Werror -Wextra -I.
SRC			= cvsn_spfr.c ft_printf.c handle_flags.c enter_flags.c utils.c\


OBJ			= $(SRC:c=o)

all:		$(NAME)

$(NAME):	$(OBJ)
				@$(MAKE) bonus -C ./libft
				@cp $(LIBFT) $(NAME)
				@ar rcs $(NAME) $(OBJ)

clean:
				@$(MAKE) clean -C ./libft
				@rm -f $(OBJ)

fclean:		clean
				@$(MAKE) fclean -C ./libft
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
