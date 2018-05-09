/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsp_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:22:41 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 20:29:10 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsp_c(char const *s, char c)
{
	int		word;
	int		index;

	index = 0;
	word = 0;
	if (s == NULL)
		return (0);
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if (s[index] != c)
		{
			word++;
			while (s[index] != c && s[index])
				index++;
		}
		else
			while (s[index] == c && s[index])
				index++;
	}
	return (word);
}
