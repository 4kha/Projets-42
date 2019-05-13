# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 22:00:53 by dlaurent          #+#    #+#              #
#    Updated: 2018/06/29 02:44:34 by dlaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 		all clean fclean re

NAME_CO = 		corewar

CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR = 		./src/
SRC_CO =		arena/arena.functions.c\
				arena/arena.init.c\
				champion/champion.init.c\
				common/common.check.c\
				common/common.display.c\
				common/common.error.c\
				common/common.memory.c\
				common/common.usage.c\
				corewar.c\
				instructions/instruct.00_nothing.c\
				instructions/instruct.01_live.c\
				instructions/instruct.02_ld.c\
				instructions/instruct.03_st.c\
				instructions/instruct.04_add.c\
				instructions/instruct.05_sub.c\
				instructions/instruct.06_and.c\
				instructions/instruct.07_or.c\
				instructions/instruct.08_xor.c\
				instructions/instruct.09_zjmp.c\
				instructions/instruct.0a_ldi.c\
				instructions/instruct.0b_sti.c\
				instructions/instruct.0c_fork.c\
				instructions/instruct.0d_lld.c\
				instructions/instruct.0e_lldi.c\
				instructions/instruct.0f_lfork.c\
				instructions/instruct.10_aff.c\
				instructions/instruct.ocp.c\
				instructions/instruct.values.c\
				instructions/instruct.init.c\
				instructions/instruct.is_.c\
				instructions/instruct.moves.c\
				parser/parser.c\
				parser/parser.champions.c\
				parser/parser.options.c\
				parser/parser.read_file.c\
				solver/solver.c\
				solver/solver.cycles.c\
				solver/solver.instructs.c\
				visual/visual.colors.c\
				visual/visual.draws.c\
				visual/visual.functions.c\
				visual/visual.init.c

SRCS_CO = 		$(addprefix $(SRC_DIR), $(SRC_CO))

OBJ_DIR = 		./obj/
OBJ_CO = 		$(SRC_CO:.c=.o)
OBJS_CO = 		$(addprefix $(OBJ_DIR), $(OBJ_CO))

INC_DIR = 		./include/
INC = 			corewar.h
INCS = 			$(addprefix $(INC_DIR), $(INC))

LIB_DIR = 		./lib/

all: 			corewar

corewar: 		$(OBJ_DIR) $(OBJS_CO)
				@make -C libft/
				@$(CC) $(CFLAGS) -o $(NAME_CO) $(OBJS_CO) -L libft/ -lft -lncurses

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c $(INCS)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/arena
				@mkdir -p $(OBJ_DIR)/champion
				@mkdir -p $(OBJ_DIR)/common
				@mkdir -p $(OBJ_DIR)/instructions
				@mkdir -p $(OBJ_DIR)/parser
				@mkdir -p $(OBJ_DIR)/solver
				@mkdir -p $(OBJ_DIR)/visual

clean:
				@make clean -C libft/
				@rm -f $(OBJS)
				@rm -rf $(OBJ_DIR)

fclean: 		clean
				@make fclean -C libft/
				@rm -f $(NAME_CO)

re: 			fclean all
