/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_map_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 04:15:42 by khtran            #+#    #+#             */
/*   Updated: 2018/12/18 15:02:44 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wf_map_free_error(t_tile **save, t_map *map_info, int cur_y)
{
	int		index;

	index = 0;
	while (index < cur_y)
	{
		free(save[index]);
		index++;
	}
	free(save);
}

t_tile	wf_map_fill_tile(int value)
{
	t_tile	tile;

	if (value == 2)
		tile = (t_tile){0, 1};
	else
		tile = (t_tile){value, 0};
	return (tile);
}

t_tile	*wf_map_fill_x(char *map, t_map *map_info)
{
	int		i_x;
	int		i_map;
	int		ret;
	t_tile	*tile;

	if ((tile = (t_tile*)malloc(sizeof(t_tile)
			* (map_info->max_x) + 1)) == NULL)
		return (NULL);
	i_x = 0;
	i_map = 0;
	while (map[i_map] && map[i_map] == ' ')
		i_map++;
	while (i_x < map_info->max_x)
	{
		tile[i_x] = wf_map_fill_tile(ft_atoi(&(map[i_map])));
		while (map[i_map] && map[i_map] != ' ')
			i_map++;
		while (map[i_map] && map[i_map] == ' ')
			i_map++;
		i_x++;
	}
	return (tile);
}

int		wf_map_fill_y(char *map, t_map *map_info)
{
	int		index_y;
	int		index;
	t_tile	**save;

	index = 0;
	index_y = 0;
	save = (t_tile**)malloc(sizeof(t_tile) * (map_info->max_y + 1));
	if (save == NULL)
		return (1);
	while (index_y < map_info->max_y)
	{
		if ((save[index_y] = wf_map_fill_x(&map[index], map_info)) == NULL)
		{
			wf_map_free_error(save, map_info, index_y - 1);
			return (1);
		}
		while (map[index] && map[index] != '\n')
			index++;
		if (map[index])
			index++;
		index_y++;
	}
	map_info->map = save;
	return (0);
}
