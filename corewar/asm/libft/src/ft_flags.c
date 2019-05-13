/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:00:13 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/07 17:12:18 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** pad :
** 0 = left - '0'
** 1 = left - ' '
** 2 = right - ' '
*/

static char	*ft_width(t_print *wal, char *str, char c, int pad)
{
	int		i;
	int		wth;
	int		len;
	int		signe;
	char	*tmp;

	i = wal->start_f + wal->offset + wal->flag;
	signe = 0;
	tmp = ft_strsub(wal->format, i, wal->width);
	wth = ft_atoi(tmp);
	free(tmp);
	len = ft_strlen(str);
	if ((c == 'd' || c == 'i' || c == 'D') && (str[0] == '-' || str[0] == '+'
		|| str[0] == ' '))
		signe = 1;
	else if ((c == 'x' || c == 'X') && (str[1] == 'x' || str[1] == 'X'))
		signe = 2;
	if (pad == 0 && wth - len > 0)
		str = ft_insert_char(str, wth - len, '0', signe);
	else if (pad == 1 && wth - len > 0)
		str = ft_insert_char(str, wth - len, ' ', 0);
	else if (pad == 2 && wth - len > 0)
		str = ft_insert_char(str, wth - len, ' ', len);
	return (str);
}

static char	*ft_flag_minuzero(t_print *wal, char *str, char c, int i)
{
	int		imax;

	imax = i + wal->flag;
	while (wal->format[i] != '-' && wal->format[i] != '0' && i < imax)
		i++;
	if (wal->format[i] == '0')
	{
		while (wal->format[i] != '-' && i < imax)
			i++;
		if (wal->format[i] != '-' && (!wal->precision || (c == 'c' || c == 's'
			|| c == 'C' || c == 'S' || c == 'p' || c == '%')) && wal->width)
			str = ft_width(wal, str, c, 0);
	}
	if (wal->format[i] == '-' && wal->width)
		str = ft_width(wal, str, c, 2);
	return (str);
}

static char	*ft_flag_pluspace(t_print *wal, char *str, char c, int i)
{
	int		imax;

	imax = i + wal->flag;
	if ((c == 'd' || c == 'i' || c == 'D') && str[0] != '-')
	{
		while (wal->format[i] != '+' && wal->format[i] != ' ' && i < imax)
			i++;
		if (wal->format[i] == '+')
			str = ft_insert_char(str, 1, '+', 0);
		else if (wal->format[i] == ' ')
		{
			if (wal->flag == 1)
				str = ft_insert_char(str, 1, ' ', 0);
			else
			{
				while (wal->format[i] != '+' && i < imax)
					i++;
				if (wal->format[i] == '+')
					str = ft_insert_char(str, 1, '+', 0);
				else
					str = ft_insert_char(str, 1, ' ', 0);
			}
		}
	}
	return (str);
}

static char	*ft_flag_sharp(t_print *wal, char *str, char c, int i)
{
	int		imax;
	int		not_zero;

	imax = i + wal->flag;
	if (c == 'o' || c == 'O' || c == 'x' || c == 'X')
	{
		while (wal->format[i] != '#' && i < imax)
			i++;
		imax = 0;
		not_zero = 0;
		while (str[imax])
		{
			if (str[imax] != '0' && (c == 'x' || c == 'X'))
				not_zero++;
			imax++;
		}
		if (wal->format[i] == '#' && (not_zero || ((c == 'o' || c == 'O')
			&& str[0] != '0')))
		{
			str = ft_insert_char(str, 1, '0', 0);
			if (c == 'x' || c == 'X')
				str = ft_insert_char(str, 1, c, 1);
		}
	}
	return (str);
}

char		*ft_flags_width(t_print *wal, char *str, char c)
{
	int		i;

	if (wal->flag)
	{
		i = wal->start_f + wal->offset;
		str = ft_flag_sharp(wal, str, c, i);
		str = ft_flag_pluspace(wal, str, c, i);
		str = ft_flag_minuzero(wal, str, c, i);
	}
	if (wal->width)
		str = ft_width(wal, str, c, 1);
	return (str);
}
