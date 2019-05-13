/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:30:26 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 20:49:25 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		index;
	int		is_neg;

	index = 0;
	result = 0;
	is_neg = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_neg = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
		result = (result * 10) + (str[index++] - '0');
	if (result == -2147483648)
		return (-2147483648);
	return (is_neg * result);
}
