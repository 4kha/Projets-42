/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:21:11 by khtran            #+#    #+#             */
/*   Updated: 2018/06/24 01:44:59 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_set_env(t_env *env)
{
	(*env).nbr_ant = -1;
	(*env).trigger = 0;
	(*env).m_start = NULL;
	(*env).m_end = NULL;
	(*env).mode = 0;
	(*env).room = NULL;
	(*env).cur_sol = 0;
	(*env).max_sol = MAX_SOL;
	(*env).b_room = BONUS_R;
	(*env).b_way = BONUS_W;
	(*env).b_stats = BONUS_S;
}

int		lem_in_parser_all(t_env *env, char **save, char **line)
{
	int		ret;

	while ((ret = get_next_line(0, line)) == 1)
	{
		if (env->nbr_ant == -1)
		{
			if (lem_in_nbrant(*line, env) == 1)
				break ;
		}
		else
		{
			if (lem_in_parser(*line, env) == 1)
			{
				free(*line);
				break ;
			}
		}
		*save = ft_strjoin_and_free(*save, *line);
		free(*line);
		*line = ft_strdup("\n");
		*save = ft_strjoin_and_free(*save, *line);
		free(*line);
	}
	return (ret);
}

int		lem_in_bonus(t_env *env, int ac, char **av)
{
	int		index;

	index = 1;
	while (index < ac)
	{
		if (ft_strcmp(av[index], "-r") == 0)
			(*env).b_room = 1;
		else if (ft_strcmp(av[index], "-w") == 0)
			(*env).b_way = 1;
		else if (ft_strcmp(av[index], "-s") == 0)
			(*env).b_stats = 1;
		else if (ft_strncmp(av[index], "-m", 2) == 0)
			(*env).max_sol = ft_atoi(&av[index][2]);
		else
		{
			ft_putstr("usage : ./lem_in -[r/w/s/m[value]]\n");
			return (1);
		}
		index++;
	}
	if ((*env).max_sol == 0)
		(*env).max_sol = -1;
	return (0);
}

int		main(int ac, char *av[])
{
	char	*line;
	char	*save;
	t_env	env;

	save = NULL;
	lem_in_set_env(&env);
	if (lem_in_bonus(&env, ac, av))
		return (0);
	if (lem_in_parser_all(&env, &save, &line) == 0 && line != NULL)
		free(line);
	env.input = save;
	lem_in_solve(&env);
	free(save);
	return (0);
}
