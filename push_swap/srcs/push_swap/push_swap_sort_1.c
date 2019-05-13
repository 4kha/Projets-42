/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:52:57 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:28 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

void		push_swap_sort_pa_ra(t_list **pile_a, t_list **pile_b,
		t_list **command, int *small)
{
	push_swap_tag(pile_a, pile_b, command, "pa");
	push_swap_tag(pile_a, pile_b, command, "ra");
	(*small) = push_swap_pre_opti(*pile_a, *pile_b);
}

int			push_swap_sort_1_put(t_list **pile_a, t_list **pile_b,
		t_list **command, int len)
{
	int		med_b;
	int		count;
	int		small;

	med_b = ft_lstmed(*pile_b, len);
	count = 0;
	small = push_swap_pre_opti(*pile_a, *pile_b);
	while (count < len / 2 && *pile_b != NULL)
	{
		if ((*pile_b)->content_size == small)
			push_swap_sort_pa_ra(pile_a, pile_b, command, &small);
		else if ((*pile_b)->content_size > med_b)
		{
			push_swap_tag(pile_a, pile_b, command, "pa");
			count++;
		}
		else
			push_swap_tag(pile_a, pile_b, command, "rb");
	}
	return (count);
}

void		push_swap_sort_1_pull(t_list **pile_a, t_list **pile_b,
		t_list **command, int count)
{
	int		small;

	small = push_swap_pre_opti(*pile_a, *pile_b);
	while (count)
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
		count--;
	}
}

void		push_swap_sort_1_recursive(t_list **pile_a, t_list **pile_b,
		t_list **command)
{
	int		count;
	int		len;
	int		small;

	if (*pile_b == NULL)
		return ;
	len = ft_lstlen(*pile_b);
	count = push_swap_sort_1_put(pile_a, pile_b, command, len);
	small = push_swap_pre_opti(*pile_a, *pile_b);
	if (len > 1)
		push_swap_sort_1_recursive(pile_a, pile_b, command);
	else if ((*pile_b)->content_size == small)
	{
		push_swap_sort_pa_ra(pile_a, pile_b, command, &small);
		return ;
	}
	push_swap_sort_1_pull(pile_a, pile_b, command, count);
	if (ft_lstlen(*pile_b) > 1)
		push_swap_sort_1_recursive(pile_a, pile_b, command);
}
