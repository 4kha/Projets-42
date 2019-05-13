/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:48:09 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 20:07:21 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*start;

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
