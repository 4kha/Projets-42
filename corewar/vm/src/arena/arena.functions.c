/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:20:15 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:00:36 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		count_champions(t_a *arena)
{
	int	i;

	i = 0;
	if (!(arena->champ))
		return (0);
	while (arena->champ[i])
		i++;
	return (i);
}

int		count_pc(t_a *arena)
{
	int	i;

	i = 0;
	if (!(arena->pc))
		return (0);
	while (arena->pc[i])
		i++;
	return (i);
}

void	delete_processus(t_a *arena, t_p *processus)
{
	int	i;
	int	j;

	i = 0;
	if (!arena->pc)
		return ;
	while (arena->pc[i])
	{
		if (arena->pc[i] == processus)
		{
			j = i;
			free(processus);
			if (!arena->visual && arena->verbose)
				ft_printf("Processus killed\n");
			while (arena->pc[++j])
				arena->pc[j - 1] = arena->pc[j];
			arena->pc[j - 1] = NULL;
			i--;
		}
		i++;
	}
}
