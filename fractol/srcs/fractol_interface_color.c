/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_interface_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:51:09 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 17:12:31 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_color_resume(t_env *param)
{
	t_rgb	tmp;

	tmp = (*param).stock;
	(*param).stock = (*param).rgb;
	(*param).rgb = tmp;
	mlx_square(mlx_pos_set(1025, 325, 0x00A0A0A0), 150, 4, (*param).env);
	mlx_square(mlx_pos_set(1025 + (*param).rgb.r,
					324, 0x00E00000), 6, 6, (*param).env);
	mlx_square(mlx_pos_set(1025, 355, 0x00A0A0A0), 150, 4, (*param).env);
	mlx_square(mlx_pos_set(1025 + (*param).rgb.g,
					324 + 30, 0x0000E000), 6, 6, (*param).env);
	mlx_square(mlx_pos_set(1025, 385, 0x00A0A0A0), 150, 4, (*param).env);
	mlx_square(mlx_pos_set(1025 + (*param).rgb.b,
					324 + 60, 0x000000E0), 6, 6, (*param).env);
	return (0);
}

int		mlx_interface_color_click_2(int x, int y, t_env *p)
{
	if ((*p).t.trigger[6] == 1 && x >= 1110 && x <= 1110 + 30
			&& y >= 275 && y <= 275 + 30)
	{
		mlx_square(mlx_pos_set(1110, 275, 0x00000000), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1111, 276, (*p).env.c_dep), 28, 28, (*p).env);
		mlx_square(mlx_pos_set(1145, 275, (*p).env.c_end), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1146, 276, (*p).env.c_end), 28, 28, (*p).env);
		(*p).t.trigger[6] = 0;
		mlx_color_resume(p);
	}
	else if ((*p).t.trigger[6] == 0 && x >= 1145 && x <= 1145 + 30
			&& y >= 275 && y <= 275 + 30)
	{
		mlx_square(mlx_pos_set(1110, 275, (*p).env.c_dep), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1111, 276, (*p).env.c_dep), 28, 28, (*p).env);
		mlx_square(mlx_pos_set(1145, 275, 0x00000000), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1146, 276, (*p).env.c_end), 28, 28, (*p).env);
		(*p).t.trigger[6] = 1;
		mlx_color_resume(p);
	}
	return (0);
}

void	mlx_interface_color_while(int x, t_env *param)
{
	if ((*param).t.trigger[3] == 1)
	{
		mlx_rgb_move(x, &param->rgb.r);
		mlx_square(mlx_pos_set(1025, 325, 0x00A0A0A0), 150, 4, (*param).env);
		mlx_square(mlx_pos_set(1025 + (*param).rgb.r,
					324, 0x00E00000), 6, 6, (*param).env);
	}
	if ((*param).t.trigger[4] == 1)
	{
		mlx_rgb_move(x, &param->rgb.g);
		mlx_square(mlx_pos_set(1025, 355, 0x00A0A0A0), 150, 4, (*param).env);
		mlx_square(mlx_pos_set(1025 + (*param).rgb.g,
					354, 0x0000E000), 6, 6, (*param).env);
	}
	if ((*param).t.trigger[5] == 1)
	{
		mlx_rgb_move(x, &param->rgb.b);
		mlx_square(mlx_pos_set(1025, 385, 0x00A0A0A0), 150, 4, (*param).env);
		mlx_square(mlx_pos_set(1025 + (*param).rgb.b,
					384, 0x000000E0), 6, 6, (*param).env);
	}
}

int		mlx_interface_color_release(t_env *p)
{
	if ((*p).t.trigger[6] == 0)
		(*p).env.c_dep = (((*p).rgb.r * 255 / 144) * 256 * 256)
			+ (((*p).rgb.g * 255 / 144) * 256)
			+ ((*p).rgb.b * 255 / 144);
	else
		(*p).env.c_end = (((*p).rgb.r * 255 / 144) * 256 * 256)
			+ (((*p).rgb.g * 255 / 144) * 256)
			+ ((*p).rgb.b * 255 / 144);
	if ((*p).t.trigger[6] == 0)
	{
		mlx_square(mlx_pos_set(1110, 275, 0x00000000), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1111, 276, (*p).env.c_dep), 28, 28, (*p).env);
		mlx_square(mlx_pos_set(1145, 275, (*p).env.c_end), 30, 30, (*p).env);
	}
	else if ((*p).t.trigger[6] == 1)
	{
		mlx_square(mlx_pos_set(1110, 275, (*p).env.c_dep), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1145, 275, 0x00000000), 30, 30, (*p).env);
		mlx_square(mlx_pos_set(1146, 276, (*p).env.c_end), 28, 28, (*p).env);
	}
	if ((*p).t.trigger[1] == 1)
		mlx_calculate(*p);
	return (0);
}

void	mlx_interface_color_click(int button, int x, int y, t_env *param)
{
	if (button == 1 && x >= 1025 && x <= 1175
			&& y >= 324 && y <= 330)
		(*param).t.trigger[3] = 1;
	if (button == 1 && x >= 1025 && x <= 1175
			&& y >= 354 && y <= 360)
		(*param).t.trigger[4] = 1;
	if (button == 1 && x >= 1025 && x <= 1175
			&& y >= 384 && y <= 390)
		(*param).t.trigger[5] = 1;
	if ((x >= 1026 && x <= 1026 + 48 && y >= 275 && y <= 275 + 30)
			&& (*param).t.trigger[1] == 0)
	{
		mlx_square(mlx_pos_set(1026, 276, 0x0000FF00), 48, 28, (*param).env);
		(*param).t.trigger[1] = 1;
		mlx_calculate(*param);
	}
	else if ((x >= 1026 && x <= 1026 + 48 && y >= 275 && y <= 275 + 30)
			&& (*param).t.trigger[1] == 1)
	{
		mlx_square(mlx_pos_set(1026, 276, 0x00FF0000), 48, 28, (*param).env);
		(*param).t.trigger[1] = 0;
		mlx_calculate(*param);
	}
	mlx_interface_color_click_2(x, y, param);
}
