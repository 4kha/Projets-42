/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 07:17:09 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 12:57:25 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_unsigned(size_t *index, uintmax_t nbr,
		t_print_trigger arg, char *pre)
{
	size_t		len1;
	size_t		len2;

	if (arg.trigger7)
		arg.trigger2 = 0;
	len1 = ft_printf_nbrlen(nbr, 10);
	len2 = ft_printf_nbrlen_cumul_base(nbr, arg, pre, 10);
	if (arg.trigger6 && !arg.trigger3 && arg.trigger2)
	{
		arg.precision = ft_max(arg.taille, len1);
		arg.trigger7 = 1;
		arg.trigger6 = 0;
	}
	if (arg.trigger6 && !arg.trigger3)
		ft_printf_diff(ft_max(len2, arg.precision), arg.taille, ' ');
	if (arg.trigger1 && pre != NULL)
		ft_putstrn(pre);
	if (arg.trigger7)
		ft_printf_diff(len1, arg.precision, '0');
	if (!(nbr == 0 && arg.precision == 0 && arg.trigger7))
		ft_printf_putnbr(nbr, arg);
	if (arg.trigger6 && arg.trigger3)
		ft_printf_diff(len2, arg.taille, ' ');
	(*index) += ft_max(len2, ft_max(arg.taille, arg.precision));
}

void	ft_printf_type_pre_unsigned(size_t *index, t_print_trigger arg,
		va_list list)
{
	uintmax_t	nbr;

	nbr = ft_printf_type_convert_unsigned(list, arg);
	ft_printf_type_unsigned(index, nbr, arg, NULL);
}
