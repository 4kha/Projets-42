/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:21:49 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 21:08:44 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		index;

	index = 0;
	if (min >= max)
		return (NULL);
	range = (int*)malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (NULL);
	while (min < max)
	{
		range[index] = min;
		min++;
		index++;
	}
	return (range);
}
