/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_convert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 00:10:41 by khtran            #+#    #+#             */
/*   Updated: 2018/01/02 02:26:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_printf_type_convert_unsigned(va_list list,
		t_print_trigger arg)
{
	uintmax_t	nbr;

	nbr = va_arg(list, uintmax_t);
	if (arg.format == 1)
		nbr = (unsigned char)nbr;
	else if (arg.format == 2)
		nbr = (unsigned short int)nbr;
	else if (arg.format == 3)
		nbr = (unsigned long int)nbr;
	else if (arg.format == 4)
		nbr = (unsigned long long int)nbr;
	else if (arg.format == 5)
		nbr = (uintmax_t)nbr;
	else if (arg.format == 6)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

intmax_t		ft_printf_type_convert_int(va_list list,
		t_print_trigger arg)
{
	intmax_t	nbr;

	nbr = va_arg(list, intmax_t);
	if (arg.format == 1)
		nbr = (char)nbr;
	else if (arg.format == 2)
		nbr = (short int)nbr;
	else if (arg.format == 3)
		nbr = (long int)nbr;
	else if (arg.format == 4)
		nbr = (long long int)nbr;
	else if (arg.format == 5)
		nbr = (intmax_t)nbr;
	else if (arg.format == 6)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
