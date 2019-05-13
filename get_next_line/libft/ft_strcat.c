/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:12:31 by khtran            #+#    #+#             */
/*   Updated: 2017/11/08 12:34:18 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(s1);
	while (s2[index])
	{
		s1[index + len] = s2[index];
		index++;
	}
	s1[index + len] = s2[index];
	return (s1);
}
