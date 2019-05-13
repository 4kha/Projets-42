/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:11:10 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 15:41:22 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	usage(void)
{
	ft_putstr("Usage:\t");
	ft_putendl("./corewar \
[--dump N | -d N] [--verbose | -v] [--visual] [--audio | -a] [--hard | -h] \
[--number | -n N] [(--color | -c) COLOR] <champion1.cor> <...>");
	ft_putstr("\tdump   :\tdump arena memory after N cycles, then exit");
	ft_putendl(", where N is int gt 0");
	ft_putendl("\tverbose:\tdisplay details of execution");
	ft_putendl("\tvisual :\tdisplay NCusrses visual");
	ft_putendl("\taudio  :\tenable sound");
	ft_putendl("\thard   :\tharcore mode");
	ft_putendl("\tnumber  :\tforce champion's number to N \
where N is int gte 0");
	ft_putstr("\tcolor  :\tforce champion's color to COLOR ");
	ft_putendl("(green, blue, red, yellow, magenta, cyan)");
	exit(EXIT_FAILURE);
}
