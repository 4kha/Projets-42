/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:27:28 by rbechir           #+#    #+#             */
/*   Updated: 2018/05/29 03:21:04 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isint(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str || !ft_isnumber(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i++])
		len++;
	if (len > 10)
		return (0);
	if (((str[i - len] <= '2') && ((intmax_t)ft_atoi(str) == ft_atoimax(str)))
		|| (len < 10))
		return (1);
	return (0);
}
