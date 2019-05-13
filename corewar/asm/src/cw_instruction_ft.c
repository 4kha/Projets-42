/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_instruction_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 01:20:27 by khtran            #+#    #+#             */
/*   Updated: 2018/06/28 22:26:26 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int			cw_check_separator(t_asm *comp, int i, char *error)
{
	if (comp->r_str[i++] != SEPARATOR_CHAR)
		cw_error(comp, error);
	i = ft_skip_whitespace(comp->r_str, i);
	return (i);
}

static int	cw_skip_separator(char *str, int i)
{
	while (str[i] && (ft_iswhitespace(str[i]) || str[i] == SEPARATOR_CHAR))
		i++;
	return (i);
}

int			cw_get_args(t_asm *comp, int i, int size, int octet)
{
	char	*tmp;

	if (comp->r_str[i] == LABEL_CHAR)
	{
		tmp = comp->r_str;
		if (!(comp->r_str = ft_strsub(comp->r_str, i,
			ft_strlen(comp->r_str) - i)))
			cw_error(comp, "Malloc error (getting label)\n");
		free(tmp);
		cw_get_label(comp, 1, (comp->i - octet) + (size * 100000000));
		i = -1;
		while (++i < size)
			comp->data[comp->i++] = 0;
	}
	else
		cw_get_number(comp, i, size);
	while (comp->r_str[i] && !ft_iswhitespace(comp->r_str[i])
			&& !(comp->r_str[i] == SEPARATOR_CHAR))
		i++;
	return (cw_skip_separator(comp->r_str, i));
}

int			cw_get_type(char c, int *total_size)
{
	*total_size = *total_size << 2;
	if (c == 'r')
	{
		(*total_size) += REG_CODE;
		return (REG_CODE);
	}
	else if (c == DIRECT_CHAR)
	{
		(*total_size) += DIR_CODE;
		return (DIR_CODE);
	}
	(*total_size) += IND_CODE;
	return (IND_CODE);
}

int			cw_tsize(int dir_size, int type, int mode)
{
	if (mode == 1)
	{
		if (type == IND_CODE)
			return (0);
		return (1);
	}
	if (type == REG_CODE)
		return (1);
	else if (type == DIR_CODE)
		return (dir_size);
	return (2);
}
