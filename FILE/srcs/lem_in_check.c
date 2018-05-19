/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:01:48 by khtran            #+#    #+#             */
/*   Updated: 2018/05/16 17:17:19 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lem_in_check_pos(char *line, int *index, int mode)
{
	int		before;

	if (ft_atoi(&line[*index]) == 123456789123)
		return (1);
	if (ft_isstr(line[*index], "+-"))
		(*index)++;
	before = *index;
	while (ft_isdigit(line[*index]))
		(*index)++;
	if (mode == 1)
	{
		if (before == *index || !line[(*index)++])
			return (1);
	}
	else
	{
		if (before == *index || line[*index])
			return (1);
	}
	return (0);
}

int		lem_in_check_room(char *line, t_env *env)
{
	int		index;
	int		tmp;

	tmp = ft_count_char(line, ' ');
	if (tmp < 2)
		return (1);
	tmp = ft_count_occur(line, ' ', tmp - 1);
	index = 0;
	while (line[index] && index != tmp && line[index] != '-')
		index++;
	if (!line[index] || index == 0 || line[index++] == '-')
		return (1);
	if (lem_in_check_pos(line, &index, 1))
		return (1);
	if (lem_in_check_pos(line, &index, 2))
		return (1);
	return (0);
}

int		lem_in_check_pipe(char *line, t_env *env)
{
	int		index;
	int		tmp;

	index = 0;
	tmp = index;
	while (line[index] && line[index] != '-')
		index++;
	if (!line[index] || index++ == tmp)
		return (1);
	tmp = index;
	while (line[index] && line[index] != '-')
		index++;
	if (line[index] || index == tmp)
		return (1);
	return (0);
}

int		lem_in_nbrant(char *line, t_env *env)
{
	char *tmp;

	tmp = line;
	if (*line == '#')
		return (0);
	if (*tmp == '+')
		tmp++;
	if (ft_isall(tmp, &ft_isdigit, 0) == 0)
	{
		if (ft_atoi(line) == 123456789123)
			return (1);
		(*env).nbr_ant = ft_atoi(line);
	}
	if ((*env).nbr_ant == 0)
		(*env).nbr_ant = -1;
	if ((*env).nbr_ant == -1)
		return (1);
	return (0);
}
