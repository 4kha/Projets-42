/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_interface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 06:49:38 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 17:51:49 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_interface_choice(t_env *env)
{
	mlx_square(mlx_pos_set(1020, 50, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1125, 50, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1020, 115, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1125, 115, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1020, 180, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1125, 180, 0x00000000), 95, 50, (*env).env);
	mlx_square(mlx_pos_set(1021, 51, 0x00116611), 93, 48, (*env).env);
	mlx_square(mlx_pos_set(1126, 51, 0x00116611), 93, 48, (*env).env);
	mlx_square(mlx_pos_set(1021, 116, 0x00116611), 93, 48, (*env).env);
	mlx_square(mlx_pos_set(1126, 116, 0x00116611), 93, 48, (*env).env);
	mlx_square(mlx_pos_set(1021, 181, 0x00116611), 93, 48, (*env).env);
	mlx_square(mlx_pos_set(1126, 181, 0x00116611), 93, 48, (*env).env);
	mlx_string_put((*env).env.mlx, (*env).env.win, 1025, 65,
			0x0011BB77, "Mandelbr.");
	mlx_string_put((*env).env.mlx, (*env).env.win, 1147, 65,
			0x0011BB77, "Julia");
	mlx_string_put((*env).env.mlx, (*env).env.win, 1025, 130,
			0x0011BB77, "BurnShip.");
	mlx_string_put((*env).env.mlx, (*env).env.win, 1147, 130,
			0x0011BB77, "Tapis");
	mlx_string_put((*env).env.mlx, (*env).env.win, 1032, 195,
			0x0011BB77, "Custom1");
	mlx_string_put((*env).env.mlx, (*env).env.win, 1139, 195,
			0x0011BB77, "Custom2");
}

void	mlx_interface_2(t_env *env)
{
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 440, 0x00A00000, "Iteration :");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 465, 0x00A00000, "Zoom      :");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 490, 0x00A00000, "Zoom X    :");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 515, 0x00A00000, "Position X:");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 540, 0x00A00000, "Position Y:");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1025, 625, 0x00A00000, "Parrot party");
	mlx_square(mlx_pos_set(1095, 490, 0x00DED9AC), 25, 20, (*env).env);
	mlx_square(mlx_pos_set(1096, 491, 0x00FEF9CC), 10, 18, (*env).env);
	mlx_square(mlx_pos_set(1096 + 13, 491, 0x00FEF9CC), 10, 18, (*env).env);
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1097, 490, 0x008B4513, "-");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1097 + 13, 490, 0x008B4513, "+");
	mlx_square(mlx_pos_set(1175, 620, 0x00000000), 30, 30, (*env).env);
	mlx_square(mlx_pos_set(1176, 621, 0x00006600), 28, 28, (*env).env);
}

void	mlx_interface(t_env *env)
{
	mlx_square(mlx_pos_set(1000, 0, 0x00FFFACD), 240, 800, (*env).env);
	mlx_string_put((*env).env.mlx, (*env).env.win, 1080, 10, 0x00A00000,
			"Fract'ol");
	mlx_square(mlx_pos_set(1010, 40, 0x00EEE9BC), 220, 200, (*env).env);
	mlx_square(mlx_pos_set(1010, 730, 0x00), 220, 60, (*env).env);
	mlx_square(mlx_pos_set(1010, 680, 0x00), 220, 40, (*env).env);
	mlx_square(mlx_pos_set(1011, 731, 0x00FF6666), 218, 58, (*env).env);
	mlx_square(mlx_pos_set(1011, 681, 0x0066FFAA), 218, 38, (*env).env);
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1100, 750, 0x00A00000, "EXIT");
	mlx_string_put((*env).env.mlx, (*env).env.win,
			1095, 690, 0x0000A000, "RESET");
	mlx_square(mlx_pos_set(1010, 260, 0x00EEE9BC), 220, 150, (*env).env);
	mlx_square(mlx_pos_set(1010, 430, 0x00EEE9BC), 220, 230, (*env).env);
	mlx_interface_2(env);
	mlx_interface_choice(env);
	mlx_fractale_set(env);
	mlx_interface_color((*env).env);
}

