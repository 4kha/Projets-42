/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 04:41:19 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 09:53:06 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_printf_nbrlen(uintmax_t nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
	{
		return (1);
	}
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

size_t		ft_printf_nbrlen_cumul_base(uintmax_t nbr, t_print_trigger arg,
		char *pre, int base)
{
	size_t		prelen;
	size_t		postlen;

	prelen = ft_printf_nbrlen(nbr, base);
	if (nbr == 0 && arg.trigger7 && arg.precision == 0)
		postlen = 0;
	else if (arg.trigger7)
		postlen = ft_max(prelen, arg.precision);
	else
		postlen = prelen;
	if (arg.trigger1 && pre != NULL)
		postlen += ft_strlen(pre);
	return (postlen);
}

size_t		ft_printf_nbrlen_cumul(uintmax_t nbr, t_print_trigger arg,
		char *pre)
{
	size_t		prelen;
	size_t		postlen;

	prelen = ft_printf_nbrlen(nbr, 10);
	if (nbr == 0 && arg.trigger7 && arg.precision == 0)
		postlen = 0;
	else if (arg.trigger7)
		postlen = ft_max(prelen, arg.precision);
	else
		postlen = prelen;
	if (arg.trigger1 && pre != NULL)
		postlen += ft_strlen(pre);
	return (postlen);
}
