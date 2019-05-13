/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.cycles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:36:05 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 13:10:31 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		delete_dead_processus(t_a *arena)
{
	int	i;
	int	j;

	i = 0;
	if (!arena->pc)
		return ;
	while (arena->pc[i])
	{
		if (!arena->pc[i]->live)
		{
			j = i;
			free(arena->pc[i]);
			if (!arena->visual && arena->verbose)
				ft_printf("Processus killed\n");
			while (arena->pc[++j])
				arena->pc[j - 1] = arena->pc[j];
			arena->pc[j - 1] = NULL;
			i--;
		}
		i++;
	}
}

static void		perform_check(t_a *arena)
{
	int	i;
	int	ctd;

	i = -1;
	ctd = arena->cycles_to_die;
	if (arena->verbose && !arena->visual)
		ft_printf("A check has started (cycles : %d).\n", arena->cycles);
	arena->cycles = 0;
	if (arena->lives >= NBR_LIVE)
	{
		arena->checks = 0;
		arena->cycles_to_die -= arena->cycles_delta;
	}
	arena->lives = 0;
	arena->checks = (arena->cycles_to_die == ctd) ? arena->checks + 1 : 0;
	if (arena->checks >= MAX_CHECKS)
	{
		arena->checks = 0;
		arena->cycles_to_die -= arena->cycles_delta;
	}
	delete_dead_processus(arena);
	while (++i < count_pc(arena))
		arena->pc[i]->live = 0;
}

static void		decrement_pc_lives(t_a *arena)
{
	int	i;

	i = 0;
	while (arena->pc[i])
	{
		arena->pc[i]->to_exec--;
		i++;
	}
}

void			cycles_handler(t_a *arena, int i)
{
	if (arena->pc)
		decrement_pc_lives(arena);
	arena->cycles++;
	arena->cycles_total++;
	if (arena->cycles >= arena->cycles_to_die)
		perform_check(arena);
	if (arena->cycles_total == arena->dump)
	{
		endwin();
		ft_printf("Memory dump after %d cycles asked by user.\n", arena->dump);
		display_arena(arena);
		error(arena, 0, NULL);
	}
	if (arena->verbose && !arena->visual)
		ft_printf("Cycle %d has started.\n", arena->cycles_total);
	if (arena->visual)
	{
		draw_memory(arena);
		display_info(arena);
		draw_champions(arena);
		draw_process(arena, i);
		draw_borders();
		refresh();
	}
}
