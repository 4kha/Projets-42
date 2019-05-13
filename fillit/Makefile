# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:27:45 by rbechir           #+#    #+#              #
#    Updated: 2017/11/22 18:09:44 by rbechir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ft_check_block.c \
	  ft_check_format.c \
	  ft_convert.c \
	  ft_fillit.c \
	  ft_grow_all_shape.c \
	  ft_read.c \
	  ft_solve.c \
	  ft_insert_char.c \
	  ft_putstr.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c
SRCS = $(addprefix srcs/,$(SRC))
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = @gcc


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
