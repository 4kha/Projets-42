/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:31:55 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:24:08 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
