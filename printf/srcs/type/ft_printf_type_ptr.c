/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 23:16:52 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 10:19:16 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_ptr(size_t *index, t_print_trigger arg, va_list list)
{
	uintmax_t	ptr;

	arg.format = 6;
	if (arg.trigger7)
	{
		arg.trigger2 = 0;
	}
	arg.hexamaj = 0;
	arg.trigger1 = 1;
	ptr = ft_printf_type_convert_unsigned(list, arg);
	ft_printf_type_pre_nbr_hexa(index, ptr, arg, "0x");
}
