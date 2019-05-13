/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:06:17 by khtran            #+#    #+#             */
/*   Updated: 2019/02/01 16:41:16 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_pause(SDL_Surface *pause)
{
	int		i;
	Uint32	*pixel;

	pixel = (Uint32*)pause->pixels;
	i = 0;
	SDL_SetSurfaceBlendMode(pause, SDL_BLENDMODE_BLEND);
	while (i < WE * HE)
	{
		pixel[i] = 0x00000000;
		i++;
	}
}

void	wf_init_env_null(t_env *env)
{
	env->win = NULL;
	env->render = NULL;
	env->map = NULL;
	env->stop = 1;
	env->pause = 1;
	env->texture[0] = NULL;
	env->texture[1] = NULL;
	env->texture[2] = NULL;
	env->texture[3] = NULL;
	env->texture[4] = NULL;
	env->texture[5] = NULL;
	env->texture[6] = NULL;
	env->texture[7] = NULL;
	env->texture[8] = NULL;
	env->texture[9] = NULL;
	env->for_screen = NULL;
}

void	wf_load_img(t_env *env)
{
	if ((env->texture[0] = SDL_LoadBMP("textures/wall1.bmp")) == NULL ||
		(env->texture[1] = SDL_LoadBMP("textures/wall2.bmp")) == NULL ||
		(env->texture[2] = SDL_LoadBMP("textures/wall3.bmp")) == NULL ||
		(env->texture[3] = SDL_LoadBMP("textures/wall4.bmp")) == NULL ||
		(env->texture[4] = SDL_LoadBMP("textures/pause.bmp")) == NULL ||
		(env->texture[5] = SDL_LoadBMP("textures/sky4.bmp")) == NULL ||
		(env->texture[6] = SDL_LoadBMP("textures/sky2.bmp")) == NULL ||
		(env->texture[7] = SDL_LoadBMP("textures/sky3.bmp")) == NULL ||
		(env->texture[8] = SDL_LoadBMP("textures/sky1.bmp")) == NULL ||
		(env->texture[9] = SDL_LoadBMP("textures/Hitler.bmp")) == NULL)
		wf_sdl_error("SDL_LoadBMP failed\n", env);
}

void	wf_init_env(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		wf_sdl_error("SDL_Init failed\n", env);
	if ((env->win = SDL_CreateWindow("Wolf3d\n", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WE, HE, SDL_WINDOW_SHOWN)) == NULL)
		wf_sdl_error("SDL_CreateWindow failed\n", env);
	if ((env->render = SDL_CreateRenderer(env->win, -1,
			SDL_RENDERER_ACCELERATED)) == NULL)
		wf_sdl_error("SDL_CreateRenderer failed\n", env);
	SDL_SetRenderDrawBlendMode(env->render, SDL_BLENDMODE_BLEND);
	wf_load_img(env);
	env->modifier = SDL_CreateRGBSurface(0, WE, HE, 32, 0, 0, 0, 0);
	env->paused = SDL_CreateRGBSurface(0, WE, HE, 32, 0, 0, 0, 0);
	init_pause(env->paused);
	SDL_BlitSurface(env->texture[4], NULL, env->paused, &(SDL_Rect){WE / 2 -
			75, HE / 2 - 37, 150, 75});
	env->wall_hit = 0;
	env->map->dir_x = 0;
	env->map->dir_y = 1;
	env->map->screen_x = 0.66;
	env->map->screen_y = 0;
}
