/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wold3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 06:20:26 by khtran            #+#    #+#             */
/*   Updated: 2019/02/01 16:39:05 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../includes/wolf3d.h"

void	wf_event_rotation_mouse(t_env *env, double x)
{
	double	tmp;

	if (x != 0)
	{
		tmp = env->map->dir_x;
		env->map->dir_x = tmp * cos(x) + env->map->dir_y * -sin(x);
		env->map->dir_y = tmp * sin(x) + env->map->dir_y * cos(x);
		tmp = env->map->screen_x;
		env->map->screen_x = tmp * cos(x) + env->map->screen_y * -sin(x);
		env->map->screen_y = tmp * sin(x) + env->map->screen_y * cos(x);
	}
}

void	wf_event_pause(t_env *env)
{
	if (env->pause == 1 && env->stop)
	{
		if ((env->for_screen = SDL_CreateTextureFromSurface(env->render,
						env->paused)) == NULL)
			printf("Texture Creation\n");
		SDL_RenderCopy(env->render, env->for_screen, NULL, NULL);
		SDL_RenderPresent(env->render);
		SDL_DestroyTexture(env->for_screen);
	}
	while (env->pause == 1 && env->stop)
	{
		while (SDL_PollEvent(&(env->event)))
		{
			if (env->event.type == SDL_QUIT || (env->event.type == SDL_KEYDOWN
				&& env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				env->stop = 0;
			if (env->keyboard[SDL_SCANCODE_P])
				env->pause = 0;
			SDL_Delay(20);
		}
	}
}

void	wf_event_press_start(t_env *env)
{
	SDL_Surface *space;
	SDL_Surface *wolf;

	env->keyboard = (Uint8*)SDL_GetKeyboardState(NULL);
	space = SDL_LoadBMP("textures/wolfwithspace.bmp");
	wolf = SDL_LoadBMP("textures/wolf.bmp");
	if ((SDL_BlitSurface(space, NULL, env->modifier, NULL)))
		wf_sdl_error("BlitzSurface failed\n", env);
	SDL_FreeSurface(space);
	if ((env->for_screen = SDL_CreateTextureFromSurface(env->render,
					env->modifier)) == NULL)
		wf_sdl_error("Creating texture failed\n", env);
	SDL_RenderCopy(env->render, env->for_screen, NULL, NULL);
	SDL_RenderPresent(env->render);
	if ((SDL_BlitSurface(wolf, NULL, env->modifier, NULL)))
		wf_sdl_error("BlitzSurface failed\n", env);
	SDL_FreeSurface(wolf);
	if ((env->for_screen = SDL_CreateTextureFromSurface(env->render,
					env->modifier)) == NULL)
		wf_sdl_error("Creating texture failed\n", env);
	SDL_RenderCopy(env->render, env->for_screen, NULL, NULL);
	SDL_RenderPresent(env->render);
	SDL_DestroyTexture(env->for_screen);
	wf_event_press_start2(env);
}

void	wf_event_main(t_env *env)
{
	while (SDL_PollEvent(&(env->event)))
	{
		if (env->event.type == SDL_QUIT || (env->event.type == SDL_KEYDOWN
			&& env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			env->stop = 0;
		if (env->keyboard[SDL_SCANCODE_P])
			env->pause = 1;
	}
	SDL_GetMouseState(&env->mouse.x, &env->mouse.y);
	wf_event_rotation_mouse(env, -((double)env->mouse.x - (WE / 2)) / 1000);
	SDL_WarpMouseInWindow(env->win, WE / 2, HE / 2);
	wf_event_pause(env);
	wf_event(env);
	SDL_FillRect(env->modifier, &(SDL_Rect){0, HE / 2, WE, HE / 2},
			0x22717171);
	wf_ray(env);
	if ((env->for_screen = SDL_CreateTextureFromSurface(env->render,
					env->modifier)) == NULL)
		wf_sdl_error("Creating texture failed\n", env);
	SDL_RenderCopy(env->render, env->for_screen, NULL, NULL);
	SDL_RenderPresent(env->render);
	SDL_DestroyTexture(env->for_screen);
	SDL_Delay(20);
}

int		main(int ac, char **av)
{
	int		index;
	t_env	env;

	index = 0;
	wf_init_env_null(&env);
	if (ac > 1)
		env.map = wf_map_check(av[1]);
	else
		ft_error("Usage: ./Wold3d [target (one max)]\n");
	if (env.map == NULL)
		wf_sdl_error("Invalid map\n", &env);
	wf_init_env(&env);
	SDL_SetWindowIcon(env.win, env.texture[9]);
	wf_event_press_start(&env);
	while (env.stop)
		wf_event_main(&env);
	wf_sdl_error("", &env);
	return (0);
}
