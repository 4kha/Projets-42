/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:41:24 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/18 14:08:11 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_pairs(t_a *arena)
{
	int	i;
	int	j;

	i = 3;
	j = 0;
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	if (!arena->champ)
		return ;
	while (arena->champ[j])
	{
		init_pair(i, arena->champ[j]->color, COLOR_BLACK);
		init_pair(i + 1, COLOR_BLACK, arena->champ[j]->color);
		i += 2;
		j++;
	}
	init_pair(99, COLOR_WHITE, COLOR_WHITE);
}

void	select_color(t_a *arena, int i)
{
	int j;

	j = 0;
	if (!arena->mem[i]->owner && !is_pc(arena, i))
		attron(COLOR_PAIR(1));
	else if (!arena->mem[i]->owner && is_pc(arena, i))
		attron(COLOR_PAIR(2));
	else
	{
		while (arena->champ[j] != arena->mem[i]->owner && arena->champ[j])
			j++;
		if (!is_pc(arena, i))
			attron(COLOR_PAIR(j * 2 + 3));
		else
			attron(COLOR_PAIR(j * 2 + 4));
	}
}

void	unselect_color(t_a *arena, int i)
{
	int j;

	j = 0;
	if (!arena->mem[i]->owner && !is_pc(arena, i))
		attroff(COLOR_PAIR(1));
	else if (!arena->mem[i]->owner && is_pc(arena, i))
		attroff(COLOR_PAIR(2));
	else
	{
		while (arena->champ[j] != arena->mem[i]->owner && arena->champ[j])
			j++;
		if (!is_pc(arena, i))
			attroff(COLOR_PAIR(j * 2 + 3));
		else
			attroff(COLOR_PAIR(j * 2 + 4));
	}
}
