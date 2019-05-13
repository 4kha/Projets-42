/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:17:12 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 22:14:52 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tab	**mlx_matrice(int fd, t_lim fen)
{
	int			index;
	char		*line;
	t_tab		**matrice;

	fen.index_y = 0;
	matrice = (t_tab**)malloc(sizeof(matrice) * (fen.size_y + 1));
	while (fen.index_y < fen.size_y)
	{
		index = 1;
		get_next_line(fd, &line);
		matrice[fen.index_y] = (t_tab*)malloc(sizeof(t_tab*)
				* (fen.size_x + 1));
		fen.index_x = 0;
		while (fen.index_x < fen.size_x)
		{
			matrice[fen.index_y][fen.index_x] = mlx_atoi_at(line, index);
			index++;
			fen.index_x++;
		}
		free(line);
		fen.index_y++;
	}
	return (matrice);
}

int		mlx_matrice_highest(t_tab **matrice, t_lim fen)
{
	int		biggest;

	biggest = matrice[0][0].high;
	fen.index_y = 0;
	while (fen.index_y < fen.size_y)
	{
		fen.index_x = 0;
		while (fen.index_x < fen.size_x)
		{
			if (biggest < matrice[fen.index_y][fen.index_x].high)
				biggest = matrice[fen.index_y][fen.index_x].high;
			fen.index_x++;
		}
		fen.index_y++;
	}
	return (biggest);
}

void	mlx_vec_set(t_vec *start, t_lim *data)
{
	(*start).x = mlx_pos_set((600 + 550 * cos((*data).rot + (PI + (PI / 2)))),
			(550 + (*data).camhigh
			* sin((*data).rot + (PI + (PI / 2)))), 0x00FFFFFF);
	(*start).pos = mlx_pos_set((600 + 550 * cos((*data).rot + PI)),
			(550 + (*data).camhigh * sin((*data).rot + PI)), 0x00FFFFFF);
	(*start).y = mlx_pos_set((600 + 550 * cos((*data).rot + (PI / 2))),
			(550 + (*data).camhigh * sin((*data).rot + (PI / 2))), 0x00FFFFFF);
	(*start).last = mlx_pos_set((600 + 550 * cos((*data).rot + (2 * PI))),
			(550 + (*data).camhigh * sin((*data).rot + (PI * 2))), 0x00FFFFFF);
	(*start).z = mlx_pos_set((*start).x.x, 0, 0x00FFFFFF);
	(*start).center = mlx_pos_set(600, 400, 0x00FFFFFF);
	if ((*data).trigger_10 == 1)
	{
		mlx_line((*start).x, (*start).pos, data);
		mlx_line((*start).y, (*start).pos, data);
		mlx_line((*start).y, (*start).last, data);
		mlx_line((*start).last, (*start).x, data);
	}
}

void	mlx_vec_set3(t_vec *start, t_lim *data)
{
	(*start).x = mlx_pos_set(1000 + (*data).rot * 100, 250
			+ (*data).camhigh, 0x00FFFFFF);
	(*start).pos = mlx_pos_set(350 + (*data).rot * 100, 250
			+ (*data).camhigh, 0x00FFFFFF);
	(*start).y = mlx_pos_set(150, 700, 0x00FFFFFF);
	(*start).last = mlx_pos_set(800, 700, 0x00FFFFFF);
	(*start).z = mlx_pos_set((*start).x.x, 0, 0x00FFFFFF);
	(*start).center = mlx_pos_set(600, 400, 0x00FFFFFF);
	if ((*data).trigger_10 == 1)
	{
		mlx_line((*start).x, (*start).pos, data);
		mlx_line((*start).y, (*start).pos, data);
		mlx_line((*start).y, (*start).last, data);
		mlx_line((*start).last, (*start).x, data);
	}
}

void	mlx_vec_set2(t_vec *start, t_lim *data)
{
	(*start).center = mlx_pos_set(600, 150, 0x00FFFFFF);
	(*start).y = mlx_pos_set(350 + ((*data).rot * 100), 150
			+ (*data).camhigh * 1.5, 0x00FFFFFF);
	(*start).last = mlx_pos_set(850 + ((*data).rot * 100), 150
			+ (*data).camhigh * 1.5, 0x00FFFFFF);
	(*start).x = mlx_pos_set((((*start).center.x * 10)
				+ ((*start).last.x * (*data).prof)) / ((*data).prof + 10),
			(((*start).center.y * 10) + (((*start).last.y)
			* (*data).prof)) / ((*data).prof + 10), 0x00FFFFFF);
	(*start).pos = mlx_pos_set((((*start).center.x * 10)
				+ ((*start).y.x * (*data).prof)) / ((*data).prof + 10),
			(((*start).center.y * 10) + (((*start).y.y) * (*data).prof))
			/ ((*data).prof + 10), 0x00FFFFFF);
	(*start).z = mlx_pos_set((*start).x.x, 0, 0x00FFFFFF);
	if ((*data).trigger_10 == 1)
	{
		mlx_line((*start).x, (*start).pos, data);
		mlx_line((*start).y, (*start).pos, data);
		mlx_line((*start).y, (*start).last, data);
		mlx_line((*start).last, (*start).x, data);
	}
}
