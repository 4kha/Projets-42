/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:22:07 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:51:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_a			*parse_input(t_a *arena, char **av)
{
	if (!(arena = init_a()))
		return (NULL);
	while (*av)
	{
		if (!ft_strcmp(*av, "--dump") || !ft_strcmp(*av, "-d")
		|| !ft_strcmp(*av, "-dump"))
			av = parse_dump(++av, arena);
		else if (!ft_strcmp(*av, "--visual"))
			av = parse_visual(++av, arena);
		else if (!ft_strcmp(*av, "--audio") || !ft_strcmp(*av, "-a"))
			av = parse_audio(++av, arena);
		else if (!ft_strcmp(*av, "--verbose") || !ft_strcmp(*av, "-v"))
			av = parse_verbose(++av, arena);
		else if (!ft_strcmp(*av, "--hard") || !ft_strcmp(*av, "-h"))
			av = parse_hard(++av, arena);
		else if (!ft_strcmp(*av, "--color") || !ft_strcmp(*av, "-c"))
			av = parse_color(++av, arena, -1);
		else if (!ft_strcmp(*av, "--number") || !ft_strcmp(*av, "-n"))
			av = parse_num(++av, arena, NO_COLOR);
		else if (!(ft_strcmp(ft_strright(*av, 4), ".cor")))
			av = parse_champion(av, arena, -1, NO_COLOR);
		else
			error(arena, 1, "Error: undefined option or character");
	}
	return (load_players(arena, count_champions(arena)));
}
