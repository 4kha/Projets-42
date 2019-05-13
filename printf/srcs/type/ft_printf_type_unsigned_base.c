/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_unsigned_base.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 04:48:00 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 13:06:45 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type_unsigned_hexa_pont(char *pre, t_print_trigger arg,
			size_t len2, int tri)
{
	if (arg.trigger6 && !arg.trigger3)
		ft_printf_diff(ft_max(len2, arg.precision), arg.taille, ' ');
	if (arg.trigger1 && pre != NULL)
		ft_putstrn(pre);
	if (arg.trigger7 && tri == 1)
		ft_printf_diff(len2, arg.precision, '0');
}

void	ft_printf_type_unsigned_hexa(size_t *index, uintmax_t nbr,
		t_print_trigger arg, char *pre)
{
	size_t		len1;
	size_t		len2;
	int			tri;

	tri = 0;
	if (arg.trigger7)
		arg.trigger2 = 0;
	len1 = ft_printf_nbrlen(nbr, 16);
	len2 = ft_printf_nbrlen_cumul_base(nbr, arg, pre, 16);
	if (arg.trigger6 && !arg.trigger3 && arg.trigger2)
	{
		tri = 1;
		arg.precision = ft_max(arg.taille, len1);
		arg.trigger7 = 1;
		arg.trigger6 = 0;
	}
	ft_printf_type_unsigned_hexa_pont(pre, arg, len2, tri);
	if (arg.trigger7 && tri == 0)
		ft_printf_diff(len1, arg.precision, '0');
	if (!(arg.precision == 0 && arg.trigger7 && nbr == 0))
		ft_printf_putnbr_base(nbr, 16, arg);
	if (arg.trigger6 && arg.trigger3)
		ft_printf_diff(len2, arg.taille, ' ');
	(*index) += ft_max(len2, ft_max(arg.taille, arg.precision));
}

void	ft_printf_type_pre_nbr_hexa(size_t *index, intmax_t nbr,
		t_print_trigger arg, char *pre)
{
	ft_printf_type_unsigned_hexa(index, nbr, arg, pre);
}
