/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:30:20 by khtran            #+#    #+#             */
/*   Updated: 2018/11/28 10:44:05 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos		mlx_pos_set(int x, int y, int color)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.color = color;
	return (pos);
}

void		mlx_tab_set(int high, int color, t_tab *tab)
{
	(*tab).high = high;
	(*tab).color = color;
}

void		mlx_rgb_set(t_lim *win, int r, int g, int b)
{
	(*win).rgb.r = r;
	(*win).rgb.g = g;
	(*win).rgb.b = b;
	(*win).rgb2.r = r;
	(*win).rgb2.g = g;
	(*win).rgb2.b = b;
	(*win).trigger_1 = 0;
	(*win).trigger_2 = 0;
	(*win).trigger_3 = 0;
	(*win).trigger_6 = 0;
	(*win).trigger_7 = 0;
	(*win).trigger_9 = 0;
	(*win).trigger_10 = 0;
	(*win).camhigh = 200;
	(*win).level = 0;
}

int			mlx_count_line_x(char *str)
{
	int		index;
	int		count;

	count = 1;
	index = 0;
	while (str[index] == ' ' && str[index])
		index++;
	while ((str[index] && str[index] != '\n') && (str[index + 1]
				&& str[index + 1] != '\n'))
	{
		if (str[index] == ' ')
		{
			count++;
			while (str[index] && str[index] == ' ' && str[index] != '\n')
				index++;
		}
		else
			index++;
	}
	return (count);
}

void		mlx_prepare_pos(int fd, t_lim *tab)
{
	int		count;
	char	*str;

	if (get_next_line(fd, &str) == -1)
	{
		ft_putstr_fd("Malloc/Gnl failed.\n", 2);
		exit(0);
	}
	if (!str)
		exit(0);
	(*tab).size_x = mlx_count_line_x(str);
	free(str);
	count = 1;
	while (get_next_line(fd, &str) == 1)
	{
		if ((*tab).size_x != mlx_count_line_x(str) || str == NULL)
		{
			ft_putstr_fd("Target_file is not a valid file.\n", 2);
			exit(0);
		}
		free(str);
		count++;
	}
	free(str);
	(*tab).size_y = count;
}
