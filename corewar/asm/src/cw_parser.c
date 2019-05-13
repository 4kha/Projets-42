/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 01:35:12 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/29 02:08:16 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <fcntl.h>
#include <unistd.h>

static int	cw_check_h(void)
{
	if (REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3 || COMMENT_CHAR != '#'
		|| LABEL_CHAR != ':' || DIRECT_CHAR != '%' || SEPARATOR_CHAR != ','
		|| PROG_NAME_LENGTH != 128 || COMMENT_LENGTH != 2048
		|| MEM_SIZE != (4 * 1024) || CHAMP_MAX_SIZE != (MEM_SIZE / 6)
		|| COREWAR_EXEC_MAGIC != 0xea83f3 || REG_NUMBER != 16
		|| ft_strcmp(NAME_CMD_STRING, ".name")
		|| ft_strcmp(COMMENT_CMD_STRING, ".comment")
		|| HEADER_LENGTH != (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
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
	int		i;

	i = 1;
	while (argc >= 2 && cw_check_h() && i < argc)
	{
		if (!(comp = (t_asm*)malloc(sizeof(t_asm) * 1)))
			cw_error(comp, "Malloc error (asm struct)\n");
		cw_init_struct(comp);
		cw_check_file(comp, argv[i]);
		cw_get_header(comp, 0, 1);
		cw_get_instructions(comp);
		close(comp->fd);
		cw_create_file(comp);
		cw_free_struct(comp);
		i++;
	}
	if (argc < 2 || !cw_check_h())
	{
		ft_printf("\nUsage : ./asm FILE.s [FILE2.s FILE3.s ...]\n\n");
		if (!cw_check_h())
			ft_printf("Do not touch that f***ing .h !\n\n");
	}
	return (0);
}
