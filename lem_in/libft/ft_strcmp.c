/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:24:13 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 17:22:13 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*dup1;
	unsigned char	*dup2;

	dup1 = (unsigned char*)s1;
	dup2 = (unsigned char*)s2;
	while (*dup1 == *dup2 && (*dup1 != 0 || *dup2 != 0))
	{
		dup1++;
		dup2++;
	}
	return (*dup1 - *dup2);
}
