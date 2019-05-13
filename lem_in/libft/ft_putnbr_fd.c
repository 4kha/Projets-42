/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:59:14 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 18:00:30 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int value, int fd)
{
	char *nbrstr;

	nbrstr = ft_itoa(value);
	ft_putstr_fd(nbrstr, fd);
	free(nbrstr);
}
