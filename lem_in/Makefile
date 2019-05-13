# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:27:45 by rbechir           #+#    #+#              #
#    Updated: 2018/06/22 15:12:25 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

SRC =		./lem_in.c \
			./lem_in_ft.c \
			./lem_in_check.c \
			./lem_in_roomft.c \
			./lem_in_build.c \
			./lem_in_find.c \
			./lem_in_parser.c \
			./lem_in_solve.c \
			./lem_in_printsol.c \
			./lem_in_combft.c \
			./lem_in_comb.c \
			./lem_in_way.c \
			./lem_in_free.c \
			./lem_in_lstft.c \
			./lem_in_info.c

SRCS =		$(addprefix srcs/,$(SRC))

SRC_O =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra -Werror

CC =		@gcc

INC =		libft/libft.a

all: check $(NAME)

$(NAME): $(SRC_O) $(INC)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC_O) $(INC)
	@echo "Lem_in Compilation completed"

$(SRC_O) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS) -I includes/
	@echo "Source made"

$(INC) :
	@make -C libft/

check :
	@make -C libft/

clean:
	@rm -f $(SRC_O)
	@make -C libft/ clean

fclean:
	@rm -f $(SRC_O)
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean check
