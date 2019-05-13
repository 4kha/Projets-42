# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:27:45 by rbechir           #+#    #+#              #
#    Updated: 2018/05/04 18:27:54 by khtran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		checker

NAME2 =		push_swap

NAME3 =		visual

SRC_C =		./checker/checker.c \
			./checker/checker_visual.c

SRC_PS =	./push_swap/push_swap.c \
			./push_swap/push_swap_sort_1.c \
			./push_swap/push_swap_sort_1_setup.c \
			./push_swap/push_swap_sort_2.c \
			./push_swap/push_swap_sort_3.c \
			./push_swap/push_swap_sort_basic.c \
			./push_swap/push_swap_sort_command_opti.c \
			./push_swap/push_swap_sort_5.c

SRC_OPS =	push_swap.o \
			push_swap_sort_1.o \
			push_swap_sort_1_setup.o \
			push_swap_sort_2.o \
			push_swap_sort_3.o \
			push_swap_sort_5.o \
			push_swap_sort_basic.o \
			push_swap_sort_command_opti.o

SRC_OC =	checker.o \
			checker_visual.o

SRC_V =		./visual_check/visual.c \
			./visual_check/visual_event_1.c \
			./visual_check/visual_instruction.c \
			./visual_check/visual_set.c

SRC_OV =	visual.o \
			visual_event_1.o \
			visual_instruction.o \
			visual_set.o

SRCS_C =	$(addprefix srcs/,$(SRC_C))
SRCS_PS =	$(addprefix srcs/,$(SRC_PS))
SRCS_V =	$(addprefix srcs/,$(SRC_V))
CFLAGS =	-Wall -Wextra -Werror
CC =		@gcc
DCC =		-lmlx -framework OpenGL -framework AppKit
INC =		libft/libft.a \
			srcs/instruction/instruction.a \
			minilibx_macos/libmlx.a \
			ftmlx/ftmlx.a

all: check $(NAME) $(NAME2) $(NAME3)

$(NAME): $(SRC_OC) $(INC)
	$(CC) -o $(NAME) $(SRC_OC) $(INC)
	@echo "Checker Compilation completed"

$(NAME2): $(SRC_OPS) $(INC)
	$(CC) -o $(NAME2) $(SRC_OPS) $(INC)
	@echo "Push_Swap Compilation completed"

$(NAME3): $(SRC_OV) $(INC)
	$(CC) $(DCC) -o $(NAME3) $(SRC_OV) $(INC)
	@echo "Visual Compilation completed"

$(SRC_OPS) : $(SRCS_PS)
	$(CC) $(CFLAGS) -c $(SRCS_PS) -I includes/

$(SRC_OC) : $(SRCS_C)
	$(CC) $(CFLAGS) -c $(SRCS_C) -I includes/

$(SRC_OV) : $(SRCS_V)
	$(CC) $(CFLAGS) -c $(SRCS_V) -I includes/

$(INC) :
	@make -C libft/
	@make -C srcs/instruction/
	@make -C ftmlx/
	@make -C minilibx_macos/

check :
	@make -C libft/
	@make -C srcs/instruction/
	@make -C ftmlx/
	@make -C minilibx_macos/

clean:
	@rm -f $(SRC_OPS) $(SRC_OC) $(SRC_OV)
	@make -C libft/ clean
	@make -C srcs/instruction/ clean
	@make -C ftmlx/ clean
	@make -C minilibx_macos/ clean

fclean:
	@rm -f $(SRC_OPS) $(SRC_OC) $(SRC_OV)
	@rm -f $(NAME) $(NAME2) $(NAME3)
	@make -C libft/ fclean
	@make -C srcs/instruction/ fclean
	@make -C ftmlx/ fclean
	@make -C minilibx_macos/ clean

re: fclean all

.PHONY: all re clean fclean check
