/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:21:11 by khtran            #+#    #+#             */
/*   Updated: 2018/05/09 05:33:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_set_env(t_env *env)
{
	(*env).nbr_ant = -1;
	(*env).t_start = 0;
	(*env).t_end = 0;
}

void	lem_in_build(char *line, t_env *env)
{
	if (line)
}

int		main(int ac, char *av[])
{
	int		ret;
	char	*line;
	t_env	env;

	lem_in_set_env(&env);
	while ((ret = get_next_line(2, &line)) == 1)
	{
		lem_in_build(line, &env);
		free(line);
	}
	return (0);
}
