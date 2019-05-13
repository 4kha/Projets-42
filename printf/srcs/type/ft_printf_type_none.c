/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_none.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 03:17:46 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 00:39:43 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_none(t_print_trigger arg, size_t *index)
{
	if (arg.trigger6 && !arg.trigger3)
	{
		if (arg.trigger2)
			ft_printf_diff(1, arg.taille, '0');
		else
			ft_printf_diff(1, arg.taille, ' ');
	}
	ft_putchar('%');
	if (arg.trigger6 && arg.trigger3)
		ft_printf_diff(1, arg.taille, ' ');
	(*index) = (*index) + ft_max(arg.taille, 1);
}
