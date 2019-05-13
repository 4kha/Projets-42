/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:46:47 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_swap_rx(t_list **pile_x)
{
	t_list	*next;
	t_list	*tmp;

	if (*pile_x == NULL)
		return ;
	if ((*pile_x)->next == NULL)
		return ;
	next = (*pile_x)->next;
	tmp = next;
	while (next->next != NULL)
		next = next->next;
	next->next = (*pile_x);
	(*pile_x)->next = NULL;
	(*pile_x) = tmp;
}

void	push_swap_rr(t_list **pile_a, t_list **pile_b)
{
	push_swap_rx(pile_a);
	push_swap_rx(pile_b);
}

void	push_swap_rrx(t_list **pile_x)
{
	t_list	*tmp;
	t_list	*next;

	if (*pile_x == NULL)
		return ;
	if ((*pile_x)->next == NULL)
		return ;
	next = (*pile_x)->next;
	tmp = (*pile_x);
	while (next->next != NULL)
	{
		tmp = next;
		next = next->next;
	}
	next->next = (*pile_x);
	tmp->next = NULL;
	(*pile_x) = next;
}

void	push_swap_rrr(t_list **pile_a, t_list **pile_b)
{
	push_swap_rrx(pile_a);
	push_swap_rrx(pile_b);
}
