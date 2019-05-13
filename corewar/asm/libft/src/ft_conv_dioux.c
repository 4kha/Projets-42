/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:29:04 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/04 16:39:21 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_conv_di(t_print *wal, char c, int mod)
{
	intmax_t	i;

	i = va_arg(wal->args, intmax_t);
	if (c == 'd' || c == 'i')
	{
		if (mod == 0)
			i = (int)i;
		else if (mod == 1)
			i = (short)i;
		else if (mod == 2)
			i = (long)i;
		else if (mod == 5)
			i = (char)i;
		else if (mod == 6)
			i = (long long)i;
		else if (mod != 3 && mod != 4)
			return (NULL);
	}
	else
		return (NULL);
	return (ft_imaxtoa(i));
}

char		*ft_conv_oux(t_print *wal, char c, int mod)
{
	int	base;

	if (c == 'o')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	else
		base = 10;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (ft_apply_modifs_oux(wal, mod, base, ft_isupper(c)));
	else
		return (NULL);
}

char		*ft_conv_dioux(t_print *wal, char c)
{
	int	mod;

	if ((mod = ft_get_modifiers(wal)) < 0)
		return (NULL);
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if (!ft_verif_modifiers_diou(&c, &mod))
			return (NULL);
		return (ft_conv_di(wal, c, mod));
	}
	else if (c == 'o' || c == 'u' || c == 'O' || c == 'U')
	{
		if (!ft_verif_modifiers_diou(&c, &mod))
			return (NULL);
		return (ft_conv_oux(wal, c, mod));
	}
	else if (c == 'x' || c == 'X')
		return (ft_conv_oux(wal, c, mod));
	else
		return (NULL);
}
