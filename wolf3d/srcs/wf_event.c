/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:23:30 by khtran            #+#    #+#             */
/*   Updated: 2019/02/01 15:52:05 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		wf_pos_check(t_map *map, t_douxy pos, double hitx, double hity)
{
	double		x;
	double		y;

	x = (pos.x + hitx);
	y = (pos.y + hity);
	if (x >= 0 && y < map->max_y && y >= 0 && x < map->max_x
		&& map->map[(int)y][(int)x].wall == 0)
		return (1);
	return (0);
}

void	wf_pos_limit(t_map *map, t_douxy pos)
{
	t_douxy	tmp;

	tmp = (t_douxy){pos.x, map->pos_y};
	if (wf_pos_check(map, tmp, 0, 0)
			&& wf_pos_check(map, tmp, W_HB, -W_HB)
			&& wf_pos_check(map, tmp, -W_HB, -W_HB)
			&& wf_pos_check(map, tmp, W_HB, W_HB)
			&& wf_pos_check(map, tmp, -W_HB, W_HB))
		map->pos_x = pos.x;
	tmp = (t_douxy){map->pos_x, pos.y};
	if (wf_pos_check(map, tmp, 0, 0)
			&& wf_pos_check(map, tmp, W_HB, W_HB)
			&& wf_pos_check(map, tmp, W_HB, -W_HB)
			&& wf_pos_check(map, tmp, -W_HB, W_HB)
			&& wf_pos_check(map, tmp, -W_HB, -W_HB))
		map->pos_y = pos.y;
}

void	wf_event_rotation(t_env *env, Uint8 *event)
{
	double	tmp;

	if (event[SDL_SCANCODE_Q])
	{
		tmp = env->map->dir_x;
		env->map->dir_x = tmp * cos(ROT) + env->map->dir_y * -sin(ROT);
		env->map->dir_y = tmp * sin(ROT) + env->map->dir_y * cos(ROT);
		tmp = env->map->screen_x;
		env->map->screen_x = tmp * cos(ROT) + env->map->screen_y * -sin(ROT);
		env->map->screen_y = tmp * sin(ROT) + env->map->screen_y * cos(ROT);
	}
	if (event[SDL_SCANCODE_E])
	{
		tmp = env->map->dir_x;
		env->map->dir_x = tmp * cos(-ROT) + env->map->dir_y * -sin(-ROT);
		env->map->dir_y = tmp * sin(-ROT) + env->map->dir_y * cos(-ROT);
		tmp = env->map->screen_x;
		env->map->screen_x = tmp * cos(-ROT) + env->map->screen_y * -sin(-ROT);
		env->map->screen_y = tmp * sin(-ROT) + env->map->screen_y * cos(-ROT);
	}
}

void	wf_event_1(t_env *env, Uint8 *event, t_douxy *new_pos)
{
	if (event[SDL_SCANCODE_LEFT] || event[SDL_SCANCODE_A])
	{
		new_pos->x -= env->map->dir_y * SPEED;
		new_pos->y += env->map->dir_x * SPEED;
	}
	wf_event_rotation(env, event);
	if (event[SDL_SCANCODE_DOWN] || event[SDL_SCANCODE_LEFT]
			|| event[SDL_SCANCODE_RIGHT] || event[SDL_SCANCODE_UP]
			|| event[SDL_SCANCODE_A] || event[SDL_SCANCODE_W]
			|| event[SDL_SCANCODE_D] || event[SDL_SCANCODE_S])
		wf_pos_limit(env->map, *new_pos);
}

void	wf_event(t_env *env)
{
	Uint8	*event;
	t_douxy	new_pos;

	new_pos = (t_douxy){env->map->pos_x, env->map->pos_y};
	event = (Uint8*)SDL_GetKeyboardState(NULL);
	if (event[SDL_SCANCODE_UP] || event[SDL_SCANCODE_W])
	{
		new_pos.x += env->map->dir_x * SPEED;
		new_pos.y += env->map->dir_y * SPEED;
	}
	if (event[SDL_SCANCODE_RIGHT] || event[SDL_SCANCODE_D])
	{
		new_pos.x += env->map->dir_y * SPEED;
		new_pos.y -= env->map->dir_x * SPEED;
	}
	if (event[SDL_SCANCODE_DOWN] || event[SDL_SCANCODE_S])
	{
		new_pos.x -= env->map->dir_x * SPEED;
		new_pos.y -= env->map->dir_y * SPEED;
	}
	wf_event_1(env, event, &new_pos);
}
