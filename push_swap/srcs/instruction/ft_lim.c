/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:13:40 by khtran            #+#    #+#             */
/*   Updated: 2018/04/20 10:54:51 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	ft_lstlast(t_list **alst, t_list *newe)
{
	t_list		*tmp;

	tmp = *alst;
	if (tmp == NULL)
	{
		*alst = newe;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newe;
}

int		ft_lstmin_until(t_list *find, int list_len)
{
	int		min;
	int		index;

	index = 0;
	min = find->content_size;
	while (find != NULL && index < list_len)
	{
		if (find->content_size < min)
			min = find->content_size;
		find = find->next;
		index++;
	}
	return (min);
}

int		ft_lstmax(t_list *find)
{
	int		max;

	max = find->content_size;
	while (find)
	{
		if (find->content_size > max)
			max = find->content_size;
		find = find->next;
	}
	return (max);
}

int		ft_lstunder(t_list *pile, int value)
{
	int		count;

	count = 0;
	while (pile != NULL)
	{
		if (pile->content_size <= value)
		{
			count++;
		}
		pile = pile->next;
	}
	return (count);
}
