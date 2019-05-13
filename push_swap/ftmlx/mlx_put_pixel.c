/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:21:38 by khtran            #+#    #+#             */
/*   Updated: 2018/02/04 13:19:21 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	mlx_put_pixel_img(int x, int y, int col, t_img *win)
{
	if ((x + (y * (*win).line_x)) <= ((*win).line_y
				* (*win).line_x) && x >= 0 && y >= 0
				&& x < (*win).line_x)
	{
		(*win).src[(x + (y * (*win).line_x))] = col;
	}
}
