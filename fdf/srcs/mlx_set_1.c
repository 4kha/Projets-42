/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:06:44 by khtran            #+#    #+#             */
/*   Updated: 2017/12/07 11:05:58 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_rgb_move(int x, int *test)
{
	x = x - 1225;
	*test = x;
	if ((*test) > 144)
	{
		*test = 144;
	}
	if ((*test) < 0)
	{
		*test = 0;
	}
}

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

void	mlx_rgb_move_2(int y, int *test)
{
	y = 114 + 50 - y;
	*test = y;
	if ((*test) > 114)
	{
		*test = 114;
	}
	if ((*test) < 0)
	{
		*test = 0;
	}
}

int		mlx_rot_set(t_lim *data)
{
	if ((*data).trigger_8 == 3)
	{
		if ((*data).rot * 100 > 200)
			(*data).rot = 2.00;
		if ((*data).rot * 100 < -350)
			(*data).rot = -3.50;
	}
	if ((*data).trigger_8 == 2)
	{
		if ((*data).rot * 100 > 400)
			(*data).rot = 4.00;
		if ((*data).rot * 100 < -400)
			(*data).rot = -4.00;
	}
	return (0);
}

int		mlx_trigger_9(t_lim *param, int x, int y)
{
	(*param).trigger_9 = 1;
	(*param).x_start = x;
	(*param).y_start = y;
	return (0);
}
