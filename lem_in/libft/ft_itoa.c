/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:11:19 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 20:21:34 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		tmp;

	len = ft_number_base_len(n, 10);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = 0;
	len = len - 1;
	if (n < 0)
		result[0] = '-';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		result[len--] = (tmp % 10) + '0';
		n = n / 10;
	}
	return (result);
}
