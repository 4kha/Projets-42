/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:45:06 by khtran            #+#    #+#             */
/*   Updated: 2019/01/31 17:29:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wf_map_space(char *str)
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

char	*wf_map_read(char *map_way)
{
	int		index;
	int		fd;
	char	*string;

	string = NULL;
	if ((fd = open(map_way, O_RDONLY)) == -1)
		return (NULL);
	string = wf_read(fd);
	if (close(fd) == -1 || string == NULL)
	{
		free(string);
		return (NULL);
	}
	return (string);
}

int		wf_map_spacevalid(char *map, t_map *map_info)
{
	int		index;

	index = 0;
	map_info->max_x = wf_map_space(map);
	map_info->max_y = 0;
	while (map[index] && map[index] != '\n')
		index++;
	if (map_info->max_x == 0)
		return (1);
	while (map[index])
	{
		if (map[index] == '\n')
		{
			index++;
			map_info->max_y += 1;
			if (map[index] && wf_map_space(&(map[index])) != map_info->max_x)
				return (1);
		}
		else
			index++;
	}
	return (0);
}

int		wf_map_spawnvalid(t_map *map, int spawn)
{
	int		x;
	int		y;

	y = 0;
	spawn = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			if (spawn == 0 && map->map[y][x].type == 1)
			{
				spawn++;
				map->pos_x = x + 0.5;
				map->pos_y = y + 0.5;
			}
			x++;
		}
		y++;
	}
	if (spawn == 0)
		map->map[0][0] = (t_tile){0, 1};
	else if (spawn > 1)
		return (1);
	return (0);
}

t_map	*wf_map_check(char *map_way)
{
	t_map	*map;
	char	*string;

	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((string = wf_map_read(map_way)) == NULL || *string == '\0')
	{
		free(map);
		return (NULL);
	}
	map->pos_x = 0.5;
	map->pos_y = 0.5;
	if (wf_map_spacevalid(string, map)
		|| (wf_map_fill_y(string, map)) || wf_map_spawnvalid(map, 0))
	{
		free(string);
		free(map);
		return (NULL);
	}
	free(string);
	return (map);
}
