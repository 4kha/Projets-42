# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:27:45 by rbechir           #+#    #+#              #
#    Updated: 2018/01/08 03:07:35 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
SRC =		ft_math.c \
			ft_printf.c \
			ft_printf_last_flag.c \
			ft_printf_parsing.c \
			ft_printf_set.c \
			type/ft_printf_diff.c \
			type/ft_printf_nbrlen.c \
			type/ft_printf_putnbr.c \
			type/ft_printf_type_convert.c \
			type/ft_printf_type_hexa.c \
			type/ft_printf_type_int.c \
			type/ft_printf_type_long.c \
			type/ft_printf_type_none.c \
			type/ft_printf_type_octo.c \
			type/ft_printf_type_binary.c \
			type/ft_printf_type_ptr.c \
			type/ft_printf_type_str.c \
			type/ft_printf_type_unsigned.c \
			type/ft_printf_type_unsigned_base.c \
			type/ft_printf_type_wstr.c \
			type/ft_printf_type_char.c \
			type/ft_printf_type_wchar.c \
			ft_printf_error.c \
			ft_isdigit.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strsub.c

SRC3 =		ft_math.c \
			ft_printf.c \
			ft_printf_last_flag.c \
			ft_printf_parsing.c \
			ft_printf_set.c \
			ft_printf_diff.c \
			ft_printf_nbrlen.c \
			ft_printf_putnbr.c \
			ft_printf_type_convert.c \
			ft_printf_type_hexa.c \
			ft_printf_type_int.c \
			ft_printf_type_long.c \
			ft_printf_type_none.c \
			ft_printf_type_octo.c \
			ft_printf_type_binary.c \
			ft_printf_type_ptr.c \
			ft_printf_type_str.c \
			ft_printf_type_unsigned.c \
			ft_printf_type_unsigned_base.c \
			ft_printf_type_wstr.c \
			ft_printf_type_char.c \
			ft_printf_type_wchar.c \
			ft_printf_error.c \
			ft_isdigit.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strsub.c

SRCS =		$(addprefix srcs/,$(SRC))
OBJ =		$(SRC3:.c=.o)
CFLAGS =	-Wall -Wextra -Werror
CC =		@gcc
CC2 =		@ar rc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC2) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation completed"

$(OBJ) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -I includes/

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all
