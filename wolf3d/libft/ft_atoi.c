/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:30:26 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 17:55:49 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	result;
	int			index;
	int			is_neg;

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
	{
		result = (result * 10) + (str[index++] - '0');
		if ((result > 2147483647 && is_neg == 1)
				|| (result > 2147483648 && is_neg == -1))
			ft_error("Error : int_max overloaded\n");
	}
	return (is_neg * result);
}
