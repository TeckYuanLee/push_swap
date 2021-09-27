PUSH_SWAP = push_swap
CHECKER = checker
LIBFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -I.
ARFLAGS = rcs

PROCESSES = processes/process_papb.c\
			processes/process_rr.c\
			processes/process_rrr.c\
			processes/process_ss.c\

SRC = ps_program/checkerror.c ps_program/main.c ps_program/quick_sort_helper.c ps_program/threerandnum.c printAB.c\

SRC1 = ps_checker/checker.c ps_program/checkerror.c\

OBJ = $(SRC:c=o)
OBJ1 = $(SRC1:c=o)

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):	$(OBJ) 
		@$(MAKE) all -C ./libft
		@gcc $(CFLAGS) $(SRC) $(PROCESSES) $(LIBFT) -o $(PUSH_SWAP)
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)

$(CHECKER):		$(OBJ)
		@gcc $(CFLAGS) $(SRC1) $(PROCESSES) $(LIBFT) -o $(CHECKER)
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