void	mlx_interface_color(t_lim win)
{
	mlx_square(mlx_pos_set(1025, 459 - 75, 0x000000E0), 150, 6, win);
	mlx_square(mlx_pos_set(1025, 429 - 75, 0x0000E000), 150, 6, win);
	mlx_square(mlx_pos_set(1025, 399 - 75, 0x00E00000), 150, 6, win);
	mlx_square(mlx_pos_set(1025, 460 - 75, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1025, 430 - 75, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1025, 400 - 75, 0x00A0A0A0), 150, 4, win);
	mlx_square(mlx_pos_set(1169, 459 - 75, 0x000000E0), 6, 6, win);
	mlx_square(mlx_pos_set(1169, 429 - 75, 0x0000E000), 6, 6, win);
	mlx_square(mlx_pos_set(1169, 399 - 75, 0x00E00000), 6, 6, win);
	mlx_square(mlx_pos_set(1025, 350 - 75, 0x00000000), 50, 30, win);
	mlx_square(mlx_pos_set(1026, 351 - 75, 0x00FF0000), 48, 28, win);
	mlx_square(mlx_pos_set(1110, 350 - 75, 0x00000000), 30, 30, win);
	mlx_square(mlx_pos_set(1111, 351 - 75, 0x00FFFFFF), 28, 28, win);
	mlx_square(mlx_pos_set(1145, 350 - 75, 0x00FFFFFF), 30, 30, win);
	mlx_square(mlx_pos_set(1146, 351 - 75, 0x00FFFFFF), 28, 28, win);
	mlx_square(mlx_pos_set(1184, 348 - 75, 0x00DED9AC), 37, 120, win);
	mlx_square(mlx_pos_set(1185, 275, 0x00FEF9CC), 35, 20, win);
	mlx_square(mlx_pos_set(1185, 298, 0x00FEF9CC), 35, 10, win);
	mlx_square(mlx_pos_set(1185, 371, 0x00FEF9CC), 35, 20, win);
	mlx_square(mlx_pos_set(1185, 358, 0x00FEF9CC), 35, 10, win);
	mlx_string_put(win.mlx, win.win, 1187, 322, 0x008B4513, "It.");
	mlx_string_put(win.mlx, win.win, 1198, 275, 0x008B4513, "+");
	mlx_string_put(win.mlx, win.win, 1198, 370, 0x008B4513, "-");
}

void	mlx_info(t_env env)
{
	char	*info;

	info = ft_itoa(env.it_max);
	mlx_square(mlx_pos_set(1135, 440, 0x00EEE9BC), 90, 150, env.env);
	mlx_string_put(env.env.mlx, env.env.win,
			1175 - (4 * ft_strlen(info)), 440, 0x00A00000, info);
	free(info);
	info = ft_itoa(env.zoom);
	mlx_string_put(env.env.mlx, env.env.win,
			1175 - (4 * ft_strlen(info)), 465, 0x00A00000, info);
	free(info);
	info = ft_itoa((double)(env.zoom_inc * 10.0));
	mlx_string_put(env.env.mlx, env.env.win,
			1175 - (4 * ft_strlen(info)), 490, 0x00A00000, info);
	free(info);
	info = ft_itoa(env.value.x * 100);
	mlx_string_put(env.env.mlx, env.env.win,
			1175 - (4 * ft_strlen(info)), 515, 0x00A00000, info);
	free(info);
	info = ft_itoa(env.value.z * 100);
	mlx_string_put(env.env.mlx, env.env.win,
			1175 - (4 * ft_strlen(info)), 540, 0x00A00000, info);
	free(info);
}
