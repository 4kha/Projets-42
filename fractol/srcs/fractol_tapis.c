/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tapis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:01:56 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 23:05:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_fractale_tapis_2(t_env env, t_value value)
{
	double		iteration;
	int			x;
	int			y;

	x = (int)value.x;
	y = (int)value.y;
	iteration = 0;
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	while (iteration < env.it_max
			&& !(((x / 3) % 3) == 1 && ((y / 3) % 3) == 1))
	{
		x = (x / 3);
		y = (y / 3);
		iteration++;
	}
	return (iteration);
}

void	mlx_fractale_tapis(t_env env, int x_start, t_lim envmore)
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
			iteration = mlx_fractale_tapis_2(env, value);
			mlx_put_pixel_img(x - x_start, y, mlx_get_color_tapis(env,
						iteration), &envmore);
			y++;
		}
		x++;
	}
}
