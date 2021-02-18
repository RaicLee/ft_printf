# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 12:05:05 by jealee            #+#    #+#              #
#    Updated: 2021/02/18 13:37:50 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
INC_LINK = -I./includes
LIBFT = -L./libft -lft

all : $(NAME)

$(NAME) : $(OBJ) libft
	cp Libft/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)

# libft compile
libft :
	@$(MAKE) -C ./libft all

clean :
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJ)
fclean : clean
	@$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re : fclean all

# to execute with virtual command
.PHONY: all clean fclean re libft
