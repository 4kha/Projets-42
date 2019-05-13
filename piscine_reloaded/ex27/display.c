/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:44:05 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 20:21:58 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displat.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char *av[])
{
	int		fd;
	int		ret;
	char	buff[50 + 1];

	if (ac == 1)
		ft_puterr("File name missing.\n");
	if (ac > 2)
		ft_puterr("Too many arguments.\n");
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_puterr("Open() error.\n");
			return (1);
		}
		while ((ret = read(fd, buff, 50)))
		{
			buff[ret] = '\0';
			ft_putstr(buff);
		}
	}
	return (0);
}
