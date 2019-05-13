/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 04:58:18 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:09:33 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

void	visual_find_tag(t_list **pile_a, t_list **pile_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		push_swap_sx(pile_a);
	else if (ft_strcmp(line, "sb") == 0)
		push_swap_sx(pile_b);
	else if (ft_strcmp(line, "ss") == 0)
		push_swap_ss(pile_a, pile_b);
	else if (ft_strcmp(line, "pa") == 0)
		push_swap_px(pile_b, pile_a);
	else if (ft_strcmp(line, "pb") == 0)
		push_swap_px(pile_a, pile_b);
	else if (ft_strcmp(line, "ra") == 0)
		push_swap_rx(pile_a);
	else if (ft_strcmp(line, "rb") == 0)
		push_swap_rx(pile_b);
	else if (ft_strcmp(line, "rr") == 0)
		push_swap_rr(pile_a, pile_b);
	else if (ft_strcmp(line, "rra") == 0)
		push_swap_rrx(pile_a);
	else if (ft_strcmp(line, "rrb") == 0)
		push_swap_rrx(pile_b);
	else if (ft_strcmp(line, "rrr") == 0)
		push_swap_rrr(pile_a, pile_b);
	else
		ft_error();
}
