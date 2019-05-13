/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:40:21 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 13:16:11 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_a	*arena;

	arena = NULL;
	check_constants();
	if (ac == 1)
		usage();
	if (!(arena = parse_input(NULL, ++av)))
		error(NULL, 0, "Error: arena is unset after parse");
	if (arena->visual)
		init_visual(arena);
	if (arena->audio)
		system("say Game will start in 3, 2, 1 !");
	if (arena->verbose && !arena->visual)
		ft_printf("Game will start in 3, 2, 1 !\n");
	play(arena);
	if (arena->visual)
	{
		while (getch() != 27)
		{
		}
		endwin();
	}
	free_arena(arena);
	return (0);
}
