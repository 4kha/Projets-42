/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/28 23:01:26 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_check_args(t_asm *comp, int i, int *total_size)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 3);
	*total_size = 0x54;
	i = cw_check_reg(comp, comp->r_str, 0);
	i = cw_check_separator(comp, i, "Bad argument (add instruction)\n");
	i = cw_check_reg(comp, comp->r_str, i);
	i = cw_check_separator(comp, i, "Bad argument (add instruction)\n");
	i = cw_check_reg(comp, comp->r_str, i);
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (add instruction)\n");
}

void		cw_add(t_asm *comp, int i)
{
	int		total_size;

	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 4;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = cw_get_args(comp, 1, 1, 2);
	i = cw_get_args(comp, i + 1, 1, 3);
	cw_get_args(comp, i + 1, 1, 4);
}
