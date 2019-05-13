/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:52:58 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/25 19:23:18 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_offset(t_print *wal)
{
	int		i;
	int		j;

	i = wal->start_f;
	j = i;
	while (j < wal->end_f)
	{
		if (wal->format[j] == '$')
		{
			while (i < j)
			{
				if (!(ft_isdigit(wal->format[i])))
					return (-1);
				i++;
			}
			return (j - wal->start_f + 1);
		}
		j++;
	}
	return (0);
}

int		ft_check_flag(t_print *wal)
{
	int		i;
	int		j;
	int		len;

	i = wal->start_f + wal->offset;
	len = 0;
	while (i <= wal->end_f && !(wal->format[i] > 48 && wal->format[i] < 58)
			&& wal->format[i] != '.')
	{
		j = 0;
		while (j <= 5)
		{
			if (wal->format[i] == wal->flags[j])
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

int		ft_check_width(t_print *wal)
{
	int		i;
	int		len;

	i = wal->start_f + wal->offset + wal->flag;
	len = 0;
	while (ft_isdigit(wal->format[i]))
	{
		i++;
		len++;
	}
	return (len);
}

int		ft_check_precision(t_print *wal)
{
	int		i;
	int		len;

	i = wal->start_f + wal->offset + wal->flag + wal->width;
	len = 0;
	if (wal->format[i] == '.')
	{
		i++;
		len++;
		while (ft_isdigit(wal->format[i]))
		{
			i++;
			len++;
		}
	}
	return (len);
}

int		ft_check_modifier(t_print *wal)
{
	int		i;
	int		j;
	int		len;

	i = wal->start_f + wal->offset + wal->flag + wal->width + wal->precision;
	len = 0;
	while (i < wal->end_f)
	{
		j = 6;
		while (j <= 10)
		{
			if (wal->format[i] == wal->flags[j])
				len++;
			j++;
		}
		i++;
	}
	if (len > 2 || (len == 2 && wal->format[i - 2] != wal->format[i - 1]))
		return (-1);
	return (len);
}
