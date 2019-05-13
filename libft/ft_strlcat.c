/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:36:51 by khtran            #+#    #+#             */
/*   Updated: 2017/11/09 17:19:26 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int					len;
	size_t				secure_len;
	int					index;
	size_t				seclen;

	secure_len = 0;
	index = 0;
	seclen = ft_strlen(src);
	len = ft_strlen(dst);
	if (size == 0)
		return (seclen);
	while (dst[secure_len] && secure_len < size)
		secure_len++;
	while (src[index] && secure_len < size - 1)
	{
		dst[index + len] = src[index];
		size--;
		index++;
	}
	dst[index + len] = 0;
	return (secure_len + seclen);
}
