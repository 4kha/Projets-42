/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 07:19:11 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:50 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

int		push_swap_sort_3_condition(t_list *pile_a, t_list *pile_b)
{
	t_list	*tmp;
	int		max;
	int		min;

	tmp = ft_lsttail(pile_a);
	min = ft_lstmin(pile_a);
	max = ft_lstmax(pile_a);
	if ((((pile_b->content_size < pile_a->content_size))
			&& (pile_b->content_size > tmp->content_size))
			|| (tmp->content_size == max
			&& pile_a->content_size == min
			&& (pile_b->content_size > max || pile_b->content_size < min)))
		return (1);
	return (0);
}

int		push_swap_sort_3_while(t_list **pile_a, t_list **pile_b,
		t_list **command, int nbr)
{
	int		len;
	int		start;

	start = ft_lstlen(*command);
	len = ft_lstlen(*pile_a) + ft_lstlen(*pile_b);
	while (*pile_b != NULL)
	{
		if (push_swap_sort_3_condition(*pile_a, *pile_b) == 1)
		{
			push_swap_tag(pile_a, pile_b, command, "pa");
			push_swap_command_opti(command);
			push_swap_sort_command_opti_2(command, len);
			start = ft_lstlen(*command);
		}
		else
		{
			push_swap_tag(pile_a, pile_b, command, "ra");
			start++;
		}
		if (start > nbr + len)
			return (1);
	}
	return (0);
}

int		push_swap_sort_3_setup(t_list *pile_a, t_list **command, int nbr)
{
	t_list	*pile_b;
	int		min;
	int		len;

	len = ft_lstlen(pile_a);
	min = ft_lstmin(pile_a);
	pile_b = NULL;
	while (pile_a != NULL && pile_a->next != NULL
			&& pile_a->next->next != NULL)
		push_swap_tag(&pile_a, &pile_b, command, "pb");
	push_swap_sort_3_while(&pile_a, &pile_b, command, nbr);
	while (pile_b != NULL)
		push_swap_tag(&pile_a, &pile_b, command, "pa");
	while (pile_a->content_size != min)
		push_swap_tag(&pile_a, &pile_b, command, "ra");
	push_swap_command_opti(command);
	push_swap_sort_command_opti_2(command, len);
	ft_lstfree(pile_a);
	ft_lstfree(pile_b);
	return (0);
}
