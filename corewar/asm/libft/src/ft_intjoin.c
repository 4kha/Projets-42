/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:23:31 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/14 04:26:22 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	*ft_intjoin(int *nb1, int *nb2, int size1, int size2)
{
	int		i;
	int		j;
	int		*nb;

	if (!nb1 || !nb2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(nb = (int*)malloc(sizeof(int) * (size1 + size2))))
		return (NULL);
	while (i < size1)
		nb[j++] = nb1[i++];
	i = 0;
	while (i < size2)
		nb[j++] = nb2[i++];
	free(nb1);
	free(nb2);
	return (nb);
}
