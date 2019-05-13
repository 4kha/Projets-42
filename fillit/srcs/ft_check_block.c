/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:08:21 by khtran            #+#    #+#             */
/*   Updated: 2017/11/22 15:43:54 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_block(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (ft_strcmp(tab[i], "##...#...#") != 0
		&& ft_strcmp(tab[i], "#...#...##") != 0
		&& ft_strcmp(tab[i], "###.#") != 0 && ft_strcmp(tab[i], "##..##") != 0
		&& ft_strcmp(tab[i], "#...##...#") != 0
		&& ft_strcmp(tab[i], "##.##") != 0 && ft_strcmp(tab[i], "##...##") != 0
		&& ft_strcmp(tab[i], "#..##..#") != 0
		&& ft_strcmp(tab[i], "####") != 0 && ft_strcmp(tab[i], "#.###") != 0
		&& ft_strcmp(tab[i], "#...#...#...#") != 0
		&& ft_strcmp(tab[i], "#...##..#") != 0
		&& ft_strcmp(tab[i], "###..#") != 0
		&& ft_strcmp(tab[i], "#..##...#") != 0
		&& ft_strcmp(tab[i], "#..###") != 0
		&& ft_strcmp(tab[i], "##..#...#") != 0
		&& ft_strcmp(tab[i], "###...#") != 0
		&& ft_strcmp(tab[i], "#...#..##") != 0
		&& ft_strcmp(tab[i], "#...###") != 0)
			return (1);
		i++;
	}
	return (0);
}
