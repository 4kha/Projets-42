/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 01:22:08 by khtran            #+#    #+#             */
/*   Updated: 2018/05/15 07:34:27 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_isall(char *line, int (is_thing)(int elem), int mode)
{
	while (*line)
	{
		if (is_thing(*line) == mode)
			return (1);
		line++;
	}
	return (0);
}

int		ft_isstr(int elem, char *symbol)
{
	int		index;

	index = 0;
	while (elem != symbol[index++])
		if (!symbol[index])
			return (0);
	return (1);
}

int		ft_count_char(char *line, int elem)
{
	int		index;

	index = 0;
	while (*line)
	{
		if (*line == elem)
			index++;
		line++;
	}
	return (index);
}

int		ft_count_occur(char *line, int elem, int occur)
{
	int		index;

	index = 0;
	while (line[index] && occur != 0)
	{
		if (line[index] == elem)
			occur--;
		if (occur == 0)
			return (index);
		index++;
	}
	return (index);
}
