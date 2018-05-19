/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:25:07 by khtran            #+#    #+#             */
/*   Updated: 2017/11/10 13:27:47 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char	letter;

	letter = (unsigned char)c;
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}