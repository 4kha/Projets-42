/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:25:47 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:40 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

int		checker_order_safe(t_list *pile_a, t_list *pile_b)
{
	int		biggest;
	int		addr;
	int		tmp;

	if (pile_b != NULL)
		return (1);
	addr = pile_a->content_size;
	biggest = addr;
	while (pile_a != NULL)
	{
		addr = pile_a->content_size;
		tmp = addr;
		pile_a = pile_a->next;
		if (tmp >= biggest)
			biggest = tmp;
		else
			return (1);
	}
	return (0);
}

void	push_swap_sort_2_if(t_list **pile_a, t_list **command, int len,
		int *stop)
{
	push_swap_tag(pile_a, NULL, command, "sa");
	push_swap_sort_command_opti_2(command, len);
	*stop = ft_lstlen(*command);
}

int		push_swap_sort_2_setup_min(t_list *pile_a, t_list **command, int nbr)
{
	int		min;
	int		stop;
	int		len;

	len = ft_lstlen(pile_a);
	min = ft_lstmin(pile_a);
	stop = 0;
	while (checker_order_safe(pile_a, NULL) == 1)
	{
		if (pile_a->content_size > pile_a->next->content_size
				&& pile_a->next->content_size != min)
			push_swap_sort_2_if(&pile_a, command, len, &stop);
		else
		{
			push_swap_tag(&pile_a, NULL, command, "ra");
			stop++;
		}
		if (stop > nbr + len)
			break ;
	}
	push_swap_sort_command_opti_2(command, len);
	ft_lstfree(pile_a);
	return (0);
}

int		push_swap_sort_2_setup_max(t_list *pile_a, t_list **command, int nbr)
{
	int		max;
	int		stop;
	int		len;

	len = ft_lstlen(pile_a);
	max = ft_lstmax(pile_a);
	stop = 0;
	while (checker_order_safe(pile_a, NULL) == 1)
	{
		if (pile_a->content_size > pile_a->next->content_size
				&& pile_a->content_size != max)
			push_swap_sort_2_if(&pile_a, command, len, &stop);
		else
		{
			push_swap_tag(&pile_a, NULL, command, "ra");
			stop++;
		}
		if (stop > nbr + len)
			break ;
	}
	push_swap_sort_command_opti_2(command, len);
	ft_lstfree(pile_a);
	return (0);
}
