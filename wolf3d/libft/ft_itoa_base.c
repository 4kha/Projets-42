/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:01:17 by exam              #+#    #+#             */
/*   Updated: 2018/05/15 07:30:41 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_complete(char *result, int value, int len, int base)
{
	int		index;

	index = 0;
	if (value < 0)
	{
		if (base == 10)
			result[index++] = '-';
		value = -value;
	}
	len--;
	while (len >= index)
	{
		result[len] = ft_hexlet(value % base);
		value = value / base;
		len--;
	}
	return (result);
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	int		len;
	int		index;

	if (base <= 1 || base >= 17)
		return (NULL);
	index = 0;
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (value == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen_base(value, base);
	result = (char*)malloc(sizeof(result) * (len + 1));
	if (result == NULL)
		exit(1);
	result[len] = 0;
	result = ft_itoa_complete(result, value, len, base);
	return (result);
}
