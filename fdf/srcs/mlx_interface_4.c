/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:45:26 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 22:14:41 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_reset_2(t_lim *param)
{
	(*param).trigger_10 = 0;
	mlx_square(mlx_pos_set(1366, 501, 0x00116611), 28, 28, *param);
	(*param).trigger_11 = 1;
	mlx_square(mlx_pos_set(1366, 541, 0x0011FF11), 28, 28, *param);
	mlx_square(mlx_pos_set(1366, 301, 0x0011FF11), 28, 28, (*param));
	mlx_square(mlx_pos_set(1366, 341, 0x00116611), 28, 28, (*param));
	mlx_square(mlx_pos_set(1366, 381, 0x00116611), 28, 28, (*param));
	(*param).trigger_8 = 1;
	mlx_square(mlx_pos_set(1226, 51, 0x00FF0000), 48, 28, *param);
	(*param).trigger_4 = 0;
	return (0);
}

void	mlx_reset(t_lim *win)
{
	(*win).rgb.r = 144;
	(*win).rgb.g = 144;
	(*win).rgb.b = 144;
	(*win).rgb2.r = 144;
	(*win).rgb2.g = 144;
	(*win).rgb2.b = 144;
	(*win).color_high = 0x00FFFFFF;
	(*win).color_def = 0x00FFFFFF;
	(*win).color_high = 0x00FFFFFF;
	mlx_color_resume(win);
	mlx_square(mlx_pos_set(1310, 50, 0x00000000), 30, 30, *win);
	mlx_square(mlx_pos_set(1311, 51, 0x00FFFFFF), 28, 28, *win);
	mlx_square(mlx_pos_set(1345, 50, 0x00000000), 30, 30, *win);
	mlx_square(mlx_pos_set(1346, 51, 0x00FFFFFF), 28, 28, *win);
	mlx_square(mlx_pos_set(1390, 50, 0x00191970), 10, 124, *win);
	mlx_square(mlx_pos_set(1391, 51, 0x00A0A0A0), 8, 123, *win);
	mlx_square(mlx_pos_set(1390, 51 + 103, 0x00191970), 10, 10, *win);
	mlx_square(mlx_pos_set(1410, 50, 0x00191970), 10, 124, *win);
	mlx_square(mlx_pos_set(1411, 51, 0x00A0A0A0), 8, 123, *win);
	mlx_square(mlx_pos_set(1410, 51 + 113, 0x00191970), 10, 10, *win);
	(*win).high = 10;
	(*win).rot = 0;
	(*win).camhigh = 200;
	(*win).prof = 5;
	mlx_reset_2(win);
}

void	mlx_interface_9(int x, int y, t_lim *param)
{
	if ((x >= 1365 && x <= 1365 + 30) && (*param).trigger_11 == 0
		&& (y >= 540 && y <= 570))
	{
		(*param).trigger_11 = 1;
		mlx_square(mlx_pos_set(1366, 541, 0x0011FF11), 28, 28, *param);
		mlx_grid_open(*param);
	}
	else if ((x >= 1365 && x <= 1365 + 30) && (*param).trigger_11 == 1
		&& (y >= 540 && y <= 570))
	{
		(*param).trigger_11 = 0;
		mlx_square(mlx_pos_set(1366, 541, 0x00116611), 28, 28, *param);
		mlx_grid_open(*param);
	}
}

void	mlx_pre_color(t_tab *var, t_lim fen)
{
	(*var).color = fen.color_def;
	if ((*var).high > ((double)fen.level / (double)114) * fen.size_z)
		(*var).color = fen.color_high;
}
