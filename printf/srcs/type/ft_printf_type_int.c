/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 03:32:26 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 12:57:09 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_pre_nbr(size_t *index, intmax_t nbr,
		t_print_trigger arg, char *pre)
{
	size_t		len;

	len = ft_printf_nbrlen_cumul(nbr, arg, pre) + ft_strlen(pre);
	(*index) += ft_strlen(pre);
	if (arg.trigger6 && !arg.trigger2 && !arg.trigger3)
	{
		ft_printf_diff(len, arg.taille, ' ');
		arg.taille -= ft_strlen(pre);
		arg.trigger6 = 0;
	}
	else if (arg.trigger6)
		arg.taille -= ft_strlen(pre);
	ft_putstrn(pre);
	if (*pre != ' ')
		arg.trigger1 = 0;
	ft_printf_type_unsigned(index, nbr, arg, pre);
}

void	ft_printf_type_int(size_t *index, t_print_trigger arg, va_list list)
{
	intmax_t	nbr;
	char		*pre;

	nbr = ft_printf_type_convert_int(list, arg);
	if (arg.trigger7)
		arg.trigger2 = 0;
	if (nbr < 0 || arg.trigger4 || arg.trigger5)
	{
		if (nbr < 0)
		{
			pre = "-";
			nbr = -nbr;
		}
		else if (arg.trigger4)
			pre = "+";
		else if (arg.trigger5)
			pre = " ";
		else
			pre = "";
		ft_printf_type_pre_nbr(index, nbr, arg, pre);
	}
	else
		ft_printf_type_unsigned(index, nbr, arg, "");
}
