/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:14:08 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:23:50 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*ptr_cp;
	size_t	i;

	i = 0;
	if (!(ptr = (void*)malloc(size)))
		return (NULL);
	ptr_cp = (char*)ptr;
	while (i < size)
	{
		ptr_cp[i] = '\0';
		i++;
	}
	return (ptr);
}
