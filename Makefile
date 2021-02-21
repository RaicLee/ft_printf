# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 12:05:05 by jealee            #+#    #+#              #
#    Updated: 2021/02/21 20:58:38 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ft_printf
NAME		= libftprintf.a
#libft
LIBFT		= libft
LIBFTL	    = libft.a

#ft_printf relevant sources
SRCS		= ft_printf.c \
			  ft_utils.c \
			  ft_print_char.c
OBJS		= $(SRCS:.c=.o)

#ft_printf header dir
INCS		= .

#remove
RM			= rm -rf

#compile
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -c
#archive
AR			= ar
ARFLAGS     = crs

%.o :%.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFTL) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re libft
