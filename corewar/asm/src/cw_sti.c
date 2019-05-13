/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/28 23:21:03 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_check_args(t_asm *comp, int i, int *total_size)
{
	int		ret;

	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 3);
	i = 0;
	cw_get_type(comp->r_str[i], total_size);
	i = cw_check_reg(comp, comp->r_str, i);
	i = cw_check_separator(comp, i, "Bad argument (sti instruction)\n");
	if ((ret = cw_get_type(comp->r_str[i], total_size)) == 1)
		i = cw_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = cw_check_dir(comp, comp->r_str, i);
	else
		i = cw_check_ind(comp, comp->r_str, i);
	i = cw_check_separator(comp, i, "Bad argument (sti instruction)\n");
	if ((ret = cw_get_type(comp->r_str[i], total_size)) == 1)
		i = cw_check_reg(comp, comp->r_str, i);
	else if (ret == 2)
		i = cw_check_dir(comp, comp->r_str, i);
	else
		cw_error(comp, "Bad argument (sti instruction)\n");
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (sti instruction)\n");
	(*total_size) = (*total_size) << 2;
}

void		cw_sti(t_asm *comp, int i)
{
	int		total_size;
	int		label_index;

	total_size = 0;
	label_index = 2;
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 11;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i, &total_size);
	comp->data[comp->i++] = total_size;
	i = 0;
	i = cw_get_args(comp, i + cw_tsize(2, total_size >> 6, 1),
		cw_tsize(2, total_size >> 6, 0), label_index);
	label_index += cw_tsize(2, total_size >> 6, 0);
	i = cw_get_args(comp, i + cw_tsize(2, (total_size >> 4) & 0x3, 1),
		cw_tsize(2, (total_size >> 4) & 0x3, 0), label_index);
	label_index += cw_tsize(2, (total_size >> 4) & 0x3, 0);
	cw_get_args(comp, i + cw_tsize(2, (total_size >> 2) & 0x3, 1),
		cw_tsize(2, (total_size >> 2) & 0x3, 0), label_index);
}
