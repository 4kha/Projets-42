/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:18 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:46:01 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrn(char const *c)
{
	if (c == NULL)
		return ;
	write(1, c, (ft_strlen(c)));
}

void	ft_putstrm(t_print_trigger arg)
{
	if (arg.stock == NULL)
		return ;
	ft_putstrn(arg.stock);
}

void	ft_putnwstr(wchar_t const *c, size_t len)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	if (c == NULL)
		return ;
	while (c[index] && count + ft_printf_wcount(c[index]) <= len)
	{
		count += ft_printf_wcount(c[index]);
		ft_putwchar(c[index]);
		index++;
	}
}
