/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 06:03:12 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 23:09:44 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_interaction1_release(int button, int x, int y, t_env *param)
{
	(void)button;
	(void)x;
	(void)y;
	if (button == 1)
	{
		(*param).t.trigger[0] = 0;
	}
	if (button == 2)
	{
		(*param).t.trigger[1] = 0;
	}
	mlx_interface_color_release(param);
	(*param).t.trigger[3] = 0;
	(*param).t.trigger[4] = 0;
	(*param).t.trigger[5] = 0;
	return (0);
}
