/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:53:47 by khtran            #+#    #+#             */
/*   Updated: 2017/11/12 12:33:46 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		index;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = 0;
	index = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[index])
		index++;
	index--;
	while ((s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
			&& index > 0)
		index--;
	index++;
	while (len < index)
		len++;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = 0;
	str = ft_strncpy(str, s, len);
	return (str);
}
