/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:23:28 by khtran            #+#    #+#             */
/*   Updated: 2018/05/19 03:47:48 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_add(t_list **sol, t_list **way)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp2 = ft_lstdup(*sol);
	tmp1 = ft_lstnew(&tmp2, sizeof(t_list*));
	ft_lstlast(way, tmp1);
	tmp1->content_size = ft_lstlen(tmp2);
}

int		lem_in_recursive(t_env *env, t_list **sol, t_list **way, t_room *curr)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_room	**tmp3;

	tmp1 = curr->chemin;
	while (tmp1 != NULL)
	{
		tmp3 = tmp1->content;
		if (*tmp3 == (*env).m_end)
		{
			lem_in_add(sol, way);
			return (1);
		}
		if ((*tmp3)->status == 0)
		{
			(*tmp3)->status = 1;
			tmp2 = ft_lstnew(&(*tmp3), sizeof(t_room*));
			ft_lstlast(sol, tmp2);
			lem_in_recursive(env, sol, way, *tmp3);
			ft_lstdelone(sol, tmp2);
			(*tmp3)->status = 0;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int		lem_in_room_len(t_room *room)
{
	int		count;

	count = 0;
	while (room != NULL)
	{
		count++;
		room = room->next;
	}
	return (count);
}

int		lem_in_recursive_set(t_env *env)
{
	t_list	*solution;
	t_list	*way;
	t_room	*tmp;
	t_list	*truc;

	solution = NULL;
	way = NULL;
	tmp = (*env).m_start;
//	ft_putstr(tmp->name);
//	test_putpath(tmp);
	tmp->status = 1;
//	truc = ft_lstnew(&tmp, sizeof(t_room*));
//	ft_lstlast(&solution, truc);
	lem_in_recursive(env, &solution, &way, tmp);
//	lem_in_printway(way);
	if (ft_lstlen(way) != 0)
		lem_in_solution_process(&way, lem_in_room_len((*env).room), env);
	lem_in_freeway(way);//Test de tout
	lem_in_freeroom((*env).room);
	if (ft_lstlen(way) == 0)
		ft_putstr("ERROR\n");
	return (0);
}

void	lem_in_solve(t_env *env)
{
	t_list	*sol;

	if ((*env).m_start == NULL || (*env).m_end == NULL
			|| (*env).room == NULL)
		ft_error("ERROR\n");
	if ((*env).m_start == (*env).m_end)
		exit(0);
	test_all_room((*env).room);
	if (lem_in_recursive_set(env))
		ft_putstr("Ok\n");
}

