/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:05:55 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 10:16:07 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_print_ant(char *name, int ant, t_list *tmp)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(name);
	if (tmp->next != NULL)
		ft_putstr(" ");
}

void	lem_in_all_comb(t_list *all_comb)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_room	**room;

	while (all_comb != NULL)
	{
		tmp1 = all_comb;
		ft_putstr("\nSize ");
		ft_putnbr(tmp1->content_size);
		ft_putstr(" : ");
		tmp2 = lem_in_list_in_list(tmp1);
		while (tmp2 != NULL)
		{
			room = tmp2->content;
			ft_putstr((*room)->name);
			tmp2 = tmp2->next;
			if (tmp2 != NULL)
				ft_putstr("->");
		}
		all_comb = all_comb->next;
	}
}

void	lem_in_print_one_way(t_env *env)
{
	int		ant;
	char	*name;

	ant = 1;
	ft_putendl(env->input);
	name = (*env).m_end->name;
	while (ant <= (*env).nbr_ant)
	{
		ft_putstr("L");
		ft_putnbr(ant);
		ft_putstr("-");
		ft_putstr(name);
		if (ant != (*env).nbr_ant)
			ft_putstr(" ");
		ant++;
	}
	ft_putstr("\n");
}

void	lem_in_stats(t_env *env, t_list *way, int index)
{
	t_room	*room;

	room = ((*env).room);
	while (room != NULL)
	{
		room = room->next;
		index++;
	}
	ft_putstr("Number of room : ");
	ft_putnbr(index);
	ft_putstr("\nPath found : ");
	ft_putnbr(ft_lstlen(way));
	ft_putstr(" / ");
	if ((*env).max_sol <= 0)
		ft_putstr("NO_LIM");
	else
		ft_putnbr((*env).max_sol);
	ft_putstr("\nNumber of ants : ");
	ft_putnbr((*env).nbr_ant);
	ft_putstr("\nObjective : ");
	ft_putstr((*env).m_start->name);
	ft_putstr(" -> ");
	ft_putendl((*env).m_end->name);
}

void	lem_in_info(t_env *env, t_list *way)
{
	if ((*env).b_stats != 0)
	{
		ft_putstr("\n");
		lem_in_stats(env, way, 0);
		ft_putstr("\n");
	}
	if ((*env).b_room == 1)
	{
		lem_in_all_room((*env).room);
	}
	if ((*env).b_way == 1)
	{
		lem_in_all_comb(way);
		ft_putstr("\n");
	}
}
