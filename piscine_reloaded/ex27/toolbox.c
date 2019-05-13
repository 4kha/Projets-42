/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:44:51 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 20:25:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *c)
{
	int		index;

	index = 0;
	while (c[index])
		index++;
	return (index);
}

void	ft_putstr(char *c)
{
	write(1, c, ft_strlen(c));
}

void	ft_puterr(char *c)
{
	write(2, c, ft_strlen(c));
}
