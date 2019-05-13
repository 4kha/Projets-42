/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 01:45:16 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/29 02:25:17 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_inst_1(t_asm *comp, int i)
{
	if (!ft_strcmp(comp->r_str, "live"))
		cw_live(comp, i);
	else if (!ft_strcmp(comp->r_str, "zjmp"))
		cw_zjmp(comp, i);
	else if (!ft_strcmp(comp->r_str, "lfork"))
		cw_lfork(comp, i);
	else if (!ft_strcmp(comp->r_str, "or"))
		cw_or(comp, i);
	else if (!ft_strcmp(comp->r_str, "sub"))
		cw_sub(comp, i);
	else if (!ft_strcmp(comp->r_str, "and"))
		cw_and(comp, i);
	else if (!ft_strcmp(comp->r_str, "add"))
		cw_add(comp, i);
	else if (!ft_strcmp(comp->r_str, "xor"))
		cw_xor(comp, i);
	else
		cw_error(comp, "Unknown instruction\n");
}

static void	cw_inst_2(t_asm *comp, int i)
{
	if (!ft_strcmp(comp->r_str, "ld"))
		cw_ld(comp, i);
	else if (!ft_strcmp(comp->r_str, "st"))
		cw_st(comp, i);
	else if (!ft_strcmp(comp->r_str, "lldi"))
		cw_lldi(comp, i);
	else if (!ft_strcmp(comp->r_str, "sti"))
		cw_sti(comp, i);
	else if (!ft_strcmp(comp->r_str, "fork"))
		cw_fork(comp, i);
	else if (!ft_strcmp(comp->r_str, "ldi"))
		cw_ldi(comp, i);
	else if (!ft_strcmp(comp->r_str, "lld"))
		cw_lld(comp, i);
	else if (!ft_strcmp(comp->r_str, "aff"))
		cw_aff(comp, i);
	else
		cw_error(comp, "Unknown instruction\n");
}

static void	cw_find_instruction(t_asm *comp, int i)
{
	int		start;

	start = ft_skip_whitespace(comp->line, i);
	i = start;
	while (comp->line[i] && !ft_iswhitespace(comp->line[i]))
		i++;
	if (!(comp->r_str = ft_strsub(comp->line, start, i - start)))
		cw_error(comp, "Malloc error (reading instruction)\n");
	if (!ft_strcmp(comp->r_str, "live") || !ft_strcmp(comp->r_str, "zjmp")
		|| !ft_strcmp(comp->r_str, "lfork") || !ft_strcmp(comp->r_str, "or")
		|| !ft_strcmp(comp->r_str, "sub") || !ft_strcmp(comp->r_str, "and")
		|| !ft_strcmp(comp->r_str, "add") || !ft_strcmp(comp->r_str, "xor"))
		cw_inst_1(comp, i);
	else if (!ft_strcmp(comp->r_str, "ld") || !ft_strcmp(comp->r_str, "st")
		|| !ft_strcmp(comp->r_str, "lldi") || !ft_strcmp(comp->r_str, "sti")
		|| !ft_strcmp(comp->r_str, "fork") || !ft_strcmp(comp->r_str, "ldi")
		|| !ft_strcmp(comp->r_str, "lld") || !ft_strcmp(comp->r_str, "aff"))
		cw_inst_2(comp, i);
	else
		cw_error(comp, "Unknown instruction\n");
	if (comp->r_str)
		ft_strdel(&comp->r_str);
}

void		cw_get_instructions(t_asm *comp)
{
	int		i;
	int		ret;

	ret = 1;
	while ((ret = get_next_line(comp->fd, &comp->line)) > 0)
	{
		cw_clean_line(comp);
		if (comp->line[0])
		{
			i = cw_get_label(comp, 0, comp->i);
			if (comp->line[i])
				cw_find_instruction(comp, i);
		}
		ft_strdel(&comp->line);
		if (comp->i - HEADER_LENGTH > CHAMP_MAX_SIZE)
			cw_error(comp, "Oh no, it's too big for me !\n");
	}
	if (comp->i - HEADER_LENGTH <= 0)
		cw_error(comp, "No code, no .cor !\n");
	if (ret == -1)
		cw_error(comp, "Error when reading file\n");
	i = comp->i;
	cw_place_size(comp);
	cw_place_labels(comp);
	comp->i = i;
}
