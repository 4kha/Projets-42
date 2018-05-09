/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:17:39 by khtran            #+#    #+#             */
/*   Updated: 2017/12/25 17:19:12 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mlx_open(char *str, int *fd)
{
	if ((*fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Open failure\n", 2);
		exit(1);
	}
}

void	mlx_close(int fd)
{
	if ((fd = close(fd)) == -1)
	{
		ft_putstr_fd("Close failure\n", 2);
		exit(1);
	}
}
