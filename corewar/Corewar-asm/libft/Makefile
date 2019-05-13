# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:34:40 by rbechir           #+#    #+#              #
#    Updated: 2018/06/18 20:21:40 by rbechir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
SRC			= ft_abs.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_strlen.c \
			  ft_nbrlen.c \
			  ft_putendl.c \
			  ft_putnbr.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_iswhitespace.c \
			  ft_isint.c \
			  ft_isupper.c \
			  ft_islower.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_skip_whitespace.c \
			  ft_atoi.c \
			  ft_strdup.c \
			  ft_strcpy.c \
			  ft_strcat.c \
			  ft_strcmp.c \
			  ft_strstr.c \
			  ft_strchr.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_strclr.c \
			  ft_strequ.c \
			  ft_strsub.c \
			  ft_strjoin.c \
			  ft_intjoin.c \
			  ft_strtrim.c \
			  ft_strsplit.c \
			  ft_intsplit.c \
			  ft_itoa.c \
			  ft_striter.c \
			  ft_strmap.c \
			  ft_printstrtab.c \
			  ft_free_tab.c \
			  ft_lstnew.c \
			  ft_lstdel.c \
			  ft_lstadd.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_insert_char.c \
			  ft_sqrt.c \
			  get_next_line.c \
			  ft_printf.c \
			  ft_check.c \
			  ft_conv_csp.c \
			  ft_conv_dioux.c \
			  ft_flags.c \
			  ft_modifiers.c \
			  ft_precision.c \
			  ft_process_flags.c \
			  ft_wchar.c
SRC_PATH	= src/
SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRCS:.c=.o)
INC			= libftprintf.h
INC_PATH	= includes/
INCS		= $(addprefix $(INC_PATH), $(INC))

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o:		%.c $(INCS)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all
