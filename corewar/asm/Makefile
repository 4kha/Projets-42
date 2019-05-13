# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbechir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:34:40 by rbechir           #+#    #+#              #
#    Updated: 2018/06/28 20:45:46 by rbechir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all clean fclean re

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= asm
SRC				= cw_parser.c \
				  cw_get_header.c \
				  cw_get_instructions.c \
				  cw_get_label.c \
				  cw_get_number.c \
				  cw_place_labels_size.c \
				  cw_args.c \
				  cw_instruction_ft.c \
				  cw_live.c \
				  cw_ld.c \
				  cw_st.c \
				  cw_add.c \
				  cw_sub.c \
				  cw_and.c \
				  cw_or.c \
				  cw_xor.c \
				  cw_zjmp.c \
				  cw_ldi.c \
				  cw_sti.c \
				  cw_fork.c \
				  cw_lld.c \
				  cw_lldi.c \
				  cw_lfork.c \
				  cw_aff.c \
				  cw_error.c \
				  cw_create_file.c
SRC_PATH		= src/
SRCS			= $(addprefix $(SRC_PATH), $(SRC))
OBJ				= $(SRCS:.c=.o)
INC				= op.h
INC_PATH		= includes/
INCS			= $(addprefix $(INC_PATH), $(INC))
LIB_PATH		= libft/
LIB_INC_PATH	= $(addprefix $(LIB_PATH), includes/)

all:			lib $(NAME)

$(NAME):		$(OBJ)
	@$(CC) -I $(INC_PATH) -I $(LIB_INC_PATH) -L $(LIB_PATH) -lftprintf \
		-o $(NAME) $(SRCS)

lib:
	@make -C $(LIB_PATH)

%.o:			%.c $(INCS) $(LIB_PATH)libftprintf.a
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH) -I $(LIB_INC_PATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)

fclean:			clean
	@rm -f $(NAME)
	@rm -f $(LIB_PATH)libftprintf.a

re:				fclean all
