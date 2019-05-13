/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 05:21:24 by khtran            #+#    #+#             */
/*   Updated: 2018/01/02 07:28:00 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_long(size_t *index, t_print_trigger arg, va_list list)
{
	arg.format = 3;
	ft_printf_type_int(index, arg, list);
}

void	ft_printf_type_long_unsigned(size_t *index, t_print_trigger arg,
		va_list list)
{
	arg.format = 3;
	ft_printf_type_pre_unsigned(index, arg, list);
}
