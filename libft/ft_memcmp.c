/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:27:36 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 19:13:54 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dup1;
	unsigned char	*dup2;

	dup1 = (unsigned char*)s1;
	dup2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*dup1 != *dup2)
		{
			return (*dup1 - *dup2);
		}
		dup1++;
		dup2++;
		n--;
	}
	return (0);
}
