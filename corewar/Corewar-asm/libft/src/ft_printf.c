/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:58:43 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/03 18:25:45 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_all(t_print *wal)
{
	int		len;

	if ((wal->offset = ft_check_offset(wal)) < 0)
		return (-1);
	wal->flag = ft_check_flag(wal);
	wal->width = ft_check_width(wal);
	wal->precision = ft_check_precision(wal);
	if ((wal->modifier = ft_check_modifier(wal)) < 0)
		return (-1);
	len = wal->offset + wal->flag + wal->width + wal->precision + wal->modifier;
	if ((wal->start_f + len) == wal->end_f)
		return (len);
	else
		return (-1);
}

static int	ft_check_conv(t_print *wal, int i)
{
	int		j;

	wal->start_f = i;
	while (wal->format[i] && !wal->end_f)
	{
		j = 12;
		while (wal->flags[j] && !wal->end_f)
		{
			if (wal->format[i] == wal->flags[j])
				wal->end_f = i;
			j++;
		}
		i++;
	}
	if (!wal->end_f)
		return (0);
	return (ft_check_all(wal) + 1);
}

static int	ft_search_flags(t_print *wal, int i)
{
	int		j;
	int		ret;
	char	*sub;
	char	*tmp;

	j = i;
	ret = 0;
	while (wal->format[i] && wal->format[i] != '%')
		i++;
	if (!(sub = ft_strsub(wal->format, j, i - j)))
		return (0);
	tmp = wal->buff;
	if (!(wal->buff = ft_strjoin(wal->buff, sub)))
		return (0);
	free(sub);
	free(tmp);
	if (wal->format[i])
	{
		if ((ret = ft_check_conv(wal, i + 1)))
			i += ret + 1;
		else
			i = 0;
	}
	return (i);
}

static int	ft_init_t_print(t_print *wal, int all)
{
	if (all)
	{
		if (!(wal->flags = ft_strdup("0#- +'hljzL*diouxXDOUCcSspneEfFgGaA%")))
			return (0);
		if (!(wal->buff = ft_strdup("\0")))
			return (0);
		wal->len = 0;
	}
	wal->start_f = 0;
	wal->end_f = 0;
	wal->offset = 0;
	wal->flag = 0;
	wal->width = 0;
	wal->precision = 0;
	wal->modifier = 0;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_print		*wal;
	int			i;

	i = 0;
	if (!(wal = (t_print*)malloc(sizeof(t_print))))
		return (-1);
	va_start(wal->args, format);
	if (!(wal->format = ft_strdup(format)))
		return (-1);
	if (!(ft_init_t_print(wal, 1)))
		return (-1);
	while (wal->format[i])
	{
		if (!(i = ft_search_flags(wal, i)))
			return (ft_free_and_quit(wal));
		if (wal->start_f)
		{
			if (!(ft_process_flags(wal)))
				return (ft_free_and_quit(wal));
			ft_init_t_print(wal, 0);
		}
	}
	va_end(wal->args);
	return (ft_write_and_free(wal));
}
