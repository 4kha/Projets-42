/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_lstft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:27:30 by khtran            #+#    #+#             */
/*   Updated: 2018/06/20 17:22:09 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*lem_in_list_in_list(t_list *maillon)
{
	t_list	**tmp;

	tmp = maillon->content;
	return (*tmp);
}

t_list	*ft_lstbef(t_list *base, t_list *cur)
{
	t_list	*tmp;

	tmp = base;
	while (tmp != NULL && tmp->next != NULL && tmp->next != cur)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstmin_chain(t_list *comb)
{
	t_list	*small;

	small = comb;
	while (comb != NULL)
	{
		if (small->content_size > comb->content_size)
			small = comb;
		comb = comb->next;
	}
	return (small);
}

int		ft_lstmax(t_list *comb)
{
	t_list	*big;

	big = comb;
	while (comb != NULL)
	{
		if (big->content_size < comb->content_size)
			big = comb;
		comb = comb->next;
	}
	return (big->content_size);
}

int		ft_lsttotal(t_list *list)
{
	int		total;

	total = 0;
	while (list != NULL)
	{
		total = total + list->content_size;
		list = list->next;
	}
	return (total);
}
