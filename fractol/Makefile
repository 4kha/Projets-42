# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:27:45 by rbechir           #+#    #+#              #
#    Updated: 2018/07/04 01:39:16 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol
SRC =		fractol.c \
			fractol_boudha.c \
			fractol_click.c \
			fractol_click_2.c \
			fractol_color.c \
			fractol_hold.c \
			fractol_interface.c \
			fractol_interface_color.c \
			fractol_julia.c \
			fractol_julia_2.c \
			fractol_key.c \
			fractol_mandelbrot.c \
			fractol_mandelbrot_2.c \
			fractol_release.c \
			fractol_set.c \
			fractol_tapis.c \
			fractol_trigger.c \
			ft_itoa.c \
			ft_putstr.c \
			ft_strcmp.c

INC =		minilibx_macos/libmlx.a \
			ftmlx/ftmlx.a
SRCS =		$(addprefix srcs/,$(SRC))
OBJ =		$(SRC:.c=.o)
CFLAGS =	-Wall -Wextra -Werror
DFLAGS =	-lmlx -framework OpenGL -framework AppKit
CC =		@gcc


all: check $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) -o $(NAME) $(DFLAGS) $(OBJ) -I $(INC)
	@echo "\x1b[32;01mCompilation completed"

$(OBJ) : $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS) -I includes/

$(INC) :
	@make -C ftmlx/
	@make -C minilibx_macos/

check :
	@make -C ftmlx/
	@make -C minilibx_macos/

clean:
	@rm -f $(OBJ)
	@make -C ftmlx/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ftmlx/ fclean
	@make -C minilibx_macos/ clean

re: fclean all
