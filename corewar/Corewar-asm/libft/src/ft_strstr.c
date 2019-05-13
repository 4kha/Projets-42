/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:15:18 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:21:52 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	else
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (needle[j] == haystack[i + j] && i + j <= len)
			{
				if (needle[j + 1] == '\0')
					return ((char*)haystack + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	else
	{
		while (haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && needle[j])
			{
				if (needle[j + 1] == '\0')
					return ((char*)haystack + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
