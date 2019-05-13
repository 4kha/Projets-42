/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hold.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:22:25 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 16:59:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_interaction2_hold(t_env *env)
{
	if ((*env).t.trigger[7] == 1)
	{
		party_parrot_of_doom(env);
		mlx_calculate(*env);
	}
}

int		mlx_interaction1_hold(int x, int y, t_env *param)
{
	t_pos	mid;

	mid = mlx_pos_set((x - 600), (y - 500), 0x00FFFFFF);
	if ((*param).t.trigger[9] == 0)
		(*param).pos = mlx_pos_set(x, y, 0);
	if ((*param).t.trigger[0] == 1)
	{
		(*param).value.x = ((*param).value.x - (0.0025
					/ ((*param).zoom / 400)) * (x - (*param).click.x));
		(*param).value.z = ((*param).value.z - (0.0025
					/ ((*param).zoom / 400)) * (y - (*param).click.y));
		(*param).value.y = ((*param).value.y - (0.0025
					/ ((*param).zoom / 400)) * (x - (*param).click.x));
		(*param).value.w = ((*param).value.w - (0.0025
					/ ((*param).zoom / 400)) * (y - (*param).click.y));
		(*param).click = mlx_pos_set(x, y, 0x00FFFFFF);
		mlx_calculate(*param);
	}
	if (((*param).t.trigger[2] == 5 || (*param).t.trigger[2] == 4)
			&& (*param).t.trigger[9] == 0)
		mlx_calculate(*param);
	mlx_interface_color_while(x, param);
	mlx_interaction2_hold(param);
	return (0);
}
