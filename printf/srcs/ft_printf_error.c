/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 04:53:51 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:45:17 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_wcount_error(wint_t var)
{
	int		ret;

	if (var == 0xd800 || var > 0x10ffff || var == 0xdb02 || var < 0
			|| var == 0xdfff)
		return (-1);
	ret = ft_printf_wcount(var);
	if (ret == -1 || MB_CUR_MAX < ret)
		return (-1);
	return (0);
}

int		ft_printf_wstr_count_error(wchar_t *var, size_t size)
{
	int		ret;
	size_t	index;

	index = 0;
	ret = 0;
	while (var != NULL && *var && ret == 0
			&& index + ft_printf_wcount(*var) <= size)
	{
		index += ft_printf_wcount(*var);
		ret = ft_printf_wcount_error(*var);
		var++;
	}
	return (ret);
}
