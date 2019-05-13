/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_wstr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 05:01:45 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:56:02 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_wstr_pont(size_t len, t_print_trigger arg)
{
	if (arg.trigger6 && !arg.trigger3 && arg.trigger2)
		ft_printf_diff(len, arg.taille, '0');
	if (arg.trigger6 && !arg.trigger3 && !arg.trigger2)
		ft_printf_diff(len, arg.taille, ' ');
}

void	ft_printf_type_wstr_pont2(size_t len, t_print_trigger arg,
		size_t *index)
{
	if (arg.trigger6)
		(*index) = (*index) + ft_max(len, arg.taille);
	else
		(*index) = (*index) + len;
}

int		ft_printf_type_wstr(size_t *index, t_print_trigger arg,
		va_list list)
{
	wchar_t	*str;
	size_t	len;

	str = va_arg(list, wchar_t*);
	if (str != NULL && arg.trigger7)
		len = ft_min(ft_strwlen_cut(str, arg.precision), ft_strwlen(str));
	else if (str != NULL)
		len = ft_strwlen(str);
	if (str != NULL && ft_printf_wstr_count_error(str, len) == -1)
		return (-1);
	ft_putstrm(arg);
	if (str == NULL)
	{
		ft_putstrn("(null)");
		(*index) += 6;
		return (0);
	}
	ft_printf_type_wstr_pont(len, arg);
	ft_putnwstr(str, len);
	if (arg.trigger6 && arg.trigger3)
		ft_printf_diff(len, arg.taille, ' ');
	ft_printf_type_wstr_pont2(len, arg, index);
	return (0);
}
