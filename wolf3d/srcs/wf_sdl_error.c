/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_sdl_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:01:47 by khtran            #+#    #+#             */
/*   Updated: 2019/02/01 16:37:45 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wf_free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		free(map->map[y]);
		y++;
	}
}

void	wf_unload(t_env *env)
{
	int		index;

	index = 0;
	while (index != 10)
	{
		if (env->texture[index] != NULL)
			SDL_FreeSurface(env->texture[index]);
		index++;
	}
}

void	wf_sdl_error(char *str, t_env *env)
{
	if (env->map != NULL)
	{
		wf_free_map(env->map);
		free(env->map);
	}
	if (env->render != NULL)
		SDL_DestroyRenderer(env->render);
	if (env->win != NULL)
		SDL_DestroyWindow(env->win);
	if (env->for_screen != NULL)
		SDL_DestroyTexture(env->for_screen);
	wf_unload(env);
	SDL_Quit();
	ft_putstr_fd(str, 2);
	exit(0);
}
