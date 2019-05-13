/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_click_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:15:51 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 23:17:35 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_interaction8_click(int button, int x, int y, t_env *param)
{
	if (button == 1 && x >= 1175 && x <= 1175 + 30
			&& y >= 620 && y <= 620 + 30 && (*param).t.trigger[7] == 1)
	{
		(*param).t.trigger[7] = 0;
		mlx_square(mlx_pos_set(1176, 621, 0x00006600), 28, 28, (*param).env);
		mlx_calculate(*param);
	}
	else if (button == 1 && x >= 1175 && x <= 1175 + 30
			&& y >= 620 && y <= 620 + 30 && (*param).t.trigger[7] == 0)
	{
		(*param).t.trigger[7] = 1;
		system("open ~/Downloads/parrot.mp3");
		mlx_square(mlx_pos_set(1176, 621, 0x0000FF00), 28, 28, (*param).env);
	}
	if (button == 1 && x >= 1185 && x <= 1185 + 35
			&& y >= 275 && y <= 371 + 40)
		mlx_calculate(*param);
	mlx_info(*param);
}

void	mlx_interaction7_click(int button, int x, int y, t_env *param)
{
	if (button == 1 && x >= 1011 && x <= 1011 + 218
			&& y >= 681 && y <= 681 + 38)
	{
		(*param).zoom = 300;
		(*param).zoom_inc = 1.1;
		(*param).it_max = 50;
		if ((*param).t.trigger[2] == 3)
			(*param).zoom = 1;
		if ((*param).t.trigger[2] == 4 || (*param).t.trigger[2] == 5)
			(*param).zoom = 200;
		if ((*param).t.trigger[2] == 0)
			(*param).value = mlx_value_set(-2.1, 0.6, -1.2, 1.2);
		if ((*param).t.trigger[2] == 1)
			(*param).value = mlx_value_set(-1.7, 0.3, -1.2, 1.2);
		if ((*param).t.trigger[2] == 2)
			(*param).value = mlx_value_set(-1.2, 1, -1.8, 1.2);
		if ((*param).t.trigger[2] == 3)
			(*param).value = mlx_value_set(-3.0, 1, -3, 1);
		if ((*param).t.trigger[2] == 4)
			(*param).value = mlx_value_set(-3.2, -0.4, -2.0, 1.2);
		if ((*param).t.trigger[2] == 5)
			(*param).value = mlx_value_set(-2.7, 1, -1.9, 1.2);
		mlx_calculate(*param);
	}
	mlx_interaction8_click(button, x, y, param);
}

void	mlx_interaction6_click(int button, int x, int y, t_env *param)
{
	if (button == 1 && x >= 1185 && x <= 1185 + 35
			&& y >= 275 && y <= 275 + 20)
		(*param).it_max += 10;
	if (button == 1 && x >= 1185 && x <= 1185 + 35
			&& y >= 298 && y <= 298 + 10)
		(*param).it_max += 1;
	if (button == 1 && x >= 1185 && x <= 1185 + 35
			&& y >= 371 && y <= 371 + 20)
		(*param).it_max -= 10;
	if (button == 1 && x >= 1185 && x <= 1185 + 35
			&& y >= 358 && y <= 358 + 10)
		(*param).it_max -= 1;
	if (button == 1 && x >= 1096 && x <= 1096 + 10
			&& y >= 491 && y <= 491 + 18)
		(*param).zoom_inc -= 0.1;
	if (button == 1 && x >= 1096 + 13 && x <= 1096 + 23
			&& y >= 491 && y <= 491 + 18)
		(*param).zoom_inc += 0.1;
	mlx_interaction7_click(button, x, y, param);
}
