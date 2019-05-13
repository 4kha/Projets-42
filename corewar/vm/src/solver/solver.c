/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:22:54 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 22:03:16 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				end_of_game(t_a *a)
{
	char	*res;

	res = NULL;
	if (a->last_alive)
	{
		if (!(res = ft_strjoins("say Player ", (char *)a->last_alive->name)))
			error(a, 0, "Cannot display result (1)");
		if (!(res = ft_strjoinf(res, " has won the game.", 1)))
			error(a, 0, "Cannot display result (2)");
		if (a->audio)
			system(res);
		a->visual ? mvprintw(55, 238, "Player %d (%s) has won the game !",
		a->last_alive->number, a->last_alive->name) :
		ft_printf("%sPlayer %d (%s) has won the game !\n",
		get_color(a->last_alive, 0), a->last_alive->number, a->last_alive->name,
		get_color(a->last_alive, 1));
		ft_strdel(&res);
	}
	else
	{
		if (a->audio)
			system("say Only losers today");
		a->visual ? mvprintw(55, 238, "Only losers today") :
		ft_printf("Only losers today\n");
	}
}

static int				is_end_of_game(t_a *a)
{
	if (!a->pc || a->cycles_to_die <= 0 || !a->pc[0])
		return (1);
	return (0);
}

static void				non_visual_play(t_a *a, int j)
{
	int	i;

	i = count_pc(a) - 1;
	while (i >= 0 && a->pc[i])
	{
		if (a->pc[i]->need_init)
			init_instruct(a, a->pc[i]);
		if (a->pc[i]->to_exec <= 0)
			exec_instruct(a, a->pc[i]);
		i--;
	}
	cycles_handler(a, j);
}

static void				visual_play(t_a *a, int c, int i)
{
	int		pause;
	int		go_next_only;
	int		key;

	pause = (c == 'w') ? 1 : 0;
	go_next_only = (c == 'w') ? 1 : 0;
	while (1)
	{
		if (kbhit() && (key = getch()))
		{
			if (key == ' ')
				pause = (pause) ? 0 : 1;
			else if (key == 'w' && pause)
				go_next_only = 1;
			else if (key == 'a')
				i = draw_process(a, --i);
			else if (key == 'd')
				i = draw_process(a, ++i);
		}
		if (go_next_only || !pause)
			non_visual_play(a, i);
		go_next_only = 0;
		if (is_end_of_game(a))
			return ;
	}
}

void					play(t_a *a)
{
	int		i;
	int		c;

	i = 0;
	if (a->visual)
		while ((c = getch()) != ' ' && c != 'w')
		{
			if (c == 'a')
				i = draw_process(a, --i);
			else if (c == 'd')
				i = draw_process(a, ++i);
		}
	while (!is_end_of_game(a))
	{
		if (a->visual)
			visual_play(a, c, i);
		else
			non_visual_play(a, i);
	}
	return (end_of_game(a));
}
