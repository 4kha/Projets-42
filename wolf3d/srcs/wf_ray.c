/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 03:26:42 by khtran            #+#    #+#             */
/*   Updated: 2019/01/31 19:18:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wf_init_ray(t_env *env, t_ray *ray)
{
	ray->type = 0;
	ray->ray.x = env->map->dir_x + env->map->screen_x * ray->process;
	ray->ray.y = env->map->dir_y + env->map->screen_y * ray->process;
	ray->dist = (t_douxy){fabs(1 / ray->ray.x), fabs(1 / ray->ray.y)};
	ray->diff = (t_valxy){(int)env->map->pos_x, (int)env->map->pos_y};
	if (ray->ray.x < 0)
	{
		ray->step.x = -1;
		ray->init_diff.x = (env->map->pos_x - ray->diff.x) * ray->dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->init_diff.x = (ray->diff.x + 1.0 - env->map->pos_x) * ray->dist.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->init_diff.y = (env->map->pos_y - ray->diff.y) * ray->dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->init_diff.y = (ray->diff.y + 1.0 - env->map->pos_y) * ray->dist.y;
	}
}

void	wf_ray_hit(t_map *map, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->init_diff.x < ray->init_diff.y)
		{
			ray->init_diff.x += ray->dist.x;
			ray->diff.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->init_diff.y += ray->dist.y;
			ray->diff.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->diff.x >= map->max_x || ray->diff.y >= map->max_y
				|| ray->diff.x < 0 || ray->diff.y < 0
				|| map->map[ray->diff.y][ray->diff.x].wall != 0)
		{
			ray->hit = 1;
			if (!(ray->diff.x >= map->max_x || ray->diff.y >= map->max_y
				|| ray->diff.x < 0 || ray->diff.y < 0))
				ray->type = (map->map[ray->diff.y][ray->diff.x]).type;
		}
	}
}

void	wf_ray_wall_hit(t_env *env, t_ray *ray, double h)
{
	if (ray->side == 0)
	{
		ray->w_hit = env->map->pos_y + (h * ray->ray.y);
	}
	else
	{
		ray->w_hit = env->map->pos_x + (h * ray->ray.x);
	}
	ray->w_hit -= (int)ray->w_hit;
}

void	wf_ray(t_env *env)
{
	int		x;
	double	h;
	t_ray	ray;

	x = 0;
	wf_ray_skybox(env);
	while (x < WE)
	{
		ray.process = 2 * x / (double)WE - 1;
		wf_init_ray(env, &ray);
		wf_ray_hit(env->map, &ray);
		h = wf_ray_type(env, &ray);
		wf_ray_wall_hit(env, &ray, h);
		wf_ray_trace(env, x, h, ray);
		x++;
	}
}
