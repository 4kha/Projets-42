/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 23:09:04 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/14 04:09:38 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nb(char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			nb++;
			while (str[i] == c)
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int			*ft_intsplit(char *str, char c, int *size)
{
	int		nb;
	int		*res;
	char	**split;

	if (!str)
		return (NULL);
	nb = ft_nb(str, c);
	*size = nb;
	if (!(res = (int*)malloc(sizeof(int) * (nb + 1))))
		return (NULL);
	if (!(split = ft_strsplit(str, c)))
		return (NULL);
	while (nb >= 0)
	{
		res[nb] = ft_atoi(split[nb]);
		free(split[nb--]);
	}
	free(str);
	free(split);
	return (res);
}
