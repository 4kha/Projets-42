/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.read_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:38:01 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 13:32:46 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_padding(void *mem)
{
	if (((((char *)mem)[0] & 0xff) != 0)
	|| ((((char *)mem)[1] & 0xff) != 0)
	|| ((((char *)mem)[2] & 0xff) != 0)
	|| ((((char *)mem)[3] & 0xff) != 0))
		return (0);
	return (1);
}

static int	is_magic(void *mem)
{
	if (!((((char *)mem)[0] & 0xff) == 0)
	&& ((((char *)mem)[1] & 0xff) == ((CW_MAGIC >> 16) & 0xff))
	&& ((((char *)mem)[2] & 0xff) == ((CW_MAGIC >> 8) & 0xff))
	&& ((((char *)mem)[3] & 0xff) == ((CW_MAGIC) & 0xff)))
		return (0);
	return (1);
}

static int	is_prog_size(void *mem, t_c *champion)
{
	if (!ft_isint(((char *)mem)))
		return (0);
	champion->size = (((char *)mem)[0] & 0xff) * ft_pow(256, 3)
						+ (((char *)mem)[1] & 0xff) * ft_pow(256, 2)
						+ (((char *)mem)[2] & 0xff) * ft_pow(256, 1)
						+ (((char *)mem)[3] & 0xff) * 1;
	return (1);
}

void		read_champion(t_a *arena, t_c *champion, int fd)
{
	int		rr;
	void	*buff;

	rr = 0;
	if (!(buff = ft_memalloc(4)))
		error(arena, 0, "Error: cannot malloc buffer");
	if ((rr = read(fd, ft_memsets(buff, 0, 4), 4)) != 4 || !is_magic(buff))
		error(arena, 0, "Error: invalid verification key");
	if ((rr = read(fd, champion->name, PROG_NAME_SIZE)) != PROG_NAME_SIZE)
		error(arena, 0, "Error: invalid champion name");
	if ((rr = read(fd, buff, 4)) != 4 || !is_padding(buff))
		error(arena, 0, "Error: invalid padding");
	if ((rr = read(fd, ft_memsets(buff, 0, 4), 4)) != 4
	|| !is_prog_size(buff, champion) || champion->size > CHAMP_MAX_SIZE
	|| champion->size <= 0)
		error(arena, 0, "Error: invalid champion size");
	if ((rr = read(fd, champion->desc, DESC_SIZE)) != DESC_SIZE)
		error(arena, 0, "Error: invalid champion description");
	if ((rr = read(fd, ft_memsets(buff, 0, 4), 4)) != 4 || !is_padding(buff))
		error(arena, 0, "Error: invalid padding");
	if (!(champion->prog = ft_memalloc(champion->size)))
		error(arena, 0, "Error: cannot malloc program");
	if ((rr = read(fd, champion->prog, champion->size)) != champion->size)
		error(arena, 0, "Error: invalid champion program");
	ft_memdel(&buff);
}
