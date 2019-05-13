/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:19:08 by khtran            #+#    #+#             */
/*   Updated: 2017/11/15 00:49:43 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrem(t_list **start, t_list *all)
{
	t_list		*before;
	t_list		*current;

	before = (*start);
	current = (*start);
	while (current != all && current != NULL)
	{
		before = current;
		current = current->next;
	}
	if (current == all && current != NULL)
	{
		if (current == before)
		{
			(*start) = (*start)->next;
			free(current);
		}
		else
		{
			before->next = current->next;
			free(current);
		}
	}
}
