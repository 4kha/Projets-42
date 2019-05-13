/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:17:42 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 16:46:49 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		finding;
	int		moving;

	moving = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[moving] && len > 0)
	{
		finding = 0;
		while (haystack[moving + finding] == needle[finding]
				&& len - finding > 0)
		{
			if (needle[finding + 1] == 0)
				return ((char*)&haystack[moving]);
			finding++;
		}
		moving++;
		len--;
	}
	return (NULL);
}
