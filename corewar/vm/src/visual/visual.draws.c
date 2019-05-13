/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.draws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:11:16 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 17:17:14 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_info(t_a *a)
{
	attron(COLOR_PAIR(1));
	mvprintw(3, 229, "GENERAL");
	mvprintw(5, 218, "Champions      :\t%8d", count_champions(a));
	mvprintw(7, 218, "Processus      :\t%8d", count_pc(a));
	mvprintw(9, 218, "Dump           :\t%8d", a->dump);
	if (a->last_alive)
		mvprintw(11, 218, "Last alive     : %-15.15s", a->last_alive->name);
	else
		mvprintw(11, 218, "Last alive     :\t%8s", "/");
	mvprintw(3, 279, "CYCLES");
	mvprintw(5, 268, "Cycles         :\t%8d", a->cycles);
	mvprintw(7, 268, "Cycles (total) :\t%8d", a->cycles_total);
	mvprintw(9, 268, "Cycles to die  :\t%8d", a->cycles_to_die);
	mvprintw(11, 268, "Cycles delta   :\t%8d", CYCLE_DELTA);
	mvprintw(3, 328, "LIVES");
	mvprintw(5, 318, "Lives          :\t%8d", a->lives);
	mvprintw(7, 318, "Lives (total)  :\t%8d", a->lives_total);
	mvprintw(9, 318, "Nbr live       :\t%8d", NBR_LIVE);
	mvprintw(11, 318, "Checks         :\t %2d / %2d", a->checks, MAX_CHECKS);
	attroff(COLOR_PAIR(1));
}

void	draw_memory(t_a *arena)
{
	int	i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printw("\n");
		select_color(arena, i);
		mvprintw(2 + i / 64, 3 + (i % 64) * 3,
		"%02x", 0xFF & (arena->mem[i]->octet));
		unselect_color(arena, i);
		printw(" ");
	}
}

void	draw_borders(void)
{
	attron(COLOR_PAIR(99));
	mvhline(1, 213, '*', 39);
	mvhline(13, 213, '*', 39);
	mvvline(1, 213, '*', 12);
	mvvline(1, 251, '*', 12);
	mvhline(1, 263, '*', 39);
	mvhline(13, 263, '*', 39);
	mvvline(1, 263, '*', 12);
	mvvline(1, 301, '*', 12);
	mvhline(1, 313, '*', 39);
	mvhline(13, 313, '*', 39);
	mvvline(1, 313, '*', 12);
	mvvline(1, 351, '*', 12);
	mvhline(0, 0, '*', 196);
	mvhline(67, 0, '*', 197);
	mvvline(0, 0, '*', 67);
	mvvline(0, 196, '*', 68);
	attroff(COLOR_PAIR(99));
}

void	draw_champions(t_a *a)
{
	int	i;
	int j;

	i = -1;
	while (++i < 4 && a->champ[i])
	{
		attron(COLOR_PAIR(i * 2 + 3));
		j = 218 + (i % 2) * 50;
		mvprintw(20 + 15 * (i / 2), j + 10, "CHAMPION %d", i + 1);
		mvprintw(22 + 15 * (i / 2), j, "%-30.30s", a->champ[i]->name);
		mvprintw(24 + 15 * (i / 2), j, "Number%9s:\t%8d", "",
		a->champ[i]->number);
		mvprintw(26 + 15 * (i / 2), j, "Color%10s:\t%8d", "",
		a->champ[i]->color);
		mvprintw(28 + 15 * (i / 2), j, "Lives%10s\t%8d", "",
		a->champ[i]->lives);
		mvprintw(30 + 15 * (i / 2), j, "Size%10s:\t%8d", "", a->champ[i]->size);
		attroff(COLOR_PAIR(i * 2 + 3));
	}
	while (i < 4)
	{
		mvprintw(20 + 15 * (i / 2), 228 + (i % 2) * 50, "CHAMPION %d", i + 1);
		mvprintw(26 + 15 * (i / 2), 231 + (i % 2) * 50, "%-18.18s", "N/A");
		i++;
	}
}

int		draw_process(t_a *a, int i)
{
	int	j;
	int k;

	if (!a->pc)
		return (0);
	j = count_pc(a);
	if (j == 0)
		return (0);
	k = i;
	if (i < 0)
		k = j - 1;
	else if (i >= j)
		k = 0;
	i = j - k - 1;
	mvprintw(20, 327, "PROCESSUS %d/%d  ", k + 1, j);
	mvprintw(22, 318, "Instruction    :\t%#8.2x", a->mem[a->pc[i]->mem]->octet);
	mvprintw(24, 318, "Position       :\t%8d", a->pc[i]->mem);
	mvprintw(26, 318, "Cycle before ex:\t%8d",
	ft_int_max(a->pc[i]->to_exec + 1, 0));
	mvprintw(28, 318, "Lives generated:\t%8d", a->pc[i]->live);
	mvprintw(30, 318, "Carry          :\t%8d", a->pc[i]->carry);
	j = 0;
	while (++j <= REG_NUMBER)
		mvprintw(31 + 2 * j, 318, "Register[%d]  :\t%08x", j, a->pc[i]->reg[j]);
	return (k);
}
