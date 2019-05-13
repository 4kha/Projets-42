/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:23:46 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 23:05:51 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_fractale_mandel_2(t_env env, t_value value)
{
	double		tmp;
	double		iteration;

	iteration = 0;
	while (iteration < env.it_max && ((value.x * value.x)
		+ (value.y * value.y)) < 12)
	{
		tmp = value.x;
		value.x = (value.x * value.x) - (value.y * value.y) + value.z;
		value.y = (2 * value.y * tmp) + value.w;
		iteration++;
	}
	return (iteration);
}

void	mlx_fractale_mandel(t_env env, int x_start, t_lim envmore)
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
			value.z = (x / env.zoom) + env.value.x;
			value.w = (y / env.zoom) + env.value.z;
			value.x = 0;
			value.y = 0;
			iteration = mlx_fractale_mandel_2(env, value);
			mlx_put_pixel_img(x - x_start, y, mlx_get_color(env,
						iteration), &envmore);
			y++;
		}
		x++;
	}
}
