/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_click.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:59:08 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 22:46:01 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_interaction5_click(int button, t_pos x_y, t_env *param)
{
	if (button == 1 && x_y.x >= 1020 && x_y.x <= 1020 + 95
			&& x_y.y >= 50 && x_y.y <= 50 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 0;
		(*param).value = mlx_value_set(-2.1, 0.6, -1.3, 1.2);
		(*param).zoom = 300;
		mlx_square(mlx_pos_set(1021, 51, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1025, 65, 0x00116677, "Mandelbr.");
		mlx_calculate(*param);
	}
	if (button == 1 && x_y.x >= 1125 && x_y.x <= 1125 + 95
			&& x_y.y >= 50 && x_y.y <= 50 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 1;
		(*param).value = mlx_value_set(-1.7, 0.3, -1.2, 1.2);
		(*param).zoom = 300;
		mlx_square(mlx_pos_set(1126, 51, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1147, 65, 0x00116677, "Julia");
		mlx_calculate(*param);
	}
}

void	mlx_interaction4_click(int button, t_pos x_y, t_env *param)
{
	if (button == 1 && x_y.x >= 1020 && x_y.x <= 1020 + 95
			&& x_y.y >= 115 && x_y.y <= 115 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 2;
		(*param).value = mlx_value_set(-1.2, 1, -1.8, 1.2);
		(*param).zoom = 300;
		mlx_square(mlx_pos_set(1021, 116, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1025, 130, 0x00116677, "BurnShip.");
		mlx_calculate(*param);
	}
	if (button == 1 && x_y.x >= 1125 && x_y.x <= 1125 + 95
			&& x_y.y >= 115 && x_y.y <= 115 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 3;
		(*param).value = mlx_value_set(-3.0, 1, -3, 1);
		(*param).zoom = 1;
		mlx_square(mlx_pos_set(1126, 116, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1147, 130, 0x00116677, "Tapis");
		mlx_calculate(*param);
	}
}

void	mlx_interaction3_click(int button, t_pos x_y, t_env *param)
{
	if (button == 1 && x_y.x >= 1020 && x_y.x <= 1020 + 95
			&& x_y.y >= 180 && x_y.y <= 180 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 4;
		(*param).value = mlx_value_set(-3.2, -0.4, -2.0, 1.2);
		(*param).zoom = 200;
		mlx_square(mlx_pos_set(1021, 181, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1032, 195, 0x00116677, "Custom1");
		mlx_calculate(*param);
	}
	if (button == 1 && x_y.x >= 1125 && x_y.x <= 1125 + 95
			&& x_y.y >= 180 && x_y.y <= 180 + 50)
	{
		mlx_interface_choice(param);
		(*param).t.trigger[2] = 5;
		(*param).value = mlx_value_set(-2.7, 1, -1.9, 1.2);
		(*param).zoom = 200;
		mlx_square(mlx_pos_set(1126, 181, 0x0011FF11), 93, 48, (*param).env);
		mlx_string_put((*param).env.mlx, (*param).env.win,
				1139, 195, 0x00116677, "Custom2");
		mlx_calculate(*param);
	}
}

void	mlx_interaction2_click(int button, t_pos mid, t_pos x_y, t_env *param)
{
	if (button == 4 && x_y.x <= 1000)
	{
		(*param).zoom *= (*param).zoom_inc;
		(*param).value.x = ((*param).value.x + (0.0025
					/ ((*param).zoom / 300)) * (mid.x) * ((*param).zoom_inc));
		(*param).value.z = ((*param).value.z + (0.0025
					/ ((*param).zoom / 300)) * (mid.y) * ((*param).zoom_inc));
		(*param).value.y = ((*param).value.y + (0.0025
					/ ((*param).zoom / 300)) * (mid.x) * ((*param).zoom_inc));
		(*param).value.w = ((*param).value.w + (0.0025
					/ ((*param).zoom / 300)) * (mid.y) * ((*param).zoom_inc));
		mlx_calculate(*param);
	}
	if (button == 1 && x_y.x <= 1000)
	{
		(*param).click = mlx_pos_set(x_y.x, x_y.y, 0);
		(*param).t.trigger[0] = 1;
	}
	if (button == 1 && x_y.x >= 1011 && x_y.x <= 1011 + 218
			&& x_y.y >= 731 && x_y.y <= 731 + 58)
	{
		exit(0);
	}
	mlx_interaction6_click(button, x_y.x, x_y.y, param);
}

int		mlx_interaction1_click(int button, int x, int y, t_env *param)
{
	t_pos	mid;
	t_pos	x_y;

	x_y = mlx_pos_set(x, y, 0);
	mid = mlx_pos_set((x - 500) * (*param).zoom_inc, (y - 400) *
			(*param).zoom_inc, 0);
	if (button == 5 && x <= 1000)
	{
		(*param).zoom /= (*param).zoom_inc;
		(*param).value.x = ((*param).value.x - (0.0025
					/ ((*param).zoom / 300)) * (mid.x) * ((*param).zoom_inc));
		(*param).value.z = ((*param).value.z - (0.0025
					/ ((*param).zoom / 300)) * (mid.y) * ((*param).zoom_inc));
		(*param).value.y = ((*param).value.y - (0.0025
					/ ((*param).zoom / 300)) * (mid.x) * ((*param).zoom_inc));
		(*param).value.w = ((*param).value.w - (0.0025
					/ ((*param).zoom / 300)) * (mid.y) * ((*param).zoom_inc));
		mlx_calculate(*param);
	}
	mlx_interaction2_click(button, mid, x_y, param);
	mlx_interaction3_click(button, x_y, param);
	mlx_interaction4_click(button, x_y, param);
	mlx_interaction5_click(button, x_y, param);
	mlx_interface_color_click(button, x, y, param);
	return (0);
}
