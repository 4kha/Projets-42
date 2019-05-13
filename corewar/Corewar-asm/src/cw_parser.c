/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 01:35:12 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/27 15:21:02 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <fcntl.h>
#include <unistd.h>

void		cw_display_labels(t_asm *comp)
{
	t_lbl	*tmp;
	t_idx	*tmp2;

	tmp = comp->label;
	ft_printf("-----------------------------------------------------------\n");
	while (tmp)
	{
		ft_printf("Nom label : %s -- ", tmp->name);
		ft_printf("Confirmed : %d -- ", tmp->confirmed);
		ft_printf("@ : %d\n", tmp->add);
		if (tmp->replace)
		{
			ft_printf("Replacement to do :\n");
			tmp2 = tmp->replace;
			while (tmp2)
			{
				ft_printf("@: %d\n", tmp2->idx);
				ft_printf("@i: %d\n", tmp2->value);
				tmp2 = tmp2->next;
			}
		}
		ft_printf("Next : %p\n\n", tmp->next);
		tmp = tmp->next;
	}
}

/*
** bonus :
** - compiler plusieurs .s d'un coup
** - operations mathematiques
** - decompilateur
*/

static int	cw_check_h(void)
{
	if (REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3 || COMMENT_CHAR != '#'
		|| LABEL_CHAR != ':' || DIRECT_CHAR != '%' || SEPARATOR_CHAR != ','
		|| PROG_NAME_LENGTH != 128 || COMMENT_LENGTH != 2048
		|| COREWAR_EXEC_MAGIC != 0xea83f3
		|| ft_strcmp(NAME_CMD_STRING, ".name")
		|| ft_strcmp(COMMENT_CMD_STRING, ".comment")
		|| ft_strcmp(LABEL_CHARS, "abcdefghijklmnopqrstuvwxyz_0123456789"))
		return (0);
	return (1);
}

static void	cw_check_file(t_asm *comp, char *filename)
{
	if (!(comp->r_str = ft_strsub(filename, ft_strlen(filename) - 2, 2)))
		cw_error(comp, "Malloc error (file extension)\n");
	if (ft_strcmp(comp->r_str, ".s"))
		cw_error(comp, "Bad extension\n");
	ft_strdel(&comp->r_str);
	if ((comp->fd = open(filename, O_RDONLY)) == -1)
		cw_error(comp, "Error when opening file\n");
	if (!(comp->r_str = ft_strndup(filename, ft_strlen(filename) - 2)))
		cw_error(comp, "Malloc error (creation of .cor, part1)\n");
	if (!(comp->cor_file = ft_strjoin(comp->r_str, ".cor")))
		cw_error(comp, "Malloc error (creation of .cor, part2)\n");
	ft_strdel(&comp->r_str);
}

static void	cw_init_struct(t_asm *comp)
{
	comp->i = 4;
	comp->fd = 0;
	comp->line = NULL;
	comp->r_str = NULL;
	comp->cor_file = NULL;
	comp->data = NULL;
	comp->label = NULL;
}

int			main(int argc, char **argv)
{
	t_asm	*comp;

	if (argc == 2 && cw_check_h())
	{
		if (!(comp = (t_asm*)malloc(sizeof(t_asm) * 1)))
			cw_error(comp, "Malloc error (asm struct)\n");
		cw_init_struct(comp);
		cw_check_file(comp, argv[1]);
		cw_get_header(comp);
		cw_get_instructions(comp);
		close(comp->fd);
		comp->fd = 0;
		cw_create_file(comp);
		cw_free_struct(comp);
	}
	else
	{
		ft_printf("\nUsage : ./asm FILE.s\n\n");
		if (!cw_check_h())
			ft_printf("Do not touch that f***ing .h !\n\n");
	}
	return (0);
}
