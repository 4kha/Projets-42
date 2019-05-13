/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:01:44 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:37:57 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
