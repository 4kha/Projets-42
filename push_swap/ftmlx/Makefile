# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:26:38 by khtran            #+#    #+#              #
#    Updated: 2017/12/12 02:42:47 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftmlx.a

SOURCE =	mlx_color.c \
			mlx_line.c \
			mlx_pos_set.c \
			mlx_put_pixel.c \
			mlx_square.c

COMP =		 $(SOURCE:.c=.o)

FLAG =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(COMP)
	@ar rc $(NAME) $(COMP)
	@ranlib $(NAME)

src : $(SOURCE)
	@gcc $(FLAG) -c $(SOURCE)

clean:
	@rm -f $(COMP)

fclean:
	@rm -f $(COMP)
	@rm -f $(NAME)

re : fclean all
