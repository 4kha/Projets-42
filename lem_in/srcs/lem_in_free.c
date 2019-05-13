/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:08:41 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 15:38:54 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_freeroom(t_room *room)
{
	t_room	*room2;

	while (room != NULL)
	{
		room2 = room;
		if (room->name != NULL)
			free(room->name);
		ft_lstfree(room->chemin);
		room = room->next;
		free(room2);
	}
}

void	lem_in_freeway(t_list *list)
{
	t_list	*tmp1;
	t_list	*start;

	start = list;
	while (list != NULL)
	{
		tmp1 = lem_in_list_in_list(list);
		ft_lstfree(tmp1);
		list = list->next;
	}
	ft_lstfree(start);
}

void	lem_in_comb_free(t_list **all_comb)
{
	t_list	*first_list;
	t_list	*second_list;

	first_list = *all_comb;
	while (first_list != NULL)
	{
		second_list = lem_in_list_in_list(first_list);
		ft_lstfree(second_list);
		first_list = first_list->next;
	}
	ft_lstfree(*all_comb);
}
