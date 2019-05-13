/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:15:59 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 20:46:44 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_colorset(int color_dep, int color_end, double rapport)
{
	t_rgb	dep;
	t_rgb	end;
	int		result;

	dep.b = (color_dep / 256) / 256;
	dep.g = (color_dep - (dep.b * 256 * 256)) / 256;
	dep.r = (color_dep - (dep.b * 256 * 256 + dep.g * 256));
	end.b = (color_end / 256) / 256;
	end.g = (color_end - (end.b * 256 * 256)) / 256;
	end.r = (color_end - (end.b * 256 * 256 + end.g * 256));
	dep.r = dep.r - ((dep.r - end.r) * rapport);
	dep.g = dep.g - ((dep.g - end.g) * rapport);
	dep.b = dep.b - ((dep.b - end.b) * rapport);
	result = (dep.b * 256 * 256) + (dep.g * 256) + (dep.r);
	return (result);
}

void	party_parrot_of_doom(t_env *parrot)
{
	(*parrot).env.c_end += 101010;
	if ((*parrot).env.c_end >= 0x00FFFFFF)
		(*parrot).env.c_end -= 0x00FFFFFF;
	(*parrot).env.c_dep -= 120011;
	if ((*parrot).env.c_dep <= 0x00000000)
		(*parrot).env.c_dep += 0x00FFFFFF;
	return ;
}

int		mlx_get_color_tapis(t_env env, int iteration)
{
	int		color;

	if (iteration == env.it_max && (env.t.trigger[1] == 0
				&& env.t.trigger[7] == 0))
		return (0x00FFFF00);
	if (env.t.trigger[1] == 1 || env.t.trigger[7] == 1)
	{
		if (iteration == env.it_max)
			return (env.env.c_dep);
		color = env.env.c_end;
		return (color);
	}
	else if (env.t.trigger[1] == 0)
	{
		return (0x00000000);
	}
	return (0);
}

int		mlx_get_color(t_env env, int iteration)
{
	int		color;

	if (iteration == env.it_max)
		return (0x00000000);
	if (env.t.trigger[1] == 1 || env.t.trigger[7] == 1)
	{
		color = mlx_colorset(env.env.c_dep, env.env.c_end,
				((double)iteration / env.it_max));
		return (color);
	}
	else if (env.t.trigger[1] == 0)
	{
		return (mlx_color_set(250, 255 - (((double)iteration / env.it_max)
					* 255), ((double)iteration / env.it_max) * 255));
	}
	return (0);
}
