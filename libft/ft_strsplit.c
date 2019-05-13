/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:02:25 by khtran            #+#    #+#             */
/*   Updated: 2017/11/12 13:37:27 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		index[3];
	char	**tab;

	if (s == NULL)
		return (NULL);
	index[2] = ft_strsp_c(s, c);
	index[1] = 0;
	while (*s == c)
		s++;
	if ((tab = (char**)malloc(sizeof(tab) * ((index[2]) + 1))) == NULL)
		return (NULL);
	tab[index[2]] = 0;
	while (index[1] < index[2])
	{
		index[0] = 0;
		tab[index[1]] = (char*)malloc(sizeof(char) * (ft_strsp_l(s, c) + 1));
		if (tab[index[1]] == NULL)
			return (NULL);
		while (*s != c && *s)
			tab[index[1]][(index[0])++] = *s++;
		tab[(index[1])++][(index[0])] = 0;
		while (*s == c)
			s++;
	}
	return (tab);
}
