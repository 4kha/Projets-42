/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:32:19 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/04 17:23:31 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_insert_char(char *str, int n, char c, int pos)
{
	char	*str_new;
	int		i;
	int		j;

	if (!(str_new = (char*)malloc(sizeof(char) * (ft_strlen(str) + n + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < pos)
	{
		str_new[i] = str[j];
		i++;
		j++;
	}
	while (i < j + n)
		str_new[i++] = c;
	while (str[j])
	{
		str_new[i] = str[j];
		i++;
		j++;
	}
	str_new[i] = '\0';
	free(str);
	return (str_new);
}
