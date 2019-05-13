# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:44:22 by khtran            #+#    #+#              #
#    Updated: 2017/11/06 21:13:19 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SOURCE =	display.c \
			toolbox.c

LIB		=	display.o \
			toolbox.o


FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : SRC
	gcc $(FLAG) -o $(NAME) $(LIB)

SRC :
	gcc $(FLAG) -c $(SOURCE)

clean :
	rm -f $(LIB)

fclean : clean
	rm -f $(NAME)

re : fclean all
