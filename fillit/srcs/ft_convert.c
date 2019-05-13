/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 23:22:41 by khtran            #+#    #+#             */
/*   Updated: 2017/11/22 15:43:35 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strtrim_fillit(char const *s)
{
	int		index;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = 0;
	index = 15;
	while ((s[index] == '.'))
		index--;
	len = index + 1;
	while (*s == '.')
	{
		s++;
		len--;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (ft_strncpy(str, s, len));
}

char	*ft_convert_one(char *string)
{
	int		index;
	char	*figure;
	char	*tmp;

	index = 0;
	figure = (char*)malloc(sizeof(char) * (16 + 1));
	if (figure == NULL)
		return (NULL);
	figure[16] = '\0';
	while (index < 16)
	{
		if (string[index] == '\n')
			string++;
		else
		{
			figure[index] = string[index];
			index++;
		}
	}
	tmp = ft_strtrim_fillit(figure);
	if (tmp == NULL)
		return (NULL);
	free(figure);
	return (tmp);
}

char	**ft_convert(char *string, int figure)
{
	char	**tab;
	char	*tmp1;
	int		index;

	tmp1 = string;
	tab = (char**)malloc(sizeof(char*) * (figure + 1));
	if (tab == NULL)
		return (NULL);
	tab[figure] = 0;
	index = 1;
	tab[0] = ft_convert_one(string);
	while (index < figure)
	{
		string = string + 21;
		tab[index] = ft_convert_one(string);
		index++;
	}
	free(tmp1);
	return (tab);
}
