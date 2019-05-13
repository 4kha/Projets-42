/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 04:30:26 by khtran            #+#    #+#             */
/*   Updated: 2018/01/02 16:10:07 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

size_t	ft_max_neg(int num, int num2)
{
	if (num > num2)
		return (num);
	return (num2);
}

size_t	ft_max(size_t num, size_t num2)
{
	if (num > num2)
		return (num);
	return (num2);
}

size_t	ft_min(size_t num, size_t num2)
{
	if (num > num2)
		return (num2);
	return (num);
}
