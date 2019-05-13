/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:16:39 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 15:27:14 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dup;

	dup = (unsigned char*)s;
	while (n > 0)
	{
		if (*dup == (unsigned char)c)
		{
			return ((void*)dup);
		}
		dup++;
		n--;
	}
	return (NULL);
}
