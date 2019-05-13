/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:07:07 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/25 23:06:20 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_a			*init_a(void)
{
	int	i;
	t_a	*arena;

	i = -1;
	if (!(arena = (t_a *)ft_memalloc(sizeof(t_a))))
		return (NULL);
	while (++i < MEM_SIZE)
		if (!(arena->mem[i] = (t_o *)ft_memalloc(sizeof(t_o))))
			error(arena, 0, "Error: cannot malloc arena memory");
	arena->cycles_to_die = CYCLES_TO_DIE;
	arena->cycles_delta = CYCLE_DELTA;
	return (arena);
}

static t_a	*set_processus(t_a *arena, int p)
{
	int	i;
	t_p	*processus;

	i = 0;
	processus = NULL;
	if (!p)
		error(arena, 0, "Error: no champions found");
	if (!(arena->pc = (t_p **)ft_memalloc(sizeof(t_p *) * (p + 1))))
		error(arena, 0, "Error: cannot malloc PC memory");
	while (i < p)
	{
		if (!(processus = (t_p *)ft_memalloc(sizeof(t_p))))
			error(arena, 0, "Error: cannot malloc PC memory");
		arena->pc[i] = processus;
		arena->pc[i]->mem = ((p - (i + 1)) * MEM_SIZE / p) % MEM_SIZE;
		arena->pc[i]->instruct = arena->mem[arena->pc[i]->mem]->octet;
		arena->pc[i]->to_exec = get_exec(arena->pc[i]->instruct) - 1;
		arena->pc[i]->reg[1] =
		~arena->champ[count_champions(arena) - 1 - i]->number;
		arena->pc[i]->owner = arena->champ[count_champions(arena) - 1 - i];
		i++;
	}
	return (arena);
}

t_a			*load_players(t_a *arena, int p)
{
	int i;
	int	j;
	int k;

	i = -1;
	j = 0;
	if (p == 0)
		error(arena, 1, "Error: the arena must contain 1 champion at least");
	while (arena->champ[++i])
	{
		k = -1;
		if (i != 0)
			while (j % MEM_SIZE < (i * MEM_SIZE / p))
				j++;
		while (++k < arena->champ[i]->size)
		{
			arena->mem[j % MEM_SIZE]->octet =
			((unsigned char *)arena->champ[i]->prog)[k];
			arena->mem[j % MEM_SIZE]->owner = arena->champ[i];
			j++;
		}
	}
	return (set_processus(arena, p));
}
