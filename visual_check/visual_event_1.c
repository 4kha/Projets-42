/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_event_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 05:05:11 by khtran            #+#    #+#             */
/*   Updated: 2018/05/03 23:21:50 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../visual.h"

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
//	ft_putnbr(key);
	if (key == 35)
	{
		if ((*env).t_pause == 1)
			(*env).t_pause = 0;
		else
			(*env).t_pause = 1;
	}
	return (0);
}

void	visual_event_all(t_env env)
{
	mlx_key_hook(env.env.win, visual_click, &env);
	mlx_loop_hook(env.env.mlx, visual_while, &env);
	mlx_loop(env.env.mlx);
}
