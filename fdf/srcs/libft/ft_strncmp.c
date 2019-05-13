/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:29:26 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 17:21:36 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dup1;
	unsigned char	*dup2;

	dup1 = (unsigned char*)s1;
	dup2 = (unsigned char*)s2;
	if (n == 0)
	{
		return (0);
	}
	while (*dup1 == *dup2 && n != 0 && n - 1 > 0 && (*dup1 != 0 || *dup2 != 0))
	{
		dup1++;
		dup2++;
		n--;
	}
	return (*dup1 - *dup2);
}
