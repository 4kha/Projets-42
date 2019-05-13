/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 06:45:53 by khtran            #+#    #+#             */
/*   Updated: 2017/11/22 17:46:25 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_line(char **string, int *symbol)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		if ((*string)[index] != '.' && (*string)[index] != '#')
			return (1);
		if ((*string)[index] == '#')
			(*symbol)++;
		index++;
	}
	if ((*string)[index] != '\n')
		return (1);
	*string = *string + 5;
	return (0);
}

int		ft_check_four(char **string)
{
	int		index;
	int		symbol;

	symbol = 0;
	index = 0;
	while (index < 4)
	{
		if (ft_check_line(string, &symbol))
			return (1);
		index++;
	}
	if (symbol != 4)
		return (1);
	return (0);
}

int		ft_check_format(char *string, int *tetrimino)
{
	int		index;
	int		figure;

	figure = 0;
	index = 0;
	if (ft_check_four(&string))
		return (1);
	figure++;
	while (*string)
	{
		if (*string != '\n')
			return (1);
		string++;
		if (ft_check_four(&string))
			return (1);
		figure++;
	}
	(*tetrimino) = (*tetrimino) + figure;
	return (0);
}
