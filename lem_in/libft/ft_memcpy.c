/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:18:46 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 09:28:12 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char*)dest;
	srccpy = (unsigned char*)src;
	while (n > 0)
	{
		*destcpy++ = *srccpy++;
		n--;
	}
	return (dest);
}
