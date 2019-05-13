/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 00:04:04 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/28 21:05:05 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <unistd.h>

static void	cw_free_lbl(t_asm *comp)
{
	t_idx	*tmp1;
	t_lbl	*tmp2;

	while (comp->label)
	{
		free(comp->label->name);
		while (comp->label->replace)
		{
			tmp1 = comp->label->replace;
			comp->label->replace = comp->label->replace->next;
			free(tmp1);
		}
		tmp2 = comp->label;
		comp->label = comp->label->next;
		free(tmp2);
	}
}

void		cw_free_struct(t_asm *comp)
{
	if (comp)
	{
		if (comp->line)
			free(comp->line);
		if (comp->fd > 0)
			close(comp->fd);
		if (comp->r_str)
			free(comp->r_str);
		if (comp->cor_file)
			free(comp->cor_file);
		if (comp->data)
			free(comp->data);
		cw_free_lbl(comp);
		free(comp);
	}
}

void		cw_error(t_asm *comp, char *str)
{
	cw_free_struct(comp);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
