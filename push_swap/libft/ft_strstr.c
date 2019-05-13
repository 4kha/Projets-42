/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:52:45 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 13:42:13 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		finding;
	int		moving;
	char	*founded;

	moving = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[moving])
	{
		finding = 0;
		while (haystack[moving + finding] == needle[finding])
		{
			if (needle[finding + 1] == '\0')
			{
				founded = (char*)&haystack[moving];
				return (founded);
			}
			finding++;
		}
		moving++;
	}
	return (NULL);
}
