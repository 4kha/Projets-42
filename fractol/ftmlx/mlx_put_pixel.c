/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:21:38 by khtran            #+#    #+#             */
/*   Updated: 2017/12/12 04:07:35 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

void	mlx_put_pixel_img(int x, int y, int col, t_lim *win)
{
	if ((x + (y * (*win).img.line_x)) <= ((*win).img.line_y
				* (*win).img.line_x) && x >= 0 && y >= 0
				&& x < (*win).img.line_x)
	{
		(*win).img.src[(x + (y * (*win).img.line_x))] = col;
	}
}
