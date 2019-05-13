# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khtran <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 20:35:25 by khtran            #+#    #+#              #
#    Updated: 2019/01/31 18:14:01 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = wolf3d
SRC =	main.c \
		wf_map_check.c \
		wf_map_load.c \
		wf_read.c \
		wf_init.c \
		wf_sdl_error.c \
		wf_ray.c \
		wf_event.c \
		wf_textures.c \
		wf_ray_skybox.c
SRCS = $(addprefix srcs/,$(SRC))
OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
FLAG = -Werror -Wextra -Wall
INC = libft/libft.a

SDL_H = ./frameworks/SDL2.framework/Headers/
SDL_B = `sdl2-config --libs`

all: $(OBJ) $(NAME)

$(NAME): $(OBJ) $(INC)
	gcc -o $(NAME) -I $(SDL_H) $(OBJ) $(INC) $(SDL_B) -lsdl2

$(INC) :
	@make -C libft/

$(OBJ): $(SRCS)
	gcc -c $(SRCS) -I $(SDL_H)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ)
	@make -C libft/ clean

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean $(NAME)
