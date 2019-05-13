# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:44:22 by khtran            #+#    #+#              #
#    Updated: 2017/11/06 21:14:35 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE =	./srcs/ft_putchar.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strcmp.c \
			./srcs/ft_strlen.c \
			./srcs/ft_swap.c

LIB 	=	ft_putchar.o \
			ft_putstr.o \
			ft_strcmp.o \
			ft_strlen.o \
			ft_swap.o


FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : SRC
	ar rc $(NAME) $(LIB)

SRC :
	gcc $(FLAG) -c $(SOURCE)

clean :
	rm -f $(LIB)

fclean : clean
	rm -f $(NAME)

re : fclean all
