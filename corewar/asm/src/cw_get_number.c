/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 01:13:45 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/29 00:54:49 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static char		*cw_conv(t_asm *comp, intmax_t nbr, int size)
{
	int		neg;
	char	*str;

	neg = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		cw_error(comp, "Malloc error (converting number)\n");
	while (--size >= 0)
	{
		if (neg)
			str[size] = (nbr % 256) - 1;
		else
			str[size] = (nbr % 256);
		if (nbr < 0)
			neg = 1;
		nbr = nbr / 256;
	}
	return (str);
}

static intmax_t	cw_atoimax(char *str)
{
	int			i;
	intmax_t	res;
	int			signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
		signe = 44 - str[i++];
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - 48);
		if (res < 0)
		{
			if (signe == 1)
				return (9223372036854775807);
			else
				return (0);
		}
	}
	return (signe * res);
}

void			cw_get_number(t_asm *comp, int start, int size)
{
	intmax_t	nbr;
	char		*tmp;

	if (!(tmp = ft_strsub(comp->r_str, start, ft_strlen(comp->r_str) - start)))
		cw_error(comp, "Malloc error (getting number)\n");
	nbr = cw_atoimax(tmp);
	free(tmp);
	tmp = cw_conv(comp, nbr, size);
	start = 0;
	while (size-- > 0)
		comp->data[comp->i++] = tmp[start++];
	free(tmp);
}
