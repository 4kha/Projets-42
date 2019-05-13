/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:07 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/01 18:40:22 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_operate(int j, wchar_t *wstr, int mal)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*ret;

	i = 0;
	if (j == 0)
		return (NULL);
	if (!(ret = ft_strdup("\0")))
		return (NULL);
	while (i < j)
	{
		str = ft_cut_mask(ft_imaxtoa_base(wstr[i], 2, 0));
		tmp = ret;
		ret = ft_strjoin(ret, str);
		free(tmp);
		free(str);
		i++;
	}
	if (mal)
		free(wstr);
	return (ret);
}

static char	*ft_conv_wcs(t_print *wal, char c)
{
	wchar_t	*wstr;

	if (c == 's')
	{
		wstr = va_arg(wal->args, wchar_t*);
		if (!wstr)
			return (ft_strdup("(null)"));
		return (ft_operate(ft_wstrlen(wstr), wstr, 0));
	}
	else if (c == 'c')
	{
		wstr = (wchar_t*)malloc(sizeof(wchar_t) * 1);
		*wstr = va_arg(wal->args, wchar_t);
		return (ft_operate(1, wstr, 1));
	}
	return (NULL);
}

static char	*ft_conv_cs(t_print *wal, char c, int mod)
{
	unsigned char	i;
	char			*str;

	if (mod == 2)
		return (ft_conv_wcs(wal, c));
	if (c == 'c')
	{
		i = (unsigned char)va_arg(wal->args, int);
		if (!(str = ft_strdup("0\0")))
			return (NULL);
		str[0] = (char)i;
		return (str);
	}
	else if (c == 's')
	{
		if ((str = va_arg(wal->args, char*)) == NULL)
			return (ft_strdup("(null)"));
		else
			return (ft_strdup(str));
	}
	else
		return (NULL);
}

char		*ft_conv_csp(t_print *wal, char c)
{
	int		mod;
	char	*str;
	char	*tmp;

	if ((mod = ft_get_modifiers(wal)) < 0)
		return (NULL);
	if (!ft_verif_modifiers_csp(&c, &mod))
		return (NULL);
	if (c == 'c' || c == 's')
		return (ft_conv_cs(wal, c, mod));
	else if (mod == 0 && c == 'p')
	{
		if (!(str = ft_conv_oux(wal, 'x', 2)))
			return (NULL);
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
		return (str);
	}
	return (NULL);
}
