/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:17:13 by khtran            #+#    #+#             */
/*   Updated: 2018/07/07 05:47:37 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pre_line_1(t_lim fen, t_vec v, t_lim *win)
{
	mlx_line(mlx_pos_set((v.pos.x + ((v.x.x - v.pos.x)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))
			+ ((v.y.x - v.pos.x) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1))) + (-((v.x.x - v.last.x)
			+ (v.y.x - v.pos.x)))
			* (double)((double)fen.index_y / (double)(fen.size_y - 1)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))),
			(v.pos.y + (-((v.varx.high * ((double)250 / (double)fen.size_z))
			* ((double)fen.high / (double)114))) + ((v.x.y - v.pos.y)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))
			+ ((v.y.y - v.pos.y) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1)))), v.varx.color),

			mlx_pos_set((v.pos.x + ((v.x.x - v.pos.x)
			* (double)((double)(fen.index_x + 1) / (double)(fen.size_x - 1)))
			+ ((v.y.x - v.pos.x) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1))) + (-((v.x.x - v.last.x)
			+ (v.y.x - v.pos.x)))
			* (double)((double)fen.index_y / (double)(fen.size_y - 1)
			* (double)((double)(fen.index_x + 1) / (double)(fen.size_x - 1)))),
			(v.pos.y + (-((v.vary.high * ((double)250 / (double)fen.size_z))
			* ((double)fen.high / (double)114))) + ((v.x.y - v.pos.y)
			* (double)((double)(fen.index_x + 1) / (double)(fen.size_x - 1)))
			+ ((v.y.y - v.pos.y) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1)))), v.vary.color), win);
}

void	mlx_pre_line_2(t_lim fen, t_vec v, t_lim *win)
{
	mlx_line(mlx_pos_set((v.pos.x + ((v.x.x - v.pos.x)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))
			+ ((v.y.x - v.pos.x) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1))) + (-((v.x.x - v.last.x)
			+ (v.y.x - v.pos.x)))
			* (double)((double)fen.index_y / (double)(fen.size_y - 1)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))),
			(v.pos.y + (-((v.varx.high * ((double)250 / (double)fen.size_z))
			* ((double)fen.high / (double)114))) + ((v.x.y - v.pos.y)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))
			+ ((v.y.y - v.pos.y) * (double)((double)fen.index_y
			/ (double)(fen.size_y - 1)))), v.varx.color),
			mlx_pos_set((v.pos.x + ((v.x.x - v.pos.x)
			* (double)((double)(fen.index_x) / (double)(fen.size_x - 1)))
			+ ((v.y.x - v.pos.x) * (double)((double)(fen.index_y + 1)
			/ (double)(fen.size_y - 1))) + (-((v.x.x - v.last.x)
			+ (v.y.x - v.pos.x)))
			* (double)((double)(fen.index_y + 1) / (double)(fen.size_y - 1)
			* (double)((double)fen.index_x / (double)(fen.size_x - 1)))),
			(v.pos.y + (-((v.varb.high * ((double)250 / (double)fen.size_z))
			* ((double)fen.high / (double)114))) + ((v.x.y - v.pos.y)
			* (double)((double)(fen.index_x) / (double)(fen.size_x - 1)))
			+ ((v.y.y - v.pos.y) * (double)((double)(fen.index_y + 1)
			/ (double)(fen.size_y - 1)))), v.varb.color), win);
}

void	mlx_grid_last(t_lim *fen, t_vec start)
{
	(*fen).index_x = 0;
	while ((*fen).index_x < (*fen).size_x)
	{
		start.varx = (*fen).matrice[(*fen).index_y][(*fen).index_x];
		start.vary = (*fen).matrice[(*fen).index_y][(*fen).index_x + 1];
		if ((*fen).trigger_4 == 1)
		{
			mlx_pre_color(&start.varx, *fen);
			mlx_pre_color(&start.vary, *fen);
		}
		if ((*fen).index_x > 0 && (*fen).index_y + 1 < (*fen).size_y)
		{
			start.varb = (*fen).matrice[(*fen).index_y + 1][(*fen).index_x];
			if ((*fen).trigger_4 == 1)
				mlx_pre_color(&start.varb, *fen);
			mlx_pre_line_2(*fen, start, fen);
		}
		if ((*fen).index_y + 1 < (*fen).size_y && (*fen).index_x
				+ 1 < (*fen).size_x)
			mlx_pre_line_1(*fen, start, fen);
		(*fen).index_x++;
	}
}

int		mlx_select_vec(t_vec *v, t_lim *fen)
{
	if ((*fen).trigger_4 == 0)
		(*fen).color_def = 0x00FFFFFF;
	if ((*fen).trigger_8 == 1)
		mlx_vec_set(v, fen);
	if ((*fen).trigger_8 == 2)
		mlx_vec_set2(v, fen);
	if ((*fen).trigger_8 == 3)
		mlx_vec_set3(v, fen);
	if ((*fen).trigger_11 == 0)
		return (0);
	if ((*v).last.y <= (*v).x.y && (*v).last.y <= (*v).y.y
			&& (*v).last.y <= (*v).pos.y)
		return (1);
	if ((*v).y.y <= (*v).x.y && (*v).y.y <= (*v).last.y
			&& (*v).y.y <= (*v).pos.y)
		return (2);
	if ((*v).pos.y <= (*v).x.y && (*v).pos.y <= (*v).y.y
			&& (*v).pos.y <= (*v).last.y)
		return (3);
	if ((*v).x.y <= (*v).last.y && (*v).x.y <= (*v).y.y
			&& (*v).x.y <= (*v).pos.y)
		return (4);
	return (0);
}

void	mlx_grid(t_lim *fen)
{
	t_vec	start;

	(*fen).ret = 0;
	(*fen).ret = mlx_select_vec(&start, fen);
	while ((*fen).index_y < (*fen).size_y)
	{
		mlx_grid_last(fen, start);
		(*fen).index_y++;
	}
	(*fen).ret = 0;
}
