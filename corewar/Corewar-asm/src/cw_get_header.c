/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 00:29:07 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/27 15:36:42 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	cw_get_comment(t_asm *comp)
{
	int		i;

	if (!(comp->r_str = ft_strsub(comp->line, 0,
		ft_strlen(COMMENT_CMD_STRING))))
		cw_error(comp, "Malloc error (champion's comment)\n");
	if (ft_strcmp(comp->r_str, COMMENT_CMD_STRING))
		cw_error(comp, "Comment command error\n");
	ft_strdel(&comp->r_str);
	i = ft_skip_whitespace(comp->line, ft_strlen(COMMENT_CMD_STRING));
	if (comp->line[i] != '\"')
		cw_error(comp, "Comment error\n");
	i++;
	while (comp->line[i] && comp->line[i] != '\"'
			&& comp->i < PROG_NAME_LENGTH + COMMENT_LENGTH + 12)
		comp->data[comp->i++] = comp->line[i++] + 48;
	if (comp->line[i] != '\"')
		cw_error(comp, "Comment error\n");
	if (comp->line[i + 1])
	{
		i = ft_skip_whitespace(comp->line, i + 1);
		if (comp->line[i])
			cw_error(comp, "Comment error\n");
	}
	while (comp->i < HEADER_LENGTH)
		comp->data[comp->i++] = '0';
}

static void	cw_get_name(t_asm *comp)
{
	int		i;

	if (!(comp->r_str = ft_strsub(comp->line, 0, ft_strlen(NAME_CMD_STRING))))
		cw_error(comp, "Malloc error (champion's name)\n");
	if (ft_strcmp(comp->r_str, NAME_CMD_STRING))
		cw_error(comp, "Name command error\n");
	ft_strdel(&comp->r_str);
	i = ft_skip_whitespace(comp->line, ft_strlen(NAME_CMD_STRING));
	if (comp->line[i] != '\"')
		cw_error(comp, "Name error\n");
	i++;
	while (comp->line[i] && comp->line[i] != '\"'
			&& comp->i < PROG_NAME_LENGTH + 4)
		comp->data[comp->i++] = comp->line[i++] + 48;
	if (comp->line[i] != '\"')
		cw_error(comp, "Name error\n");
	if (comp->line[i + 1])
	{
		i = ft_skip_whitespace(comp->line, i + 1);
		if (comp->line[i])
			cw_error(comp, "Name error\n");
	}
	while (comp->i < PROG_NAME_LENGTH + 12)
		comp->data[comp->i++] = '0';
}

void		cw_clean_line(t_asm *comp)
{
	int		i;

	if ((i = ft_strchri(comp->line, COMMENT_CHAR)) != -1)
	{
		comp->r_str = comp->line;
		if (!(comp->line = ft_strsub(comp->line, 0, i)))
			cw_error(comp, "Malloc error (cleaning line)\n");
		ft_strdel(&comp->r_str);
	}
	i = ft_strlen(comp->line) - 1;
	while (i >= 0 && ft_iswhitespace(comp->line[i]))
		i--;
	comp->r_str = comp->line;
	if (!(comp->line = ft_strsub(comp->line, 0, i + 1)))
		cw_error(comp, "Malloc error (cleaning line)\n");
	ft_strdel(&comp->r_str);
}

static void	cw_magic(t_asm *comp)
{
	int		i;
	int		magic;

	if (!(comp->data = (char*)malloc(sizeof(char) *
		(HEADER_LENGTH + CHAMP_MAX_SIZE + 1))))
		cw_error(comp, "Malloc error (creating header)\n");
	magic = COREWAR_EXEC_MAGIC;
	i = 3;
	while (i >= 0)
	{
		comp->data[i] = (magic % 256) + 48;
		magic = magic / 256;
		i--;
	}
}

void		cw_get_header(t_asm *comp)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	cw_magic(comp);
	while (ret && i < 2)
	{
		if ((ret = get_next_line(comp->fd, &comp->line)) == -1)
			cw_error(comp, "Error when reading file\n");
		cw_clean_line(comp);
		if (ret && comp->line[0])
		{
			if (i == 0)
				cw_get_name(comp);
			else if (i == 1)
				cw_get_comment(comp);
			i++;
		}
		if (comp->line)
			ft_strdel(&comp->line);
	}
	if (i != 2)
		cw_error(comp, "Incomplete header\n");
}
