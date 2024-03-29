/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:23:19 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 18:23:19 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fd_close(int fd)
{
	if ((fd = close(fd)) == -1)
	{
		ft_putstr_fd("Close failure\n", 2);
		exit(1);
	}
}
