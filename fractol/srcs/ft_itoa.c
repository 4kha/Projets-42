/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:01:17 by exam              #+#    #+#             */
/*   Updated: 2017/12/21 16:54:49 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int		ft_lenght(int value)
{
	int		len;

	len = 0;
	if (value == 0)
	{
		len = 1;
	}
	if (value < 0)
	{
		value = -value;
		len = 1;
	}
	while (value != 0)
	{
		len++;
		value = value / 10;
	}
	return (len);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*dup;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	dup = (char*)malloc(sizeof(dup) * (len + 1));
	if (dup == NULL)
	{
		ft_putstr("Malloc failed > ft_strdup\n");
		exit(1);
	}
	dup[len] = 0;
	len = 0;
	while (s1[len])
	{
		dup[len] = s1[len];
		len++;
	}
	return (dup);
}

char	*ft_calcul(int len, int index, int value, char *result)
{
	if (value < 0)
	{
		result[index++] = '-';
		value = -value;
	}
	len--;
	while (len >= index)
	{
		result[len] = (value % 10) + '0';
		value = value / 10;
		len--;
	}
	return (result);
}

char	*ft_itoa(int value)
{
	char	*result;
	int		len;
	int		index;

	len = ft_lenght(value);
	if (len > 7)
		return (ft_strdup("Too big"));
	index = 0;
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	if (value == 0)
		return (ft_strdup("0"));
	result = (char*)malloc(sizeof(result) * (len + 1));
	if (result == NULL)
	{
		ft_putstr("Malloc failed > ft_itoa\n");
		exit(1);
	}
	result[len] = 0;
	return (ft_calcul(len, index, value, result));
}
