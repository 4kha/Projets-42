/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 07:35:51 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 09:06:51 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_hexa_s(size_t *index, t_print_trigger arg, va_list list)
{
	uintmax_t	nbr;
	char		*pref;

	pref = "";
	nbr = ft_printf_type_convert_unsigned(list, arg);
	if (arg.trigger1 && nbr != 0)
		pref = "0x";
	arg.hexamaj = 0;
	ft_printf_type_pre_nbr_hexa(index, nbr, arg, pref);
}

void	ft_printf_type_hexa_b(size_t *index, t_print_trigger arg, va_list list)
{
	uintmax_t	nbr;
	char		*pref;

	pref = "";
	arg.hexamaj = 1;
	nbr = ft_printf_type_convert_unsigned(list, arg);
	if (arg.trigger1 && nbr != 0)
		pref = "0X";
	ft_printf_type_pre_nbr_hexa(index, nbr, arg, pref);
}
