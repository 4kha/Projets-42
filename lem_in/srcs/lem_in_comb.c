/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:44:39 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 15:18:19 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_len(t_list **list)
{
	int		len;
	t_list	*tmp2;

	len = 0;
	tmp2 = *list;
	while (tmp2 != NULL)
	{
		len = len + tmp2->content_size;
		tmp2 = tmp2->next;
	}
	return (len);
}

void	lem_in_comb_best(t_list **cur_comb, t_list **tmp_comb, t_solve *data)
{
	t_list	*tmp;

	if (*cur_comb == NULL)
	{
		*cur_comb = ft_lstdup(*tmp_comb);
		data->len = lem_in_len(cur_comb);
	}
	else
	{
		if (lem_in_len(cur_comb) > lem_in_len(tmp_comb))
		{
			tmp = *cur_comb;
			ft_lstfree(*cur_comb);
			*cur_comb = ft_lstdup(*tmp_comb);
			data->len = lem_in_len(cur_comb);
		}
	}
}

void	lem_in_comb_recursive(t_list **cur_comb, t_list **tmp_comb, t_list *way,
		t_solve *data)
{
	t_list	*tmp1;
	t_list	**tmp2;

	tmp1 = way;
	if (data->cur_entry == data->entry)
	{
		lem_in_comb_best(cur_comb, tmp_comb, data);
		(*cur_comb)->content_size = data->entry;
		return ;
	}
	while (tmp1 != NULL && (data->len == 0 || data->len <
				tmp1->content_size + lem_in_len(tmp_comb)))
	{
		tmp2 = tmp1->content;
		if (lem_in_comb_compare(tmp_comb, *tmp2) == 1)
		{
			lem_in_add_nodup(tmp_comb, *tmp2);
			data->cur_entry++;
			lem_in_comb_recursive(cur_comb, tmp_comb, tmp1, data);
			lem_in_del_last(tmp_comb);
			data->cur_entry--;
		}
		tmp1 = tmp1->next;
	}
}

int		lem_in_comb_recursive_set(t_solve *data, t_list **all_comb,
		t_list **way)
{
	t_list	*tmp_comb;
	t_list	*cur_comb;

	tmp_comb = NULL;
	cur_comb = NULL;
	data->len = 0;
	data->cur_entry = 0;
	lem_in_comb_recursive(&cur_comb, &tmp_comb, *way, data);
	if (cur_comb == NULL)
		return (1);
	lem_in_add(all_comb, cur_comb);
	ft_lstfree(cur_comb);
	return (0);
}
