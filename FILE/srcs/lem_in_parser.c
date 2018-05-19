/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:19:44 by khtran            #+#    #+#             */
/*   Updated: 2018/05/16 17:16:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_parser_room_pipe(char *line, t_env *env)
{
	if ((*env).mode == 0 && lem_in_check_room(line, env) == 0)
	{
		if (lem_in_build_room(line, env) == 1)
			return (1);
	}
	else if (lem_in_check_pipe(line, env) == 0)
	{
		(*env).mode = 1;
		if ((*env).m_start == NULL || (*env).m_end == NULL)
			return (1);
		if (lem_in_build_pipe(line, env) == 1)
			return (1);
	}
	else
		return (1);
	(*env).trigger = 0;
	return (0);
}

int		lem_in_parser(char *line, t_env *env)
{
	if (*line == 0)
		return (1);
	if (*line == 'L')
		return (1);
	else if (*line == '#')
	{
		if (ft_strcmp(line, "##end") == 0)
			(*env).trigger = 2;
		else if (ft_strcmp(line, "##start") == 0)
			(*env).trigger = 1;
	}
	else if (lem_in_parser_room_pipe(line, env) == 1)
		return (1);
	return (0);
}
