/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:54:38 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 15:38:41 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_prepare(t_list *list, int ant, int way)
{
	int		diff;
	t_list	*last;
	t_list	*first;
	t_list	*tmp;

	first = list;
	tmp = list;
	last = ft_lsttail(list);
	while (way != 0)
	{
		diff = ft_intdif(last->content_size, first->content_size);
		diff = ant - (diff);
		diff = diff / way;
		ant = ant - diff;
		last->content_size = diff;
		last = ft_lstbef(list, last);
		way = way - 1;
	}
}

void	lem_in_ant_move(t_list **ant, t_env *env)
{
	t_list	*tmp;
	t_room	**room;
	t_list	*next;

	tmp = *ant;
	while (tmp != NULL)
	{
		next = lem_in_list_in_list(tmp);
		room = next->content;
		lem_in_print_ant((*room)->name, tmp->content_size, tmp);
		if (*room == env->m_end)
		{
			next = tmp->next;
			ft_lstdelone(ant, tmp);
			tmp = next;
		}
		else
		{
			next = next->next;
			ft_memcpy(tmp->content, &next, sizeof(tmp->content) + 1);
			tmp = tmp->next;
		}
	}
}

t_list	*lem_in_ant_vague(int *send_ant, t_list **thing)
{
	t_list	*tmp;
	t_list	*list;
	t_list	*group;

	tmp = *thing;
	group = NULL;
	while (tmp != NULL && tmp->content_size != 0)
	{
		if (tmp->content_size != 0)
		{
			list = ft_lstnew(tmp->content, sizeof(tmp->content));
			list->content_size = *send_ant;
			tmp->content_size--;
			ft_lstlast(&group, list);
			(*send_ant)++;
		}
		tmp = tmp->next;
	}
	return (group);
}

void	lem_in_print(t_list *way, t_env *env)
{
	t_list	*tmp;
	t_list	*ant;
	t_list	*group;
	int		send_ant;

	lem_in_prepare(way, env->nbr_ant, ft_lstlen(way));
	tmp = way;
	ant = NULL;
	send_ant = 1;
	while (send_ant <= env->nbr_ant || ant != NULL)
	{
		tmp = way;
		group = lem_in_ant_vague(&send_ant, &tmp);
		ft_lstlast(&group, ant);
		ant = group;
		group = NULL;
		lem_in_ant_move(&ant, env);
		ft_putstr("\n");
	}
}

void	lem_in_way_best(t_list **all_comb, t_env *env)
{
	int		way;
	t_list	*tmp;
	t_list	*proceed;

	way = 0;
	tmp = *all_comb;
	while (tmp != NULL)
	{
		way++;
		proceed = lem_in_list_in_list(tmp);
		if (proceed->content_size == 1)
		{
			lem_in_print_one_way(env);
			return ;
		}
		lem_in_prepare(proceed, env->nbr_ant, way);
		tmp->content_size = ft_lstmax(proceed)
			+ ft_lstlen(lem_in_list_in_list(proceed));
		tmp = tmp->next;
	}
	proceed = ft_lstmin_chain(*all_comb);
	proceed = lem_in_list_in_list(proceed);
	ft_putendl(env->input);
	lem_in_print(proceed, env);
}
