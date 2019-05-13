/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_event_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 05:05:11 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:09:28 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		visual_while(t_env *env)
{
	(*env).index += 1;
	if ((*env).index > 1 && (*env).t_pause == 0)
	{
		(*env).index = 0;
		visual_step(env->pile_a, env->pile_b, env);
	}
	return (0);
}

int		visual_click(int key, t_env *env)
{
	if (key == 35)
		(*env).t_pause = ((*env).t_pause + 1) % 2;
	if ((*env).t_pause == 1)
		mlx_string_put((*env).env.mlx, (*env).env.win, 10, 5, 0xFF0000,
				"Paused");
	return (0);
}

void	visual_event_all(t_env env)
{
	mlx_key_hook(env.env.win, visual_click, &env);
	mlx_loop_hook(env.env.mlx, visual_while, &env);
	mlx_loop(env.env.mlx);
}
