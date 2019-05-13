/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:10:59 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:07:57 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_swap_px(t_list **pile1, t_list **pile2)
{
	t_list		*tmp1;

	if ((*pile1) == NULL)
		return ;
	tmp1 = (*pile1)->next;
	(*pile1)->next = (*pile2);
	(*pile2) = (*pile1);
	(*pile1) = tmp1;
}
