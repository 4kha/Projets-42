/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:18:53 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 17:43:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftmlx.h"

int				mlx_color_med(int color_dep, int color_end, double rapport)
{
	t_rgb	dep;
	t_rgb	end;
	int		result;

	dep.b = (color_dep / 256) / 256;
	dep.g = (color_dep - (dep.b * 256 * 256)) / 256;
	dep.r = (color_dep - (dep.b * 256 * 256 + dep.g * 256));
	end.b = (color_end / 256) / 256;
	end.g = (color_end - (end.b * 256 * 256)) / 256;
	end.r = (color_end - (end.b * 256 * 256 + end.g * 256));
	dep.r = dep.r - ((dep.r - end.r) * rapport);
	dep.g = dep.g - ((dep.g - end.g) * rapport);
	dep.b = dep.b - ((dep.b - end.b) * rapport);
	result = (dep.b * 256 * 256) + (dep.g * 256) + (dep.r);
	return (result);
}

int				mlx_color_set(int r, int g, int b)
{
	int		color;

	color = ((r * 255 / 144) * 256 * 256)
			+ ((g * 255 / 144) * 256)
			+ (b * 255 / 144);
	return (color);
}
