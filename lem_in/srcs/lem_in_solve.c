/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:23:28 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 15:17:10 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_add_rec(t_list **sol, t_list **way, t_room **tmp3)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp4;

	tmp2 = ft_lstdup(*sol);
	tmp4 = ft_lstnew(&(*tmp3), sizeof(t_room*));
	ft_lstlast(&tmp2, tmp4);
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
	while (tmp1 != NULL && ((*env).cur_sol != (*env).max_sol))
	{
		tmp3 = tmp1->content;
		if (*tmp3 == (*env).m_end)
		{
			lem_in_add_rec(sol, way, tmp3);
			return (1);
		}
		if ((*tmp3)->status == 0)
		{
			(*tmp3)->status = 1;
			tmp2 = ft_lstnew(&(*tmp3), sizeof(t_room*));
			ft_lstlast(sol, tmp2);
			(*env).cur_sol += lem_in_recursive(env, sol, way, *tmp3);
			ft_lstdelone(sol, tmp2);
			(*tmp3)->status = 0;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int		lem_in_room_len(t_room *room2)
{
	int		count;
	t_room	*room;

	room = room2;
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
	int		ret;

	solution = NULL;
	way = NULL;
	tmp = (*env).m_start;
	tmp->status = 1;
	lem_in_recursive(env, &solution, &way, tmp);
	if ((ret = ft_lstlen(way)) != 0)
		lem_in_solution_process(&way, env);
	else
		ft_putstr("ERROR\n");
	lem_in_freeway(way);
	lem_in_freeroom((*env).room);
	if (ret == 0)
		return (0);
	return (1);
}

void	lem_in_solve(t_env *env)
{
	if ((*env).m_start == NULL || (*env).m_end == NULL
			|| (*env).room == NULL)
		ft_error("ERROR\n");
	if ((*env).m_start == (*env).m_end)
		ft_error("ERROR\n");
	lem_in_recursive_set(env);
}
