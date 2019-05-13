/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_atoi_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:22:02 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 20:46:54 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_letter(char c)
{
	int		index;
	char	*letter;

	index = 0;
	letter = "0123456789ABCDEF";
	while (letter[index])
	{
		if (c == letter[index])
			return (index);
		index++;
	}
	letter = "0123456789abcdef";
	index = 0;
	while (letter[index])
	{
		if (c == letter[index])
			return (index);
		index++;
	}
	return (0x00FFFFFF);
}

int		mlx_atoi_hexa(char *nb)
{
	int		index;
	int		result;

	result = 0;
	index = 0;
	while (nb[index] && nb[index] != ' ' && nb[index] != '\n')
	{
		result = result * 16;
		result = result + mlx_letter(nb[index]);
		index++;
	}
	return (result);
}

t_tab	mlx_atoi_at(char *nb, int at)
{
	t_tab	tab;
	int		check;

	mlx_tab_set(0, 0x00FFFFFF, &tab);
	check = 0;
	while (*nb)
	{
		if ((*nb >= '0' && *nb <= '9') || *nb == '-')
		{
			if (++check == at)
				tab.high = ft_atoi(nb);
			while (*nb && (*nb != ' ' && *nb != '\n'))
			{
				if (*nb == 'x' && check == at)
					tab.color = mlx_atoi_hexa(++nb);
				else
					nb++;
			}
			if (check == at)
				return (tab);
		}
		else
			nb++;
	}
	return (tab);
}
