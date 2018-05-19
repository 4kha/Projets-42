/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:21:11 by khtran            #+#    #+#             */
/*   Updated: 2018/05/19 03:03:26 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test_putpath(t_room *room)
{
	t_room	**tmp;
	t_list	*chemin;

	printf("chemins =  ");
	chemin = room->chemin;
	while (chemin != NULL)
	{
		tmp = chemin->content;
		printf("%s", (*tmp)->name);
		printf(" ; ");
		chemin = chemin->next;
	}
	printf("\n");
}

void	test_all_room(t_room *room)
{
	printf("Les rooms existante :\n");
	while (room != NULL)
	{
		printf("name    =  %s\nstatus  =  %i\n", room->name, room->status);
		test_putpath(room);
		printf("\n");
		room = room->next;
	}
	printf("=========================\n");
}

void	lem_in_freeroom(t_room *room)
{
	t_list	*tmp;
	t_list	*start;
	t_room	*room2;

	while (room != NULL)
	{
		room2 = room;
		free(room->name);
		ft_lstfree(room->chemin);
		room = room->next;
		free(room2);
	}
}

void	lem_in_freelist(t_list *thing)
{
	t_room **room;
	t_list	*start;

	start = thing;
	while (thing != NULL)
	{
		room = thing->content;
		printf("%s->", (*room)->name);
		thing = thing->next;
	}
	printf("\n");
	ft_lstfree(start);
}

void	lem_in_freeway(t_list *list)
{
	t_list	**tmp1;
	t_room	*room;
	t_list	*start;

	start = list;
	while (list != NULL)
	{
		tmp1 = list->content;
		printf("len = %d : ", list->content_size);
		lem_in_freelist(*tmp1);
		list = list->next;
	}
	ft_lstfree(start);
}

void	lem_in_set_env(t_env *env)
{
	(*env).nbr_ant = -1;
	(*env).trigger = 0;
	(*env).m_start = NULL;
	(*env).m_end = NULL;
	(*env).mode = 0;
}

int		main(int ac, char *av[])
{
	int		ret;
	char	*line;
	t_env	env;

	lem_in_set_env(&env);
	while ((ret = get_next_line(0, &line)) == 1)
	{
		if (env.nbr_ant == -1)
		{
			if (lem_in_nbrant(line, &env) == 1)
				break ;
		}
		else
		{
			if (lem_in_parser(line, &env) == 1)
			{
				free(line);
				break ;
			}
		}
//		lem_in_all_room(env.room);
		free(line);
	}
	if (ret == 0)
		free(line);
//	test_all_room(env.room);
	lem_in_solve(&env);
//	exit (0);
//	while(1);
	return (0);
}
