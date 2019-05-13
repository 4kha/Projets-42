/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:14:19 by rbechir           #+#    #+#             */
/*   Updated: 2018/03/13 15:41:37 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_hextoi(char *str)
{
	int	i;
	int	res;

	if (ft_strlen(str) > 2 && str[1] == 'x')
		i = 2;
	else
		i = 0;
	res = 0;
	while (str[i] && res >= 0)
	{
		res *= 16;
		if (ft_isdigit(str[i]))
			res += str[i] - 48;
		else if ((str[i] > 64 && str[i] < 71) || (str[i] > 96 && str[i] < 103))
		{
			if (str[i] < 71)
				res += str[i] - 65 + 10;
			else
				res += str[i] - 97 + 10;
		}
		else
			res = -1;
		i++;
	}
	return (res);
}

intmax_t	ft_atoimax(char *str)
{
	int			i;
	intmax_t	res;
	int			signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		signe = 44 - str[i];
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (signe * res);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		signe = 44 - str[i];
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (signe * res);
}
