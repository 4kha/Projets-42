/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.champions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:56:25 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/29 04:10:13 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	deduce_color(t_a *arena, char *color)
{
	if (!arena || !color)
		return (0);
	if (ft_strcmp(color, "red") == 0)
		return (RED);
	else if (ft_strcmp(color, "green") == 0)
		return (GREEN);
	else if (ft_strcmp(color, "yellow") == 0)
		return (YELLOW);
	else if (ft_strcmp(color, "blue") == 0)
		return (BLUE);
	else if (ft_strcmp(color, "magenta") == 0)
		return (MAGENTA);
	else if (ft_strcmp(color, "cyan") == 0)
		return (CYAN);
	else
		error(arena, 1, "Error: unknown color");
	return (0);
}

char		**parse_color(char **av, t_a *arena, int n)
{
	int	color;
	int	i;

	i = 0;
	color = 0;
	if (!av || !arena)
		error(arena, 1, "Error: arena or argv unset");
	color = deduce_color(arena, *av);
	if (arena->champ)
		while (arena->champ[i])
		{
			if (arena->champ[i]->color == color
			&& !(arena->champ[i]->color_auto))
				error(arena, 1, "Error: two champions with the same color");
			i++;
		}
	return (parse_champion(++av, arena, n, color));
}

char		**parse_num(char **av, t_a *arena, int color)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!av || !arena)
		error(arena, 1, "Error: arena or argv unset");
	else if (!ft_isint(*av))
		error(arena, 1, "Error: champion number must be an integer value");
	else if ((n = ft_atoi(*av)) < 0)
		error(arena, 1, "Error: champion number must be gte 0");
	if (arena->champ)
		while (arena->champ[i])
		{
			if (arena->champ[i]->number == n
			&& !(arena->champ[i]->num_auto))
				error(arena, 1, "Error : two champions with the same number");
			i++;
		}
	return (parse_champion(++av, arena, n, color));
}

char		**parse_champion(char **av, t_a *arena, int number, int color)
{
	int		fd;
	t_c		*champion;

	fd = 0;
	champion = NULL;
	if (!av || !arena)
		error(arena, 1, "Error: arena or argv unset");
	if (!ft_strcmps(*av, "--color") || !ft_strcmp(*av, "-c"))
		return (parse_color(++av, arena, number));
	if (!ft_strcmps(*av, "--number") || !ft_strcmp(*av, "-n"))
		return (parse_num(++av, arena, color));
	if (ft_strcmps(ft_strright(*av, 4), ".cor"))
		error(arena, 1, "Error: only .cor files as accepted (1)");
	if (!(champion = init_c(arena, number, color)))
		error(arena, 1, "Error: cannot initialize champion");
	if ((fd = open(*av, O_RDONLY)) == -1)
		error(arena, 1, "Error: cannot open file");
	read_champion(arena, champion, fd);
	close(fd);
	return (++av);
}
