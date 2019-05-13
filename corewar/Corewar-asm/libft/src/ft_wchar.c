/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:03:39 by rbechir           #+#    #+#             */
/*   Updated: 2018/02/01 18:40:19 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_abintoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 2 + (str[i] - 48);
		i++;
	}
	return (res);
}

static char	*ft_apply_mask(char *str, int nbr)
{
	char	*mask;
	int		i;

	if (nbr <= 7)
		mask = ft_strdup("0xxxxxxx");
	else if (nbr <= 11)
		mask = ft_strdup("110xxxxx10xxxxxx");
	else if (nbr <= 16)
		mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else if (nbr <= 21)
		mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	else
		return (NULL);
	i = ft_strlen(mask) - 1;
	nbr--;
	while (i > 0)
	{
		if (mask[i] == 'x' && nbr >= 0)
			mask[i] = str[nbr--];
		else if (mask[i] == 'x')
			mask[i] = '0';
		i--;
	}
	return (mask);
}

char		*ft_cut_mask(char *str)
{
	int		nbr;
	char	*mask;
	char	*submask;
	char	*ret;

	nbr = ft_strlen(str);
	if (!(mask = ft_apply_mask(str, nbr)))
		return (NULL);
	free(str);
	nbr = ft_strlen(mask) / 8;
	ret = (char*)malloc(sizeof(char) * nbr + 1);
	ret[nbr] = '\0';
	nbr = 0;
	while (mask[nbr])
	{
		submask = ft_strsub(mask, nbr, 8);
		ret[nbr / 8] = ft_abintoi(submask);
		nbr += 8;
		free(submask);
	}
	free(mask);
	return (ret);
}
