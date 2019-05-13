/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:39:38 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 00:48:59 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_type_char(size_t *index, t_print_trigger arg, va_list list)
{
	int		c;
	int		len;
	char	*pre;

	if (arg.trigger2 == 1)
		pre = "0";
	else
		pre = " ";
	len = 1;
	if (arg.format == 3)
		return (ft_printf_type_wchar(index, arg, list));
	else
	{
		ft_putstrm(arg);
		if (arg.trigger7)
			arg.trigger2 = 0;
		c = va_arg(list, int);
		if (arg.trigger6 && !arg.trigger3)
			ft_printf_diff(len, arg.taille, *pre);
		ft_putchar(c);
		if (arg.trigger6 && arg.trigger3)
			ft_printf_diff(len, arg.taille, ' ');
		(*index) = (*index) + ft_max(len, arg.taille);
	}
	return (0);
}
