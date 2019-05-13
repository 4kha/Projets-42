/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madecreu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:17:27 by madecreu          #+#    #+#             */
/*   Updated: 2019/02/01 16:30:30 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

Uint32	wf_getpixel(SDL_Surface *surface, int x, int y)
{
	Uint8	*p;

	p = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
	return (*(Uint32 *)p);
}

void	wf_putpixel(SDL_Surface *modifier, int pos, Uint32 color)
{
	Uint32	*pixel;

	pixel = (Uint32*)modifier->pixels;
	if (pos >= 0 && pos <= WE * HE)
		pixel[pos] = color;
}

double	wf_ray_type(t_env *env, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step.x == 1)
			env->wall_hit = 0;
		else
			env->wall_hit = 1;
		return ((ray->diff.x - env->map->pos_x + (1 - ray->step.x) / 2)
			/ ray->ray.x);
	}
	else
	{
		if (ray->step.y == 1)
			env->wall_hit = 2;
		else
			env->wall_hit = 3;
		return ((ray->diff.y - env->map->pos_y + (1 - ray->step.y) / 2)
			/ ray->ray.y);
	}
}

void	wf_ray_skybox_trace(t_env *env, int x, double h, t_ray ray)
{
	int		index;
	int		z;
	double	hit;
	Uint32	color;
	double	truc;

	index = 0;
	z = HE;
	hit = ray.w_hit * 194;
	while (index < HE / 2)
	{
		color = wf_getpixel(env->texture[env->wall_hit + 5],
				(int)hit, ((double)index / z) * 194);
		wf_putpixel(env->modifier, index * WE + x, color);
		index++;
	}
}

void	wf_ray_trace(t_env *env, int x, double h, t_ray ray)
{
	int		index;
	int		z;
	double	hit;
	Uint32	color;
	double	tmp;

	index = 0;
	z = HE / h;
	hit = ray.w_hit * 64;
	tmp = (HE / 2) - (z / 2);
	while (index < z)
	{
		color = wf_getpixel(env->texture[env->wall_hit],
				(int)hit, ((double)index / z) * 64);
		wf_putpixel(env->modifier, (tmp + index) * WE + x, color);
		index++;
	}
}
