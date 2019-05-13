/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:20:34 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 17:53:25 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_value	mlx_value_set(double x1, double x2, double x3, double x4)
{
	t_value	tmp;

	tmp.x = x1;
	tmp.y = x2;
	tmp.z = x3;
	tmp.w = x4;
	return (tmp);
}

void	mlx_image_set(t_env *env)
{
	int		size;
	int		envs;

	(*env).env.img.img = mlx_new_image((*env).env.mlx, 250, 800);
	(*env).env.img.src = (int*)mlx_get_data_addr((*env).env.img.img, &size,
			&(*env).env.img.line_x, &envs);
	(*env).env.img.line_x = (*env).env.img.line_x / 4;
	(*env).env.img.line_y = 800;
	(*env).env2.img.img = mlx_new_image((*env).env.mlx, 250, 800);
	(*env).env2.img.src = (int*)mlx_get_data_addr((*env).env2.img.img, &size,
			&(*env).env2.img.line_x, &envs);
	(*env).env2.img.line_x = (*env).env2.img.line_x / 4;
	(*env).env2.img.line_y = 800;
	(*env).env3.img.img = mlx_new_image((*env).env.mlx, 250, 800);
	(*env).env3.img.src = (int*)mlx_get_data_addr((*env).env3.img.img, &size,
			&(*env).env3.img.line_x, &envs);
	(*env).env3.img.line_x = (*env).env3.img.line_x / 4;
	(*env).env3.img.line_y = 800;
	(*env).env4.img.img = mlx_new_image((*env).env.mlx, 250, 800);
	(*env).env4.img.src = (int*)mlx_get_data_addr((*env).env4.img.img, &size,
			&(*env).env4.img.line_x, &envs);
	(*env).env4.img.line_x = (*env).env4.img.line_x / 4;
	(*env).env4.img.line_y = 800;
	(*env).zoom = 300;
	(*env).it_max = 50;
}

void	mlx_param_set(t_env *env)
{
	(*env).env.c_dep = 0x00FFFFFF;
	(*env).env.c_end = 0x00FFFFFF;
	(*env).rgb.r = 144;
	(*env).rgb.g = 144;
	(*env).rgb.b = 144;
	(*env).stock.r = 144;
	(*env).stock.g = 144;
	(*env).stock.b = 144;
	(*env).zoom_inc = 1.1;
}

void	mlx_rgb_move(int x, int *test)
{
	x = x - 1025;
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

void	mlx_fractale_set(t_env *param)
{
	if ((*param).t.trigger[2] == 0)
	{
		mlx_square(mlx_pos_set(1021, 51, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win, 1025, 65, 0x00116677,
			"Mandelbr.");
	}
	if ((*param).t.trigger[2] == 1)
	{
		mlx_square(mlx_pos_set(1126, 51, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1147, 65, 0x00116677, "Julia");
	}
	if ((*param).t.trigger[2] == 2)
	{
		mlx_square(mlx_pos_set(1021, 116, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1025, 130, 0x00116677, "BurnShip.");
	}
}
