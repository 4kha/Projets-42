/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:54:37 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 19:43:44 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_interaction1_key_click(int button, t_env *param)
{
	if (button == 53)
	{
		exit(0);
	}
	if (button == 125)
	{
		mlx_calculate(*param);
	}
	if (button == 126)
	{
		mlx_calculate(*param);
	}
	if (button == 35 && (*param).t.trigger[9] == 0)
	{
		(*param).t.trigger[9] = 1;
	}
	else if (button == 35 && (*param).t.trigger[9] == 1)
	{
		(*param).t.trigger[9] = 0;
	}
	return (0);
}
