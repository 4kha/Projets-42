# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 02:34:37 by dlaurent          #+#    #+#              #
#    Updated: 2018/06/29 02:46:30 by dlaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 		all vm asm clean fclean re

all: asm vm

vm:
	@make -C vm/

asm:
	@make -C asm/

clean:
	@make clean -C asm/
	@make clean -C vm/

fclean:
	@make fclean -C asm/
	@make fclean -C vm/

re:
	@make re -C asm/
	@make re -C vm/
