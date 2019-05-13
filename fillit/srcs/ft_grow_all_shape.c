/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow_all_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:48:56 by rbechir           #+#    #+#             */
/*   Updated: 2017/11/22 15:51:14 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_grow_all_shape(char **tab, int n)
{
	int	i;
	int j;

	if (n <= 0)
		return (tab);
	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			while (tab[i][j] == '#')
				j++;
			if (tab[i][j])
				if (!(tab[i] = ft_insert_char(tab[i], n, '.', j)))
					return (NULL);
			while (tab[i][j] == '.')
				j++;
		}
		i++;
	}
	return (tab);
}
