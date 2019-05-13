/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:07 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/04 17:16:37 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int			ft_free_and_quit(t_print *wal)
{
	free(wal->buff);
	free(wal->format);
	free(wal->flags);
	free(wal);
	return (-1);
}

int			ft_write_and_free(t_print *wal)
{
	int		len;

	len = ft_strlen(wal->buff) + wal->len;
	ft_putstr(wal->buff);
	free(wal->buff);
	free(wal->format);
	free(wal->flags);
	free(wal);
	return (len);
}

static void	ft_save(t_print *wal, char *str)
{
	char	*tmp;

	tmp = wal->buff;
	wal->buff = ft_strjoin(wal->buff, str);
	free(tmp);
	free(str);
}

static void	ft_display_bz(t_print *wal, char *str)
{
	char	*tmp;
	int		i;
	int		imax;

	i = wal->start_f + wal->offset;
	imax = i + wal->flag;
	wal->len += ft_strlen(wal->buff) + 1;
	ft_putstr(wal->buff);
	tmp = wal->buff;
	wal->buff = ft_strdup("\0");
	free(tmp);
	str = ft_flags_width(wal, str, 'c');
	while (i < imax && wal->format[i] != '-')
		i++;
	if (str[0] == '\0')
		imax = 1;
	else
		imax = ft_strlen(str);
	if (wal->format[i] == '-')
		str = ft_insert_char(str, 1, '\0', 0);
	else
		str = ft_insert_char(str, 1, '\0', imax - 1);
	write(1, str, imax);
	wal->len = wal->len + imax - 1;
	free(str);
}

int			ft_process_flags(t_print *wal)
{
	char	c;
	char	*str;

	c = wal->format[wal->end_f];
	str = NULL;
	if (c == 'd' || c == 'o' || c == 'u' || c == 'x' || c == 'i'
		|| c == 'D' || c == 'O' || c == 'U' || c == 'X')
		str = ft_conv_dioux(wal, c);
	else if (c == 'c' || c == 's' || c == 'p' || c == 'C' || c == 'S')
		str = ft_conv_csp(wal, c);
	else if (c == '%')
		str = ft_strdup("%");
	if (str)
	{
		if (str[0] == '\0' && (c == 'c' || c == 'C'))
			ft_display_bz(wal, str);
		else
		{
			str = ft_precision(wal, str, c);
			str = ft_flags_width(wal, str, c);
			ft_save(wal, str);
		}
		return (1);
	}
	return (0);
}
