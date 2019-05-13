/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 23:29:58 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 01:03:59 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_type_wchar(size_t *index, t_print_trigger arg, va_list list)
{
	int		len;
	wchar_t	c;
	char	*pre;
	int		ret;

	if (arg.trigger2 == 1)
		pre = "0";
	else
		pre = " ";
	if (arg.trigger7)
		arg.trigger2 = 0;
	c = va_arg(list, wint_t);
	if ((ret = ft_printf_wcount_error(c)) == -1)
		return (-1);
	ft_putstrm(arg);
	len = ft_printf_wcount(c);
	if (arg.trigger6 && !arg.trigger3)
		ft_printf_diff(len, arg.taille, *pre);
	ft_putwchar(c);
	if (arg.trigger6 && arg.trigger3)
		ft_printf_diff(len, arg.taille, ' ');
	(*index) = (*index) + ft_max(len, arg.taille);
	return (0);
}
