/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_combft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:39:52 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 15:17:55 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_common(t_list *list_a, t_list *list_b)
{
	t_room	**tmp1;
	t_list	*tmp2;
	t_room	**tmp3;

	tmp2 = list_b;
	while (list_a != NULL && list_a->next != NULL)
	{
		list_b = tmp2;
		tmp1 = list_a->content;
		while (list_b->next != NULL)
		{
			tmp3 = list_b->content;
			if (*tmp1 == *tmp3)
				return (0);
			list_b = list_b->next;
		}
		list_a = list_a->next;
	}
	return (1);
}

int		lem_in_comb_compare(t_list **cur_comb, t_list *to_add)
{
	t_list	*tmp1;
	t_list	**tmp2;

	tmp1 = *cur_comb;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->content;
		if (lem_in_common(*tmp2, to_add) == 0)
			return (0);
		tmp1 = tmp1->next;
	}
	return (1);
}

void	lem_in_add(t_list **all_comb, t_list *cur_comb)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp2 = ft_lstdup(cur_comb);
	tmp1 = ft_lstnew(&tmp2, sizeof(t_list*));
	ft_lstlast(all_comb, tmp1);
}

void	lem_in_add_nodup(t_list **all_comb, t_list *cur_comb)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp2 = cur_comb;
	tmp1 = ft_lstnew(&tmp2, sizeof(t_list*));
	ft_lstlast(all_comb, tmp1);
}

void	lem_in_del_last(t_list **comb)
{
	t_list	*tmp1;

	tmp1 = *comb;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	ft_lstdelone(comb, tmp1);
}
