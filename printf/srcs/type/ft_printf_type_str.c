/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 03:51:41 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 00:49:05 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_str_pont(size_t len, t_print_trigger arg)
{
	if (arg.trigger6 && !arg.trigger3 && arg.trigger2)
		ft_printf_diff(len, arg.taille, '0');
	if (arg.trigger6 && !arg.trigger3 && !arg.trigger2)
		ft_printf_diff(len, arg.taille, ' ');
}

int		ft_printf_type_str(size_t *index, t_print_trigger arg,
		va_list list)
{
	char	*str;
	size_t	len;

	if (arg.format == 3)
		return (ft_printf_type_wstr(index, arg, list));
	else
	{
		ft_putstrm(arg);
		str = va_arg(list, char*);
		if (str == NULL)
			str = "(null)";
		if (arg.trigger7)
			len = ft_min(arg.precision, ft_strlen(str));
		else
			len = ft_strlen(str);
		ft_printf_type_str_pont(len, arg);
		write(1, str, len);
		if (arg.trigger6 && arg.trigger3)
			ft_printf_diff(len, arg.taille, ' ');
		if (arg.trigger6)
			(*index) = (*index) + ft_max(len, arg.taille);
		else
			(*index) = (*index) + len;
	}
	return (0);
}
