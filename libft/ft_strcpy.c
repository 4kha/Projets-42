/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:42:36 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 15:47:53 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		index1;

	index1 = 0;
	while (src[index1])
	{
		dest[index1] = src[index1];
		index1++;
	}
	dest[index1] = src[index1];
	return (dest);
}
