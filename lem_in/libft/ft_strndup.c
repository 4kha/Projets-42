/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:34:58 by khtran            #+#    #+#             */
/*   Updated: 2018/05/15 08:46:05 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*start;
	char	*dest;

	dest = (char*)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		exit(0);
	dest[len] = 0;
	start = dest;
	while (len > 0)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = 0;
		len--;
	}
	return (start);
}
