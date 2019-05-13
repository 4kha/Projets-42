/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:55:44 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/13 14:06:53 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_cat;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size > len_dst)
	{
		len_cat = size - len_dst - 1;
		if (len_cat > 0)
			dst = ft_strncat(dst, src, len_cat);
		return (ft_strlen(src) + len_dst);
	}
	else
		return (ft_strlen(src) + size);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned int	j;

	i = ft_strlen(s1);
	j = 0;
	while (j < n && s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
