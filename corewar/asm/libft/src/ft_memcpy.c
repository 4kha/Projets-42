/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:58:36 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:22:47 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_cp;
	unsigned char	*dst_cp;

	i = 0;
	src_cp = (unsigned char*)src;
	dst_cp = (unsigned char*)dst;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		i++;
		if (src_cp[i - 1] == (unsigned char)c)
			return (dst_cp + i);
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_cp;
	char	*dst_cp;

	i = 0;
	src_cp = (char*)src;
	dst_cp = (char*)dst;
	while (i < n)
	{
		dst_cp[i] = src_cp[i];
		i++;
	}
	return (dst);
}
