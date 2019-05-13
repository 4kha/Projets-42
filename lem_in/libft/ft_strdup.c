/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:45:23 by khtran            #+#    #+#             */
/*   Updated: 2018/04/30 15:12:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		index;

	index = 0;
	dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		exit(0);
	while (s1[index])
	{
		dup[index] = s1[index];
		index++;
	}
	dup[index] = s1[index];
	return (dup);
}
