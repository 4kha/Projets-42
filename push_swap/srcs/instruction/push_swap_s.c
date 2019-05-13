/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:07:42 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:08:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_swap_sx(t_list **pile_x)
{
	int		tmp;

	if (*pile_x == NULL)
		return ;
	if ((*pile_x)->next == NULL)
		return ;
	tmp = (*pile_x)->content_size;
	(*pile_x)->content_size = (*pile_x)->next->content_size;
	(*pile_x)->next->content_size = tmp;
}

void	push_swap_ss(t_list **pile_a, t_list **pile_b)
{
	push_swap_sx(pile_a);
	push_swap_sx(pile_b);
}
