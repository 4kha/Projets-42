/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:01:44 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/24 16:47:48 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error(t_a *arena, int display_usage, char *msg)
{
	endwin();
	if (arena)
		free_arena(arena);
	if (msg)
		ft_putendl_fd(msg, 2);
	if (display_usage)
		usage();
	exit(EXIT_FAILURE);
}

void	error_champion(t_a *arena, t_c *champion, int display_usage, char *msg)
{
	endwin();
	if (arena)
		free_arena(arena);
	if (champion)
		free_champion(champion);
	if (msg)
		ft_putendl_fd(msg, 2);
	if (display_usage)
		usage();
	exit(EXIT_FAILURE);
}

void	error_ocp(t_a *arena, char *ocp, int display_usage, char *msg)
{
	endwin();
	if (arena)
		free_arena(arena);
	if (ocp)
		ft_strdel(&ocp);
	if (msg)
		ft_putendl_fd(msg, 2);
	if (display_usage)
		usage();
	exit(EXIT_FAILURE);
}
