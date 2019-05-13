/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:00:38 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 17:06:37 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_instruct(t_a *arena, t_p *processus)
{
	if (!arena || !processus)
		return ;
	processus->need_init = 0;
	processus->instruct = arena->mem[processus->mem % MEM_SIZE]->octet;
	processus->to_exec = get_exec(processus->instruct) - 1;
}

int			get_exec(unsigned char mem)
{
	if (mem == 0x01 || mem == 0x04 || mem == 0x05 || mem == 0x0d)
		return (10);
	else if (mem == 0x02 || mem == 0x03)
		return (5);
	else if (mem == 0x06 || mem == 0x07 || mem == 0x08)
		return (6);
	else if (mem == 0x09)
		return (20);
	else if (mem == 0x0a || mem == 0x0b)
		return (25);
	else if (mem == 0x0c)
		return (800);
	else if (mem == 0x0e)
		return (50);
	else if (mem == 0x0f)
		return (1000);
	else if (mem == 0x10)
		return (2);
	else
		return (0);
}
