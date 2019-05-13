/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:14:39 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 22:14:29 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_interface_3(int button, int x, int y, t_lim *param)
{
	(*param).trigger_1 = 0;
	(*param).trigger_2 = 0;
	(*param).trigger_3 = 0;
	(*param).trigger_7 = 0;
	(*param).trigger_9 = 0;
	(void)x;
	(void)y;
	if ((*param).trigger_6 == 1 && button == 1)
		mlx_grid_open(*param);
	if ((*param).trigger_5 == 0)
	{
		(*param).color_def = (((*param).rgb.r * 255 / 144) * 256 * 256)
			+ (((*param).rgb.g * 255 / 144) * 256)
			+ ((*param).rgb.b * 255 / 144);
	}
	else
	{
		(*param).color_high = (((*param).rgb.r * 255 / 144) * 256 * 256)
			+ (((*param).rgb.g * 255 / 144) * 256)
			+ ((*param).rgb.b * 255 / 144);
	}
	if ((*param).trigger_4 == 1 && (*param).trigger_6 == 0)
		mlx_grid_open(*param);
	(*param).trigger_6 = 0;
	return (0);
}

int		mlx_interface_all(t_lim *win)
{
	(*win).color_def = 0x00FFFFFF;
	(*win).color_high = 0x00FFFFFF;
	(*win).block = 99;
	mlx_rgb_set(win, 144, 144, 144);
	mlx_interface(*win);
	(*win).trigger_8 = 1;
	(*win).trigger_4 = 0;
	(*win).trigger_5 = 0;
	(*win).trigger_11 = 1;
	(*win).prof = 5;
	(*win).high = 10;
	mlx_grid_open(*win);
	mlx_hook((*win).win, 5, 0, mlx_interface_3, win);
	mlx_mouse_hook((*win).win, mlx_interface_2, win);
	mlx_hook((*win).win, 6, 0, mlx_interface_1, win);
	mlx_key_hook((*win).win, ft_exit, win);
	return (0);
}

int		mlx_interface_7(int x, int y, t_lim *win)
{
	if ((x >= 1365 && x <= 1365 + 30 && y >= 300 && y <= 300 + 30)
			&& (*win).trigger_8 != 1)
	{
		mlx_square(mlx_pos_set(1366, 301, 0x0011FF11), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 341, 0x00116611), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 381, 0x00116611), 28, 28, (*win));
		(*win).trigger_8 = 1;
	}
	else if ((x >= 1365 && x <= 1365 + 30 && y >= 340 && y <= 340 + 30)
			&& (*win).trigger_8 != 2)
	{
		mlx_square(mlx_pos_set(1366, 301, 0x00116611), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 341, 0x0011FF11), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 381, 0x00116611), 28, 28, (*win));
		(*win).trigger_8 = 2;
	}
	else if ((x >= 1365 && x <= 1365 + 30 && y >= 380 && y <= 380 + 30)
			&& (*win).trigger_8 != 3)
	{
		mlx_square(mlx_pos_set(1366, 301, 0x00116611), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 341, 0x00116611), 28, 28, (*win));
		mlx_square(mlx_pos_set(1366, 381, 0x0011FF11), 28, 28, (*win));
		(*win).trigger_8 = 3;
	}
	return (0);
}

void	mlx_interface_text(t_lim win)
{
	mlx_square(mlx_pos_set(1210, 235, 0x00EEE9BC), 220, 200, win);
	mlx_square(mlx_pos_set(1210, 485, 0x00EEE9BC), 220, 185, win);
	mlx_string_put(win.mlx, win.win, 1300, 10, 0x00000000, "Fdf");
	mlx_square(mlx_pos_set(1210, 730, 0x00000000), 220, 60, win);
	mlx_string_put(win.mlx, win.win, 1255, 250, 0xF0111111, "Projection :");
	mlx_string_put(win.mlx, win.win, 1245, 305, 0xF0111111, "Isometrique");
	mlx_square(mlx_pos_set(1365, 300, 0x00000000), 30, 30, win);
	mlx_string_put(win.mlx, win.win, 1245, 345, 0xF0111111, "Conique");
	mlx_square(mlx_pos_set(1365, 340, 0x00000000), 30, 30, win);
	mlx_string_put(win.mlx, win.win, 1245, 385, 0xF0111111, "Parallele");
	mlx_square(mlx_pos_set(1365, 380, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1366, 301, 0x0011FF11), 28, 28, win);
	mlx_square(mlx_pos_set(1366, 341, 0x00116611), 28, 28, win);
	mlx_square(mlx_pos_set(1366, 381, 0x00116611), 28, 28, win);
	mlx_square(mlx_pos_set(1211, 731, 0x00FF6666), 218, 58, win);
	mlx_square(mlx_pos_set(1210, 680, 0x00000000), 220, 40, win);
	mlx_square(mlx_pos_set(1211, 681, 0x0066FFAA), 218, 38, win);
	mlx_string_put(win.mlx, win.win, 1297, 690, 0x0000A000, "RESET");
	mlx_string_put(win.mlx, win.win, 1302, 750, 0x00A00000, "EXIT");
	mlx_string_put(win.mlx, win.win, 1245, 505, 0xF0111111, "Base");
	mlx_square(mlx_pos_set(1365, 500, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1366, 501, 0x00116611), 28, 28, win);
	mlx_string_put(win.mlx, win.win, 1245, 545, 0xF0111111, "Buffer-Z");
	mlx_square(mlx_pos_set(1365, 540, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1366, 541, 0x0011FF11), 28, 28, win);
}

void	mlx_interface_8(int x, int y, t_lim *param)
{
	if ((x >= 1365 && x <= 1365 + 30) && (*param).trigger_10 == 0
		&& (y >= 500 && y <= 530))
	{
		(*param).trigger_10 = 1;
		mlx_square(mlx_pos_set(1366, 501, 0x0011FF11), 28, 28, *param);
		mlx_grid_open(*param);
	}
	else if ((x >= 1365 && x <= 1365 + 30) && (*param).trigger_10 == 1
		&& (y >= 500 && y <= 530))
	{
		(*param).trigger_10 = 0;
		mlx_square(mlx_pos_set(1366, 501, 0x00116611), 28, 28, *param);
		mlx_grid_open(*param);
	}
	mlx_interface_9(x, y, param);
}
