/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:35:47 by khtran            #+#    #+#             */
/*   Updated: 2017/11/22 16:26:57 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_have_place(char *str, char *figure)
{
	int		index;

	index = 0;
	while (figure[index])
	{
		if (str[index] == '\0')
			return (0);
		if (str[index] != '.' && figure[index] == '#')
		{
			return (2);
		}
		index++;
	}
	return (1);
}

void	ft_place(char *str, char *tetri, char symb)
{
	int		index;

	index = 0;
	while (tetri[index])
	{
		if (tetri[index] == '#')
			str[index] = symb;
		index++;
	}
}

int		ft_solve(char **tab, char *grid, int figure, int state)
{
	char	*tmp;
	int		ret;

	tmp = grid;
	if (figure <= state)
	{
		ft_putstr(grid);
		return (0);
	}
	while ((ret = ft_have_place(tmp, tab[state])) != 0)
	{
		if (ret == 1)
		{
			ft_place(tmp, tab[state], ('A' + state));
			if (ft_solve(tab, grid, figure, (state + 1)) == 0)
				return (0);
			ft_place(tmp, tab[state], '.');
		}
		tmp++;
	}
	return (1);
}

char	*ft_prepare(int size)
{
	char	*str;
	int		len;
	int		index;

	index = 0;
	len = (size + 1) * size;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (index < len)
	{
		if ((index + 1) % (size + 1) == 0 && index != 0)
			str[index] = '\n';
		else
			str[index] = '.';
		index++;
	}
	return (str);
}

int		ft_init(char **tab, int figure)
{
	char	*grid;
	int		size;

	size = 2;
	if (figure == 1 && ft_strcmp(tab[0], "##..##") == 0)
	{
		ft_putstr("AA\nAA\n");
		return (0);
	}
	while (size * size < figure * 4)
		size++;
	grid = ft_prepare(size);
	tab = ft_grow_all_shape(tab, size - 3);
	if (grid == NULL || tab == NULL)
		return (1);
	while (ft_solve(tab, grid, figure, 0) == 1)
	{
		free(grid);
		size++;
		grid = ft_prepare(size);
		ft_grow_all_shape(tab, 1);
	}
	free(grid);
	return (0);
}
