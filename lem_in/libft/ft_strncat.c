/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:20:30 by khtran            #+#    #+#             */
/*   Updated: 2017/11/07 19:14:29 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(s1);
	while (s2[index] && n > 0)
	{
		s1[index + len] = s2[index];
		index++;
		n--;
	}
	s1[index + len] = 0;
	return (s1);
}
