/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:47:06 by rbechir           #+#    #+#             */
/*   Updated: 2018/04/10 20:05:53 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_filltab(char **tab, char const *s, char c, size_t len_tab)
{
	int		i;
	size_t	word;
	size_t	len_w;

	i = 0;
	word = 0;
	while (word < len_tab)
	{
		while (s[i] == c)
			i++;
		len_w = 0;
		while (s[i + len_w] != c && s[i + len_w])
			len_w++;
		tab[word] = ft_strsub(s, i, len_w);
		i += len_w;
		word++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	len_tab;

	i = 0;
	len_tab = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			len_tab++;
		while (s[i] != c && s[i])
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (len_tab + 1))))
		return (NULL);
	tab[len_tab] = NULL;
	ft_filltab(tab, s, c, len_tab);
	return (tab);
}
