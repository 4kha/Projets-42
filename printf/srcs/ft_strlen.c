/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:46:50 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:24:36 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_wcount(wchar_t var)
{
	if (var <= 0x7F || (var <= 255 && MB_CUR_MAX < 2))
		return (1);
	else if (var <= 0x7FF)
		return (2);
	else if (var <= 0xFFFF)
		return (3);
	else if (var <= 0x10FFFF)
		return (4);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t		ft_strwlen(const wchar_t *s)
{
	size_t		len;
	size_t		index;

	index = 0;
	len = 0;
	while (s[index])
	{
		len = len + ft_printf_wcount(s[index]);
		index++;
	}
	return (len);
}

size_t		ft_strwlen_cut(const wchar_t *s, size_t cut)
{
	size_t		len;
	size_t		index;

	index = 0;
	len = 0;
	while (s[index] && len + ft_printf_wcount(s[index]) <= cut)
	{
		len = len + ft_printf_wcount(s[index]);
		index++;
	}
	return (len);
}
