/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_boudha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:05:42 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 23:06:50 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_fractale_burning_2(t_env env, t_value value)
{
	double		tmp;
	double		iteration;
	double		x;
	double		y;

	x = 0;
	y = 0;
	iteration = 0;
	while (iteration < env.it_max && ((x * x)
		+ (y * y)) < 4)
	{
		tmp = (x * x) - (y * y) + value.x;
		x = fabs(2 * x * y + value.y);
		y = fabs(tmp);
		iteration++;
	}
	return (iteration);
}

void	mlx_fractale_burning(t_env env, int x_start, t_lim envmore)
{
	double	iteration;
	t_value	value;
	int		x;
	int		y;

	iteration = 0;
	x = x_start;
	while (x < x_start + 250)
	{
		y = 0;
		while (y < 800)
		{
			value.x = (x / env.zoom) + env.value.x;
			value.y = (y / env.zoom) + env.value.z;
			value.z = x;
			value.w = y;
			iteration = mlx_fractale_burning_2(env, value);
			mlx_put_pixel_img(x - x_start, y, mlx_get_color(env,
						iteration), &envmore);
			y++;
		}
		x++;
	}
}
