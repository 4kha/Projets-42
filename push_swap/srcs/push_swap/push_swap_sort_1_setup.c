/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1_setup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 02:07:03 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

void	push_swap_sort_1_setup_put_1(t_list **pile_a, t_list **pile_b,
		t_list **command, int list_len)
{
	int		med;
	int		count;

	count = 0;
	med = ft_lstmed(*pile_a, list_len);
	while (count < list_len / 2)
	{
		if ((*pile_a)->content_size <= med)
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

void	push_swap_sort_1_setup_put_2(t_list **pile_a, t_list **pile_b,
		t_list **command, int min)
{
	int		small;

	small = push_swap_pre_opti(*pile_a, *pile_b);
	while ((*pile_a)->content_size != min)
	{
		if ((*pile_a)->content_size == small)
		{
			push_swap_tag(pile_a, pile_b, command, "ra");
			small = push_swap_pre_opti(*pile_a, *pile_b);
			if ((*pile_b) != NULL && (*pile_b)->content_size == small)
				push_swap_sort_pa_ra(pile_a, pile_b, command, &small);
		}
		else
			push_swap_tag(pile_a, pile_b, command, "pb");
	}
	push_swap_sort_1_recursive(pile_a, pile_b, command);
	if (ft_lstlen(*pile_b) == 1)
	{
		push_swap_tag(pile_a, pile_b, command, "pa");
		push_swap_tag(pile_a, pile_b, command, "ra");
	}
}

int		push_swap_sort_1_setup(t_list *pile_a, int list_len, t_list **command)
{
	t_list	*pile_b;
	int		min;

	if (list_len == 1)
		return (0);
	pile_b = NULL;
	min = ft_lstmin_until(pile_a, list_len);
	push_swap_sort_1_setup_put_1(&pile_a, &pile_b, command, list_len);
	push_swap_sort_1_setup_put_2(&pile_a, &pile_b, command, min);
	push_swap_command_opti(command);
	push_swap_sort_command_opti_2(command, ft_lstlen(pile_a));
	ft_lstfree(pile_a);
	ft_lstfree(pile_b);
	return (0);
}
