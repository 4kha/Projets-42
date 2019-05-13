/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:33:52 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 22:05:53 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	rearrange_colors(t_a *arena)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!arena->champ)
		return ;
	while (arena->champ[i + 1])
	{
		j = i + 1;
		while (arena->champ[j])
		{
			if (arena->champ[i]->color == arena->champ[j]->color)
			{
				if (arena->champ[j]->color_auto)
					arena->champ[j]->color = (arena->champ[j]->color + 1) % 6;
				else
					arena->champ[i]->color = (arena->champ[i]->color + 1) % 6;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
}

static void	rearrange_numbers(t_a *arena)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!arena->champ)
		return ;
	while (arena->champ[i + 1])
	{
		j = i + 1;
		while (arena->champ[j])
		{
			if (arena->champ[i]->number == arena->champ[j]->number)
			{
				if (arena->champ[j]->num_auto)
					arena->champ[j]->number = arena->champ[j]->number + 1;
				else
					arena->champ[i]->number = arena->champ[i]->number + 1;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
}

static void	realloc_arena_champions(t_a *a, t_c *c)
{
	int		i;

	i = count_champions(a);
	if (i + 1 > MAX_CHAMPIONS)
		error(a, 1, "Error : cannot create a new champion (max reached)");
	if (a->champ)
		a->champ = (t_c **)realloc((t_c **)a->champ, sizeof(t_c) * (i + 2));
	else
		a->champ = (t_c **)ft_memalloc(sizeof(t_c) * (i + 2));
	if (!(a->champ))
		error_champion(a, c, 1, "Error: cannot (re)malloc champion memory");
	a->champ[i] = c;
	a->champ[i + 1] = 0;
	if (i)
		rearrange_numbers(a);
}

t_c			*init_c(t_a *arena, int number, int color)
{
	t_c		*champion;

	champion = NULL;
	if (!(champion = (t_c *)ft_memalloc(sizeof(t_c))))
		return (NULL);
	champion->number = (number == -1) ? 0 : number;
	champion->num_auto = (number == -1) ? TRUE : FALSE;
	champion->color = (color == NO_COLOR) ? 1 : color;
	champion->color_auto = (color == NO_COLOR) ? TRUE : FALSE;
	realloc_arena_champions(arena, champion);
	rearrange_colors(arena);
	return (champion);
}

char		*get_color(t_c *c, int end)
{
	if (!c || c->color_auto)
		return ("");
	else if (end)
		return ("\x1b[0m");
	else if (c->color == RED)
		return ("\x1B[31m");
	else if (c->color == GREEN)
		return ("\x1B[32m");
	else if (c->color == YELLOW)
		return ("\x1B[33m");
	else if (c->color == BLUE)
		return ("\x1B[34m");
	else if (c->color == MAGENTA)
		return ("\x1B[35m");
	else if (c->color == CYAN)
		return ("\x1B[36m");
	else
		return ("");
}
