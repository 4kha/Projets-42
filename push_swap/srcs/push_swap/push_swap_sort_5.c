/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:04:24 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:57 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

int		push_swap_take(t_list *pile_a, int nbr)
{
	int		count;
	t_list	*tmp;

	tmp = pile_a;
	count = 0;
	while (count != nbr && tmp != NULL && tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (tmp->content_size);
}

void	push_swap_sort_5_setup_put_1(t_list **pile_a, t_list **pile_b,
		t_list **command, int pivot)
{
	int		under;
	int		count;

	count = 0;
	under = ft_lstunder(*pile_a, pivot);
	while (count < under && *pile_a != NULL)
	{
		if ((*pile_a)->content_size <= pivot)
		{
			push_swap_tag(pile_a, pile_b, command, "pb");
			count++;
		}
		else
			push_swap_tag(pile_a, pile_b, command, "ra");
	}
	push_swap_sort_1_recursive(pile_a, pile_b, command);
	if (ft_lstlen(*pile_b) == 1)
	{
		push_swap_tag(pile_a, pile_b, command, "pa");
		push_swap_tag(pile_a, pile_b, command, "ra");
	}
}

int		push_swap_sort_5_setup(t_list *pile_a, t_list **command, int pivot)
{
	t_list	*pile_b;
	int		list_len;
	int		min;

	list_len = ft_lstlen(pile_a);
	min = ft_lstmin(pile_a);
	pile_b = NULL;
	push_swap_sort_5_setup_put_1(&pile_a, &pile_b, command, pivot);
	push_swap_sort_1_setup_put_2(&pile_a, &pile_b, command, min);
	push_swap_command_opti(command);
	push_swap_sort_command_opti_2(command, ft_lstlen(pile_a));
	ft_lstfree(pile_a);
	ft_lstfree(pile_b);
	return (0);
}
