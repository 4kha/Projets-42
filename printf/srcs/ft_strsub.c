/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:40:10 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 00:43:46 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	plus;

	index = 0;
	plus = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		return (NULL);
	while (s[start + plus] && plus < len)
		plus++;
	str = (char*)malloc((plus + 1));
	if (str == NULL)
		return (NULL);
	str[plus] = 0;
	while (index < plus)
	{
		str[index] = s[start + index];
		index++;
	}
	return (str);
}
