/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:36:25 by khtran            #+#    #+#             */
/*   Updated: 2018/05/17 03:51:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_add_pipe(t_room *dest, t_room *room, int repeat)
{
	t_list	*tmp;

	tmp = room->chemin;
	while (tmp)
	{
		if (tmp->content == dest)
			return ;
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(&dest, sizeof(t_room*))))
		ft_error(ERROR_MALLOC);
	ft_lstadd(&(room->chemin), tmp);
	if (repeat == 1)
		lem_in_add_pipe(room, dest, 0);
}

t_room	*lem_in_find_room(char *name, t_env *env)
{
	t_room		*current;

	current = (*env).room;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			current->status = -1;
			free(name);
			return (current);
		}
		current = current->next;
	}
	if (!(current = (t_room*)malloc(sizeof(t_room))))
		ft_error(ERROR_MALLOC);
	room_lstadd(&((*env).room), current);
	current->name = name;
	current->status = -1;
	current->chemin = NULL;
	return (current);
}

void	lem_in_room_exist_varset(t_room **first, t_room **second)
{
	*first = NULL;
	*second = NULL;
}

int		lem_in_room_exist(char *line, char *dest, t_env *env, int mode)
{
	t_room		*tmp;
	t_room		*first;
	t_room		*second;

	lem_in_room_exist_varset(&first, &second);
	tmp = (*env).room;
	while (tmp && (second == NULL || first == NULL))
	{
		if (first == NULL && ft_strcmp(tmp->name, line) == 0)
		{
			first = tmp;
			if (mode != 1)
				return (1);
		}
		else if (mode == 1 && second == NULL && ft_strcmp(tmp->name, dest) == 0)
			second = tmp;
		tmp = tmp->next;
	}
	if (mode == 1)
	{
		if (first == NULL || second == NULL)
			return (1);
		lem_in_add_pipe(first, second, 1);
	}
	return (0);
}

int		lem_in_find_pos(char *line, int x, int y, t_env *env)
{
	t_room		*current;
	int			tmp;

	tmp = 0;
	current = (*env).room;
	while (current)
	{
		if (current->status != -1
			&& current->x == x && current->y == y && tmp++ == 0)
			break ;
		current = current->next;
	}
	if (tmp == 1)
	{
		if (lem_in_room_exist(line, NULL, env, 2) == 1)
		{
			free(line);
			return (1);
		}
		free(current->name);
		current->name = ft_strdup(line);
		current->status = -1;
	}
	return (0);
}
