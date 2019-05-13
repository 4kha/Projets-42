/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:02:25 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/22 16:06:25 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_champion(t_c *champion)
{
	if (!champion)
		return ;
	if (champion->prog)
		free(champion->prog);
	free(champion);
}

static void	free_arena_mem(t_a *arena)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (arena->mem[i])
			free(arena->mem[i]);
		i++;
	}
}

static void	free_arena_pc(t_a *arena)
{
	int	i;

	i = 0;
	if (!arena->pc)
		return ;
	while (arena->pc[i])
	{
		free(arena->pc[i]);
		i++;
	}
	free(arena->pc);
}

void		free_arena(t_a *arena)
{
	int	i;

	i = 0;
	if (!arena)
		return ;
	if (arena->champ)
	{
		while (arena->champ[i])
			free_champion(arena->champ[i++]);
		free(arena->champ);
	}
	free_arena_pc(arena);
	free_arena_mem(arena);
	free(arena);
}
