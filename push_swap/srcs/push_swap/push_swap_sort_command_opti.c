/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_command_opti.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:01:15 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:09:10 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instruction.h"

void	push_swap_command_opti(t_list **command)
{
	t_list	*tmp;

	tmp = *command;
	while (tmp != NULL && tmp->next != NULL)
	{
		if ((ft_strcmp(tmp->content, "pa") == 0 &&
		ft_strcmp(tmp->next->content, "pb") == 0) || ((ft_strcmp(tmp->content,
		"pb") == 0 && ft_strcmp(tmp->next->content, "pa") == 0)))
		{
			ft_lstdelmail(command, tmp->next);
			ft_lstdelmail(command, tmp);
			tmp = *command;
		}
		else if ((ft_strcmp(tmp->content, "ra") == 0 &&
		ft_strcmp(tmp->next->content, "rb") == 0) || ((ft_strcmp(tmp->content,
		"rb") == 0 && ft_strcmp(tmp->next->content, "ra") == 0)))
		{
			ft_lstdelmail(command, tmp->next);
			free(tmp->content);
			tmp->content = ft_strdup("rr");
			tmp = *command;
		}
		else
			tmp = tmp->next;
	}
}

void	push_swap_opti_2(t_list **command, int count,
		int pos, t_list **tmp)
{
	t_list	*tmp2;

	count = count - pos;
	while ((*tmp) != NULL && pos)
	{
		pos--;
		ft_strcpy((*tmp)->content, "rra");
		(*tmp) = (*tmp)->next;
	}
	while (count && (*tmp) != NULL)
	{
		tmp2 = (*tmp)->next;
		ft_lstdelmail(command, (*tmp));
		(*tmp) = tmp2;
		count--;
	}
}

void	push_swap_sort_command_opti_2(t_list **command, int len)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		count;
	int		pileb;

	tmp = *command;
	pileb = 0;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		count = 0;
		if (ft_strcmp(tmp->content, "pb") == 0)
			pileb++;
		if (ft_strcmp(tmp->content, "pa") == 0)
			pileb--;
		while (tmp2 != NULL && ft_strcmp(tmp2->content, "ra") == 0)
		{
			tmp2 = tmp2->next;
			count++;
		}
		if ((count > ((len - pileb) / 2)))
			push_swap_opti_2(command, count, (len - pileb) - count, &tmp);
		else
			tmp = tmp->next;
	}
}
