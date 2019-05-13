/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 05:21:37 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/27 14:53:09 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_get_args(t_asm *comp, int i, int size)
{
	char	*tmp;

	if (comp->r_str[i] == LABEL_CHAR)
	{
		tmp = comp->r_str;
		if (!(comp->r_str = ft_strsub(comp->r_str, 1,
			ft_strlen(comp->r_str) - 1)))
			cw_error(comp, "Malloc error (getting label)\n");
		free(tmp);
		cw_get_label(comp, i + 1, (comp->i - 1) + (size * 100000000));
		i = -1;
		while (++i < size)
			comp->data[comp->i++] = '0';
	}
	else
		cw_get_number(comp, i, size);
}

static void	cw_check_args(t_asm *comp, int i)
{
	if (!(comp->r_str = ft_strsub(comp->line, i, ft_strlen(comp->line) - i)))
		cw_error(comp, "Malloc error (counting args)\n");
	cw_count_args(comp, comp->r_str, 1);
	i = cw_check_dir(comp, comp->r_str, 0);
	if (comp->r_str[i])
		cw_error(comp, "Bad argument (fork instruction)\n");
}

void	cw_fork(t_asm *comp, int i)
{
	ft_strdel(&comp->r_str);
	comp->data[comp->i++] = 48 + 12;
	i = ft_skip_whitespace(comp->line, i);
	cw_check_args(comp, i);
	cw_get_args(comp, 1, 2);
}
