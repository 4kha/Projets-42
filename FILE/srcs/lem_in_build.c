/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:36:17 by khtran            #+#    #+#             */
/*   Updated: 2018/05/16 19:29:46 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_build_room(char *line, t_env *env)
{
	int			tmp;
	char		*name;
	t_room		*room;
	long		pos[3];

	tmp = ft_count_occur(line, ' ', ft_count_char(line, ' ') - 1);
	pos[0] = ft_atoi(&line[tmp]);
	name = ft_strndup(line, tmp);
	tmp = ft_count_occur(line, ' ', ft_count_char(line, ' '));
	pos[1] = ft_atoi(&line[tmp]);
	if ((pos[2] = lem_in_find_pos(name, pos[0], pos[1], env)) == 0)
	{
		room = lem_in_find_room(name, env);
		room->x = pos[0];
		room->y = pos[1];
		room->status = 0;
	}
	if (pos[2] == 1)
		return (1);
	if ((*env).trigger == 1)
		(*env).m_start = room;
	else if ((*env).trigger == 2)
		(*env).m_end = room;
	return (0);
}

int		lem_in_build_pipe(char *line, t_env *env)
{
	int			tmp;
	char		*first;
	char		*second;

	tmp = ft_count_occur(line, '-', 1);
	first = ft_strndup(line, tmp);
	second = ft_strdup(&line[tmp + 1]);
	if (ft_strcmp(first, second) == 0)
	{
		free(first);
		free(second);
		return (1);
	}
	tmp = lem_in_room_exist(first, second, env, 1);
	free(first);
	free(second);
	if (tmp == 1)
		return (1);
	return (0);
}
