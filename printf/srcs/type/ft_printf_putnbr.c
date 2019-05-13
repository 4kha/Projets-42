/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 00:43:52 by khtran            #+#    #+#             */
/*   Updated: 2018/01/02 09:35:27 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_base(int n, t_print_trigger arg)
{
	char	*str;

	if (arg.hexamaj)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	ft_putchar(str[n]);
}

void	ft_printf_putnbr_base(uintmax_t n, int base, t_print_trigger arg)
{
	if (n >= (uintmax_t)base)
	{
		ft_printf_putnbr_base(n / base, base, arg);
		ft_printf_putnbr_base(n % base, base, arg);
	}
	else
	{
		ft_putchar_base(n, arg);
	}
}

void	ft_printf_putnbr(uintmax_t n, t_print_trigger arg)
{
	ft_printf_putnbr_base(n, 10, arg);
}
