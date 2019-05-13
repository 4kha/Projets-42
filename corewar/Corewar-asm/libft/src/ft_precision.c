/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:56:38 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/07 17:31:07 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_apply_precision(char *str, int nbr, char c)
{
	int		i;
	char	*tmp;

	i = ft_strlen(str);
	if ((c != 's' && c != 'S') && str[0] == '-')
		i--;
	if ((c == 's' || c == 'S') && nbr < i)
	{
		tmp = str;
		str = ft_strsub(str, 0, nbr);
		free(tmp);
	}
	else if ((c != 's' && c != 'S') && nbr > i)
	{
		if (str[0] == '-')
			str = ft_insert_char(str, nbr - i, '0', 1);
		else
			str = ft_insert_char(str, nbr - i, '0', 0);
	}
	return (str);
}

static int	ft_cal_prec(t_print *wal)
{
	int		i;
	int		nbr;
	char	*tmp;

	if (wal->precision > 1)
	{
		i = wal->start_f + wal->offset + wal->flag + wal->width + 1;
		tmp = ft_strsub(wal->format, i, wal->precision - 1);
		nbr = ft_atoi(tmp);
		free(tmp);
		return (nbr);
	}
	else
		return (0);
}

char		*ft_precision(t_print *wal, char *str, char c)
{
	int		nbr;
	char	*tmp;

	if (wal->precision && c != 'c' & c != 'C' && c != 'p' && c != '%')
	{
		nbr = ft_cal_prec(wal);
		if (nbr == 0 && ft_strlen(str) == 1 && str[0] == '0')
		{
			tmp = str;
			str = ft_strdup("\0");
			free(tmp);
		}
		else
			str = ft_apply_precision(str, nbr, c);
	}
	return (str);
}
