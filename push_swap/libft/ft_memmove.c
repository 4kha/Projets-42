/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:54:29 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 19:59:45 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*destdup;
	unsigned char		*srcdup;
	size_t				lencpy;

	destdup = (unsigned char*)dest;
	srcdup = (unsigned char*)src;
	lencpy = 0;
	if (dest != src)
	{
		if (dest < src)
			while (lencpy < len)
			{
				destdup[lencpy] = srcdup[lencpy];
				lencpy++;
			}
		else
			while (len > 0)
			{
				destdup[len - 1] = srcdup[len - 1];
				len--;
			}
	}
	return (dest);
}
