/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:42:38 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 18:42:39 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **command, t_list *remove)
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
