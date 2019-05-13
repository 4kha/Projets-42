/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:31:46 by khtran            #+#    #+#             */
/*   Updated: 2018/02/04 13:20:13 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

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

int		mlx_square_img(t_pos start, t_pos go, t_img img, t_lim *win)
{
	int		x_bis;
	int		y_bis;

	x_bis = 0;
	y_bis = 0;
	while (y_bis <= go.y)
	{
		x_bis = 0;
		while (x_bis <= go.x)
		{
			mlx_put_pixel_img(start.x + x_bis,
					start.y + y_bis, start.color, &img);
			x_bis++;
		}
		y_bis++;
	}
	return (0);
}
