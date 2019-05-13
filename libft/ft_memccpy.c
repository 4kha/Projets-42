/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:28:43 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 09:48:39 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destdup;
	unsigned char	*srcdup;

	destdup = (unsigned char*)dest;
	srcdup = (unsigned char*)src;
	while (n > 0)
	{
		if (*srcdup == (unsigned char)c)
		{
			*destdup++ = *srcdup++;
			return (destdup);
		}
		*destdup++ = *srcdup++;
		n--;
	}
	return (NULL);
}
