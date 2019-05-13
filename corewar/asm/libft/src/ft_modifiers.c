/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:37:31 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/04 16:39:13 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_verif_modifiers_csp(char *c, int *mod)
{
	if (ft_isupper(*c))
	{
		if (*mod == 0)
			*mod = 2;
		else
			return (0);
		*c = ft_tolower(*c);
	}
	else if (*mod != 0 && *mod != 2)
		return (0);
	return (1);
}

int		ft_verif_modifiers_diou(char *c, int *mod)
{
	if (ft_isupper(*c))
	{
		if (*mod == 2)
			*mod = 6;
		else if (*mod == 0)
			*mod = 2;
		else
			return (0);
		*c = ft_tolower(*c);
	}
	return (1);
}

int		ft_get_modifiers(t_print *wal)
{
	int	i;

	i = wal->end_f - wal->modifier;
	if (wal->modifier == 0)
		return (0);
	else if (wal->modifier == 1)
	{
		if (wal->format[i] == 'h')
			return (1);
		else if (wal->format[i] == 'l')
			return (2);
		else if (wal->format[i] == 'j')
			return (3);
		else if (wal->format[i] == 'z')
			return (4);
	}
	else if (wal->modifier == 2)
		if (wal->format[i] == wal->format[i + 1])
		{
			if (wal->format[i] == 'h')
				return (5);
			else if (wal->format[i] == 'l')
				return (6);
		}
	return (-1);
}

char	*ft_apply_modifs_oux(t_print *wal, int mod, int base, int maj)
{
	uintmax_t	i;

	i = va_arg(wal->args, uintmax_t);
	if (mod == 0)
		i = (unsigned int)i;
	else if (mod == 1)
		i = (unsigned short)i;
	else if (mod == 2)
		i = (unsigned long)i;
	else if (mod == 4)
		i = (size_t)i;
	else if (mod == 5)
		i = (unsigned char)i;
	else if (mod == 6)
		i = (unsigned long long)i;
	else if (mod != 3)
		return (NULL);
	return (ft_uimaxtoa_base(i, base, maj));
}
