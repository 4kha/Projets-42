/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 07:58:26 by khtran            #+#    #+#             */
/*   Updated: 2019/02/01 20:10:59 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define SPEED 0.1
# define ROT 0.1
# define WE 2048
# define HE 1600
# define W_HB 0.2
# define MAP_SYMBOL " 0123456789\n"

typedef struct		s_tile
{
	int				wall;
	int				type;
}					t_tile;

typedef struct		s_map
{
	int				max_x;
	int				max_y;
	t_tile			**map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			screen_x;
	double			screen_y;
}					t_map;

typedef struct		s_valxy
{
	int				x;
	int				y;
}					t_valxy;

typedef struct		s_douxy
{
	double			x;
	double			y;
}					t_douxy;

typedef struct		s_ray
{
	t_douxy			ray;
	t_douxy			dist;
	t_douxy			init_diff;
	t_valxy			diff;
	t_valxy			step;
	int				hit;
	int				type;
	int				side;
	double			process;
	double			w_hit;
}					t_ray;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*render;
	SDL_Event		event;
	SDL_Surface		*texture[10];
	SDL_Surface		*screen;
	SDL_Surface		*paused;
	SDL_Surface		*modifier;
	SDL_Texture		*for_screen;
	int				wall_hit;
	t_map			*map;
	int				stop;
	int				pause;
	Uint8			*keyboard;
	t_valxy			mouse;
}					t_env;

char				*wf_read(int fd);
void				wf_event(t_env *env);
t_map				*wf_map_check(char *map_way);
int					wf_map_fill_y(char *map, t_map *map_info);
void				wf_sdl_error(char *str, t_env *env);
void				wf_init_env_null(t_env *env);
void				wf_init_env(t_env *env);
void				wf_ray(t_env *env);
Uint32				getpixel(SDL_Surface *surface, int x, int y);
double				wf_ray_type(t_env *env, t_ray *ray);
void				wf_ray_trace(t_env *env, int x, double h, t_ray ray);
void				wf_ray_skybox(t_env *env);
void				wf_ray_skybox_trace(t_env *env, int x, double h, t_ray ray);
void				wf_event_press_start2(t_env *env);

#endif
