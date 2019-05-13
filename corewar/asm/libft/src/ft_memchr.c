/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:16:29 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:23:27 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cp;
	size_t			i;

	i = 0;
	s_cp = (unsigned char*)s;
	while (i < n)
	{
		if (s_cp[i] == (unsigned char)c)
			return (s_cp + i);
		i++;
	}
	return (NULL);
}
