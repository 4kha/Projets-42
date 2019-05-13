/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:01:51 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:29:58 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	if (n > ft_strlen(s1))
		len = ft_strlen(s1);
	else
		len = n;
	if ((copy = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}
