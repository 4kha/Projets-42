/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:20:38 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/01 15:40:34 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uimaxtoa_base(uintmax_t n, int base, int maj)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_unbrlenmax_base(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		if (n % base < 10)
			str[len--] = (n % base) + 48;
		else
			str[len--] = (n % base) + (87 - maj * 32);
		n /= base;
	}
	return (str);
}

char	*ft_imaxtoa_base(intmax_t n, int base, int maj)
{
	int		len;
	char	*str;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlenmax_base(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		if (n % base < 10)
			str[len--] = (n % base) + 48;
		else
			str[len--] = (n % base) + (87 - maj * 32);
		n /= base;
	}
	return (str);
}

char	*ft_imaxtoa(intmax_t n)
{
	return (ft_imaxtoa_base(n, 10, 0));
}

char	*ft_itoa_base(int n, int base, int maj)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen_base(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		if (n % base < 10)
			str[len--] = (n % base) + 48;
		else
			str[len--] = (n % base) + (87 - maj * 32);
		n /= base;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10, 0));
}
