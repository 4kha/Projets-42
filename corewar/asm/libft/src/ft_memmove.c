/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:57:32 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:23:02 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src_cp;
	char	*dst_cp;

	src_cp = (char*)src;
	dst_cp = (char*)dst;
	if (src_cp - dst_cp > 0)
	{
		i = 0;
		while (i < len)
		{
			dst_cp[i] = src_cp[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i + 1 >= 1)
		{
			dst_cp[i] = src_cp[i];
			i--;
		}
	}
	return (dst_cp);
}
