/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:42:53 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/18 16:11:13 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_pc(t_a *arena, int i)
{
	int	j;

	j = 0;
	if (!arena || !arena->pc)
		return (0);
	while (arena->pc[j])
	{
		if (arena->pc[j]->mem == i)
			return (1);
		j++;
	}
	return (0);
}

int		kbhit(void)
{
	int ch;

	ch = getch();
	if (ch != ERR)
	{
		ungetch(ch);
		return (1);
	}
	else
		return (0);
}
