/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 18:44:02 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/19 22:14:19 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_visual(t_a *arena)
{
	initscr();
	start_color();
	init_pairs(arena);
	draw_memory(arena);
	display_info(arena);
	draw_champions(arena);
	draw_process(arena, 0);
	draw_borders();
	noecho();
	curs_set(0);
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	refresh();
}
