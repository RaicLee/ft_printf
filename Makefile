# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealee <jealee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 12:05:05 by jealee            #+#    #+#              #
#    Updated: 2021/03/05 19:30:49 by jealee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFTL	    = libft.a

#ft_printf relevant sources
SRCS		= ft_printf.c \
			  ft_utils.c \
			  ft_print_c.c \
			  ft_print_s.c \
			  ft_print_number.c
OBJS		= $(SRCS:.c=.o)

INCS		= .
RM			= rm -rf

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -c
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
