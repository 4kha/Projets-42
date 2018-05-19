/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_printsol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:41:57 by khtran            #+#    #+#             */
/*   Updated: 2018/05/19 05:28:41 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_common(t_list *list_a, t_list *list_b)
{
	t_room	**tmp1;
	t_list	*tmp2;
	t_room	**tmp3;

	while (list_a != NULL)
	{
		tmp2 = list_b;
		tmp1 = list_a->content;
		while (list_b != NULL)
		{
			tmp3 = list_b->content;
			if ((*tmp1)->name == (*tmp3)->name)
				return (0);
			list_b = list_b->next;
		}
		list_a = list_a->next;
	}
	return (1);
}

t_list	lem_in_combine(t_list **way, t_solve *data, t_list **comb)
{
	if ()
}

void	lem_in_solution_process(t_list **way, int nbr, t_env *env)
{
	t_list	*comb;
	t_solve	*data;

	data->max_entry = ft_min(ft_lstlen((*env).m_start->chemin),
			ft_lstlen((*env).m_end->chemin));
	comb = 0;
	if (ft_lstlen(*way) == 1)
	{

	}
/*	while ((*tmp1)->next != NULL)
	{
		thing = (*way)->content;
		list = (*way)->next->content;
		printf("comp = %d\n",lem_in_common(*thing, *list));
	}*/
}
