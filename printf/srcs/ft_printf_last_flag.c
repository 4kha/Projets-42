/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_last_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 01:51:08 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 03:05:55 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_nothing(char **string, size_t *index,
		t_print_trigger arg)
{
	char	pre;

	pre = ' ';
	if (arg.trigger6 == 1)
	{
		if (arg.trigger2)
			pre = '0';
		(*index) = (*index) + arg.taille;
		if (arg.trigger3 == 0)
			ft_printf_diff(1, arg.taille, pre);
		ft_putchar(**string);
		if (arg.trigger3 == 1)
			ft_printf_diff(1, arg.taille, ' ');
	}
	else
	{
		ft_putchar(**string);
		(*index) += 1;
	}
}

int		ft_printf_last_flag2(char **string, size_t *index,
		t_print_trigger arg, va_list list)
{
	if (**string == 'o')
		ft_printf_type_octal(index, arg, list);
	else if (**string == 'O')
		ft_printf_type_octal_long(index, arg, list);
	else if (**string == 'u')
		ft_printf_type_pre_unsigned(index, arg, list);
	else if (**string == 'U')
		ft_printf_type_long_unsigned(index, arg, list);
	else if (**string == 'x')
		ft_printf_type_hexa_s(index, arg, list);
	else if (**string == 'X')
		ft_printf_type_hexa_b(index, arg, list);
	else if (**string == 'b')
		ft_printf_type_bin(index, arg, list);
	else if (**string == 'B')
		ft_printf_type_bin_long(index, arg, list);
	else
		ft_printf_type_nothing(string, index, arg);
	return (0);
}

int		ft_printf_last_flag(char **string, size_t *index, t_print_trigger arg,
		va_list list)
{
	if (**string == 's')
		return (ft_printf_type_str(index, arg, list));
	else if (**string == 'c')
		return (ft_printf_type_char(index, arg, list));
	else if (**string == 'C')
		return (ft_printf_type_wchar(index, arg, list));
	else if (**string == 'S')
		return (ft_printf_type_wstr(index, arg, list));
	ft_putstrm(arg);
	if (**string == '%')
		ft_printf_type_none(arg, index);
	else if (**string == 'p')
		ft_printf_type_ptr(index, arg, list);
	else if (**string == 'd')
		ft_printf_type_int(index, arg, list);
	else if (**string == 'D')
		ft_printf_type_long(index, arg, list);
	else if (**string == 'i')
		ft_printf_type_int(index, arg, list);
	else
		return (ft_printf_last_flag2(string, index, arg, list));
	return (0);
}
