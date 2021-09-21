# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telee <telee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 14:50:07 by telee             #+#    #+#              #
#    Updated: 2021/08/01 23:26:26 by telee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
headers		= libft.h
CFLAGS		= -Wall -Werror -Wextra -I.
SRC			= ft_atol.c ft_calloc.c ft_putchar.c ft_putstr.c ft_intlen.c

OBJ			= $(SRC:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
				@ar rcs $(NAME) $(OBJ) libft.h

$(OBJ): 	$(headers)

clean:
				@rm -f $(OBJ)

fclean: 	clean
				@rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus
