/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:13:38 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 21:01:18 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = src[len];
	return (dup);
}
