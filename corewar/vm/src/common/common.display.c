/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:19:36 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 22:04:03 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		display_arena(t_a *arena)
{
	int	i;

	i = -1;
	if (!arena)
		ft_printf("\tArena is unset.\n");
	else
	{
		while (++i < MEM_SIZE)
		{
			if (i % DUMP_SIZE == 0 && i == 0)
				ft_printf("0x%04x : ", 0xFFFF & i);
			else if (i % DUMP_SIZE == 0)
				ft_printf("\n0x%04x : ", 0xFFFF & i);
			ft_printf("%s%02x%s ", get_color(arena->mem[i]->owner, 0),
			0xFF & (arena->mem[i]->octet), get_color(arena->mem[i]->owner, 1));
		}
		ft_putendl("");
	}
}
