/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:56:15 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 13:13:10 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		**parse_dump(char **av, t_a *arena)
{
	if (!av || !arena)
		error(arena, 1, "Error: arena or argv is unset");
	else if (!ft_isint(*av))
		error(arena, 1, "Error: dump value must be an integer value");
	else if ((arena->dump = ft_atoi(*av)) <= 0)
		error(arena, 1, "Error: dump value must be gt 0");
	return (++av);
}

char		**parse_verbose(char **av, t_a *arena)
{
	if (!av || !arena)
		error(arena, 1, "Error: arena or argv is unset");
	arena->verbose = TRUE;
	return (av);
}

char		**parse_visual(char **av, t_a *arena)
{
	arena->visual = TRUE;
	return (av);
}

char		**parse_audio(char **av, t_a *arena)
{
	arena->audio = TRUE;
	return (av);
}

char		**parse_hard(char **av, t_a *arena)
{
	arena->hard = TRUE;
	return (av);
}
