/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:50:11 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 18:51:45 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_debug(char *c)
{
	int		index;

	index = 0;
	while (c[index])
	{
		ft_putnbr(c[index]);
		index++;
		ft_putchar(' ');
	}
	ft_putnbr(c[index]);
	ft_putchar('\n');
}
