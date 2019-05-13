/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_trigger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 06:01:04 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 18:18:58 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_trigger	mlx_trigger_create(int count)
{
	t_trigger	new;
	int			index;

	index = 0;
	new.trigger = (int*)malloc(sizeof(int*) * (count + 1));
	if (new.trigger == NULL)
	{
		ft_putstr("Malloc failed > mlx_trigger_create\n");
		exit(1);
	}
	new.count_t = count;
	while (new.count_t >= index)
	{
		new.trigger[index] = 0;
		index++;
	}
	return (new);
}

void		mlx_trigger_set(t_trigger *trigger)
{
	int			index;

	index = 0;
	while ((*trigger).count_t >= index)
	{
		(*trigger).trigger[index] = 0;
		index++;
	}
}

int			mlx_close(void)
{
	exit(0);
	return (0);
}
