# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:26:38 by khtran            #+#    #+#              #
#    Updated: 2018/03/15 12:27:08 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = instruction.a

SOURCE =	push_swap_p.c \
			push_swap_r.c \
			push_swap_s.c \
			ft_lst.c \
			push_parser.c \
			push_error.c \
			ft_lim.c

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
