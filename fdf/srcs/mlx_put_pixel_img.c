/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:50:43 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 13:45:27 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put_pixel_img(int x, int y, int col, t_lim *win)
{
	if ((x + (y * (*win).img.line)) <= ((*win).img.y * (*win).img.line)
			&& x >= 0 && y >= 0 && x < (*win).img.line)
	{
		if (((*win).ret == 3 || (*win).ret == 4 || (*win).ret == 0))
		{
			(*win).img.src[(x + (y * (*win).img.line))] = col;
		}
		if (((*win).ret == 1 || (*win).ret == 2)
				&& ((*win).img.src[(x + (y * (*win).img.line))] == 0))
		{
			(*win).img.src[(x + (y * (*win).img.line))] = col;
		}
	}
}
