/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:01:07 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:33:23 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;
	size_t			j;
	char			*cpy;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	if (!ft_isgreyspace(s[i]) && !ft_isgreyspace(s[j]))
	{
		if (!(cpy = (char*)malloc(sizeof(char) * ft_strlen(s))))
			return (NULL);
		return (ft_strcpy(cpy, s));
	}
	while (ft_isgreyspace(s[i]))
		i++;
	while (ft_isgreyspace(s[j]) && j > i)
		j--;
	if (i == j)
		return ("");
	len = (j - i + 1);
	return (ft_strsub(s, i, len));
}
