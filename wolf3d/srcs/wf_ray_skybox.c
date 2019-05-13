/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_ray_skybox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:31:35 by khtran            #+#    #+#             */
/*   Updated: 2019/01/31 19:55:10 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double	wf_ray_skybox_type(t_env *env, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step.x == 1)
			env->wall_hit = 0;
		else
			env->wall_hit = 1;
		return ((ray->diff.x - 0.5 + (1 - ray->step.x) / 2)
			/ ray->ray.x);
	}
	else
	{
		if (ray->step.y == 1)
			env->wall_hit = 2;
		else
			env->wall_hit = 3;
		return ((ray->diff.y - 0.5 + (1 - ray->step.y) / 2)
			/ ray->ray.y);
	}
}

void	wf_init_skybox_ray(t_env *env, t_ray *ray)
{
	ray->type = 0;
	ray->ray.x = env->map->dir_x + env->map->screen_x * ray->process;
	ray->ray.y = env->map->dir_y + env->map->screen_y * ray->process;
	ray->dist = (t_douxy){fabs(1 / ray->ray.x), fabs(1 / ray->ray.y)};
	ray->diff = (t_valxy){(int)0.5, (int)0.5};
	if (ray->ray.x < 0)
	{
		ray->step.x = -1;
		ray->init_diff.x = (0.5 - ray->diff.x) * ray->dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->init_diff.x = (ray->diff.x + 1.0 - 0.5) * ray->dist.x;
	}
	if (ray->ray.y < 0)
	{
		ray->step.y = -1;
		ray->init_diff.y = (0.5 - ray->diff.y) * ray->dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->init_diff.y = (ray->diff.y + 1.0 - 0.5) * ray->dist.y;
	}
}

void	wf_ray_skybox_hit(t_ray *ray)
{
	ray->hit = 1;
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
}

void	wf_ray_skybox(t_env *env)
{
	int		x;
	double	h;
	t_ray	ray;

	x = 0;
	while (x < WE)
	{
		ray.process = 2 * x / (double)WE - 1;
		wf_init_skybox_ray(env, &ray);
		wf_ray_skybox_hit(&ray);
		h = wf_ray_skybox_type(env, &ray);
		if (ray.side == 0)
			ray.w_hit = 0.5 + (h * ray.ray.y);
		else
			ray.w_hit = 0.5 + (h * ray.ray.x);
		wf_ray_skybox_trace(env, x, h, ray);
		x++;
	}
}
