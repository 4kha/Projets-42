/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_roomft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 09:00:17 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 10:15:37 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_lstadd(t_room **alst, t_room *new)
{
	new->next = (*alst);
	*alst = new;
}

void	ft_lstfree_safecontent(t_list *to_free)
{
	t_list			*tmp;

	while (to_free != NULL)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
}

void	lem_in_putpath(t_room *room)
{
	t_room	**tmp;
	t_list	*chemin;

	ft_putstr("chemins    =  ");
	chemin = room->chemin;
	while (chemin != NULL)
	{
		tmp = chemin->content;
		ft_putstr((*tmp)->name);
		chemin = chemin->next;
		if (chemin != NULL)
			ft_putstr(" ; ");
	}
	ft_putstr("\n");
}

void	lem_in_all_room(t_room *room)
{
	ft_putstr("Les rooms existante :\n");
	while (room != NULL)
	{
		ft_putstr("name       =  ");
		ft_putendl(room->name);
		ft_putstr("position x =  ");
		ft_putnbr(room->x);
		ft_putstr("\nposition y =  ");
		ft_putnbr(room->y);
		ft_putstr("\n");
		lem_in_putpath(room);
		ft_putstr("\n");
		room = room->next;
	}
}

int		ft_strncmp(const char *s1, const char *s2, int max)
{
	int				index;
	unsigned char	*dup1;
	unsigned char	*dup2;

	index = 1;
	dup1 = (unsigned char*)s1;
	dup2 = (unsigned char*)s2;
	while (*dup1 == *dup2 && (*dup1 != 0 || *dup2 != 0) && index < max)
	{
		dup1++;
		dup2++;
		index++;
	}
	return (*dup1 - *dup2);
}
