/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:46:16 by khtran            #+#    #+#             */
/*   Updated: 2018/06/22 01:57:24 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		exit(0);
	str[len] = 0;
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL && s1 != NULL)
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		exit(0);
	str[len] = 0;
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (s1)
		free(s1);
	return (str);
}
