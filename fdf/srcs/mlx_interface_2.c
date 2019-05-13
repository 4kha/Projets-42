/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:09:05 by khtran            #+#    #+#             */
/*   Updated: 2017/12/16 15:32:11 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mlx_interface_1(int x, int y, t_lim *param)
{
	(*param).x = x;
	(*param).y = y;
	if ((*param).trigger_1 == 1)
	{
		mlx_rgb_move(x, &param->rgb.r);
		mlx_square(mlx_pos_set(1225, 100, 0x00A0A0A0), 150, 4, *param);
		mlx_square(mlx_pos_set(1225 + (*param).rgb.r,
					(*param).block, 0x00E00000), 6, 6, *param);
	}
	if ((*param).trigger_2 == 1)
	{
		mlx_rgb_move(x, &param->rgb.g);
		mlx_square(mlx_pos_set(1225, 130, 0x00A0A0A0), 150, 4, *param);
		mlx_square(mlx_pos_set(1225 + (*param).rgb.g,
					(*param).block + 30, 0x0000E000), 6, 6, *param);
	}
	if ((*param).trigger_3 == 1)
	{
		mlx_rgb_move(x, &param->rgb.b);
		mlx_square(mlx_pos_set(1225, 160, 0x00A0A0A0), 150, 4, *param);
		mlx_square(mlx_pos_set(1225 + (*param).rgb.b,
					(*param).block + 60, 0x000000E0), 6, 6, *param);
	}
	mlx_interface_5_bis(param, y, x);
	return (0);
}

int			mlx_color_resume(t_lim *param)
{
	t_rgb	tmp;

	tmp = (*param).rgb2;
	(*param).rgb2 = (*param).rgb;
	(*param).rgb = tmp;
	mlx_square(mlx_pos_set(1225, 100, 0x00A0A0A0), 150, 4, *param);
	mlx_square(mlx_pos_set(1225 + (*param).rgb.r,
				(*param).block, 0x00E00000), 6, 6, *param);
	mlx_square(mlx_pos_set(1225, 130, 0x00A0A0A0), 150, 4, *param);
	mlx_square(mlx_pos_set(1225 + (*param).rgb.g,
					(*param).block + 30, 0x0000E000), 6, 6, *param);
	mlx_square(mlx_pos_set(1225, 160, 0x00A0A0A0), 150, 4, *param);
	mlx_square(mlx_pos_set(1225 + (*param).rgb.b,
					(*param).block + 60, 0x000000E0), 6, 6, *param);
	return (0);
}

int			mlx_interface_5(int x, int y, t_lim *param)
{
	if ((*param).trigger_5 == 1 && x >= 1310 && x <= 1310 + 30
			&& y >= 50 && y <= 50 + 30)
	{
		mlx_square(mlx_pos_set(1310, 50, 0x00000000), 30, 30, *param);
		mlx_square(mlx_pos_set(1311, 51, (*param).color_def), 28, 28, *param);
		mlx_square(mlx_pos_set(1345, 50, (*param).color_high), 30, 30, *param);
		mlx_square(mlx_pos_set(1346, 51, (*param).color_high), 28, 28, *param);
		(*param).trigger_5 = 0;
		mlx_color_resume(param);
	}
	else if ((*param).trigger_5 == 0 && x >= 1345 && x <= 1345 + 30
			&& y >= 50 && y <= 50 + 30)
	{
		mlx_square(mlx_pos_set(1310, 50, (*param).color_def), 30, 30, *param);
		mlx_square(mlx_pos_set(1311, 51, (*param).color_def), 28, 28, *param);
		mlx_square(mlx_pos_set(1345, 50, 0x00000000), 30, 30, *param);
		mlx_square(mlx_pos_set(1346, 51, (*param).color_high), 28, 28, *param);
		(*param).trigger_5 = 1;
		mlx_color_resume(param);
	}
	return (0);
}

int			mlx_interface_4(int x, int y, t_lim *param)
{
	if ((x >= 0 && x <= 1200 && y >= 0 && y <= 800) && (*param).trigger_9 == 0)
		mlx_trigger_9(param, x, y);
	if ((x >= 1226 && x <= 1226 + 48 && y >= 51 && y <= 51 + 28)
			&& (*param).trigger_4 == 0)
	{
		mlx_square(mlx_pos_set(1226, 51, 0x0000FF00), 48, 28, *param);
		(*param).trigger_4 = 1;
	}
	else if ((x >= 1226 && x <= 1226 + 48 && y >= 51 && y <= 51 + 28)
			&& (*param).trigger_4 == 1)
	{
		mlx_square(mlx_pos_set(1226, 51, 0x00FF0000), 48, 28, *param);
		(*param).trigger_4 = 0;
		mlx_grid_open(*param);
	}
	if (x >= 1390 && x <= 1400 && y >= 50 && y <= 50 + 124)
		(*param).trigger_6 = 1;
	if (x >= 1410 && x <= 1420 && y >= 50 && y <= 50 + 124)
		(*param).trigger_7 = 1;
	mlx_interface_5(x, y, param);
	mlx_interface_7(x, y, param);
	mlx_grid_open(*param);
	return (0);
}

int			mlx_interface_2(int button, int x, int y, t_lim *param)
{
	if ((x >= 1225 && x <= 1375) && button == 1
		&& (y >= (*param).block && y <= 105))
		(*param).trigger_1 = 1;
	if ((x >= 1225 && x <= 1375) && button == 1
		&& (y >= (*param).block + 30 && y <= 135))
		(*param).trigger_2 = 1;
	if ((x >= 1225 && x <= 1375) && button == 1
		&& (y >= (*param).block + 60 && y <= 165))
		(*param).trigger_3 = 1;
	if ((x >= 1210 && x <= 1210 + 220) && (y >= 730 && y <= 730 + 60))
		exit(0);
	if (x >= 1210 && x <= 1210 + 220 && y >= 680 && y <= 680 + 40)
		mlx_reset(param);
	mlx_interface_4(x, y, param);
	mlx_interface_8(x, y, param);
	return (0);
}
