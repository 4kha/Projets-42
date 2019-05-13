/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_printsol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:41:57 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 09:51:11 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_comb_sort(t_list **way)
{
	t_list	*tmp1;
	t_list	**tmp2;
	int		trigger;
	int		len;

	trigger = 0;
	while (trigger != 1)
	{
		tmp1 = *way;
		trigger = 1;
		while (tmp1->next != NULL)
		{
			if (tmp1->content_size > tmp1->next->content_size)
			{
				tmp2 = tmp1->content;
				tmp1->content = tmp1->next->content;
				tmp1->next->content = tmp2;
				len = tmp1->content_size;
				tmp1->content_size = tmp1->next->content_size;
				tmp1->next->content_size = len;
				trigger = 0;
			}
			tmp1 = tmp1->next;
		}
	}
}

void	lem_in_size(t_list **all_comb)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = *all_comb;
	while (tmp1 != NULL)
	{
		tmp2 = lem_in_list_in_list(tmp1);
		while (tmp2 != NULL)
		{
			tmp3 = lem_in_list_in_list(tmp2);
			tmp2->content_size = ft_lstlen(tmp3);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	lem_in_solution_process(t_list **way, t_env *env)
{
	t_list	*all_comb;
	t_solve	data;

	all_comb = NULL;
	lem_in_comb_sort(way);
	data.max_entry = ft_min(ft_lstlen((*env).m_start->chemin),
			ft_lstlen((*env).m_end->chemin));
	data.cur_entry = 0;
	data.entry = 1;
	while (data.entry <= data.max_entry)
	{
		if (lem_in_comb_recursive_set(&data, &all_comb, way))
			break ;
		data.entry++;
	}
	lem_in_size(&all_comb);
	lem_in_way_best(&all_comb, env);
	lem_in_info(env, *way);
	lem_in_comb_free(&all_comb);
}
