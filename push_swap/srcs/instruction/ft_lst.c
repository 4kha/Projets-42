/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 03:38:03 by khtran            #+#    #+#             */
/*   Updated: 2018/03/15 12:26:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "instruction.h"

int		ft_lstlen(t_list *list)
{
	int		count;

	count = 0;
	while (list != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstdup(t_list *target)
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = NULL;
	while (target != NULL)
	{
		tmp = ft_lstnew("\0", 0);
		tmp->content_size = target->content_size;
		ft_lstlast(&cpy, tmp);
		target = target->next;
	}
	return (cpy);
}

void	ft_lstfree(t_list *to_free)
{
	t_list	*tmp;

	while (to_free != NULL)
	{
		tmp = to_free->next;
		free(to_free->content);
		free(to_free);
		to_free = tmp;
	}
}

t_list	*ft_lsttail(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstdelmail(t_list **command, t_list *remove)
{
	t_list	*next;
	t_list	*before;

	before = *command;
	next = (*command)->next;
	if (*command == remove)
	{
		free(before->content);
		free(before);
		*command = next;
		return ;
	}
	while (remove != next && next != NULL)
	{
		before = next;
		next = next->next;
	}
	if (next == remove)
	{
		before->next = next->next;
		free(next->content);
		free(next);
	}
}
