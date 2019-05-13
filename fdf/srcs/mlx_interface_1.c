/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:02:02 by khtran            #+#    #+#             */
/*   Updated: 2017/12/07 06:17:42 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_square(t_pos start, int x, int y, t_lim win)
{
	int		x_bis;
	int		y_bis;

	x_bis = 0;
	y_bis = 0;
	while (y_bis <= y)
	{
		x_bis = 0;
		while (x_bis <= x)
		{
			mlx_pixel_put(win.mlx, win.win, start.x + x_bis,
					start.y + y_bis, start.color);
			x_bis++;
		}
		y_bis++;
	}
	return (0);
}

void	mlx_interface(t_lim win)
{
	mlx_square(mlx_pos_set(1200, 0, 0x00FFFACD), 240, 800, win);
	mlx_square(mlx_pos_set(1210, 40, 0x00EEE9BC), 220, 150, win);
	mlx_square(mlx_pos_set(1225, 159, 0x000000E0), 150, 6, win);
	mlx_square(mlx_pos_set(1225, 129, 0x0000E000), 150, 6, win);
	mlx_square(mlx_pos_set(1225, 99, 0x00E00000), 150, 6, win);
	mlx_square(mlx_pos_set(1225, 160, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1225, 130, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1225, 100, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1369, 159, 0x000000E0), 6, 6, win);
	mlx_square(mlx_pos_set(1369, 129, 0x0000E000), 6, 6, win);
	mlx_square(mlx_pos_set(1369, 99, 0x00E00000), 6, 6, win);
	mlx_square(mlx_pos_set(1225, 50, 0x00000000), 50, 30, win);
	mlx_square(mlx_pos_set(1226, 51, 0x00FF0000), 48, 28, win);
	mlx_square(mlx_pos_set(1310, 50, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1311, 51, 0x00FFFFFF), 28, 28, win);
	mlx_square(mlx_pos_set(1345, 50, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1346, 51, 0x00FFFFFF), 28, 28, win);
	mlx_square(mlx_pos_set(1390, 50, 0x00191970), 10, 124, win);
	mlx_square(mlx_pos_set(1391, 51, 0x00A0A0A0), 8, 123, win);
	mlx_square(mlx_pos_set(1390, 51 + 103, 0x00191970), 10, 10, win);
	mlx_square(mlx_pos_set(1410, 50, 0x00191970), 10, 124, win);
	mlx_square(mlx_pos_set(1411, 51, 0x00A0A0A0), 8, 123, win);
	mlx_square(mlx_pos_set(1410, 51 + 113, 0x00191970), 10, 10, win);
	mlx_interface_text(win);
}

int		mlx_interface_6(t_lim *param, int y, int x)
{
	if ((*param).trigger_7 == 1)
	{
		mlx_rgb_move_2(y, &param->level);
		mlx_square(mlx_pos_set(1410, 50, 0x00191970), 10, 124, *param);
		mlx_square(mlx_pos_set(1411, 51, 0x00A0A0A0), 8, 123, *param);
		mlx_square(mlx_pos_set(1410, 164 - (*param).level,
					0x00191970), 10, 10, *param);
	}
	if ((*param).trigger_9 == 1)
	{
		(*param).rot = 0.0001 * (x - (*param).x_start) + (*param).rot;
		(*param).camhigh = (*param).camhigh + (0.1 * (y - (*param).y_start));
		if ((*param).camhigh > 400)
			(*param).camhigh = 400;
		if ((*param).camhigh < 0)
			(*param).camhigh = 0;
		mlx_grid_open(*param);
	}
	return (0);
}

int		mlx_interface_5_bis(t_lim *param, int y, int x)
{
	if ((*param).trigger_5 == 0)
	{
		mlx_square(mlx_pos_set(1310, 50, 0x00000000), 30, 30, *param);
		mlx_square(mlx_pos_set(1311, 51, (*param).color_def), 28, 28, *param);
		mlx_square(mlx_pos_set(1345, 50, (*param).color_high), 30, 30, *param);
	}
	else if ((*param).trigger_5 == 1)
	{
		mlx_square(mlx_pos_set(1310, 50, (*param).color_def), 30, 30, *param);
		mlx_square(mlx_pos_set(1345, 50, 0x00000000), 30, 30, *param);
		mlx_square(mlx_pos_set(1346, 51, (*param).color_high), 28, 28, *param);
	}
	if ((*param).trigger_6 == 1)
	{
		mlx_rgb_move_2(y, &param->high);
		mlx_square(mlx_pos_set(1390, 50, 0x00191970), 10, 124, *param);
		mlx_square(mlx_pos_set(1391, 51, 0x00A0A0A0), 8, 123, *param);
		mlx_square(mlx_pos_set(1390, 164 - (*param).high,
					0x00191970), 10, 10, *param);
	}
	mlx_interface_6(param, y, x);
	mlx_rot_set(param);
	return (0);
}
