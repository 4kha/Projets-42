# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:26:38 by khtran            #+#    #+#              #
#    Updated: 2018/05/15 08:37:11 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE =	ft_atoi.c ft_error.c ft_fd_close.c ft_fd_open.c \
					ft_hexlet.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa_base.c \
					ft_itoa.c ft_lstadd.c ft_lstdelone.c ft_lstdup.c \
					ft_lstfree.c ft_lstiter.c ft_lstlast.c ft_lstlen.c \
					ft_lstmap.c ft_lstnew.c ft_lsttail.c ft_nbrlen_base.c \
					ft_nbrlen.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
					ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
					ft_putstr.c ft_puttab.c ft_read.c ft_strcat.c ft_strchr.c \
					ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
					ft_strequ.c ft_strjoin.c ft_strlen.c ft_tolower.c ft_toupper.c \
					get_next_line.c ft_memcpy.c ft_strncpy.c ft_strndup.c

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
