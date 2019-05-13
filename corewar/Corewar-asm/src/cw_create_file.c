/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 07:15:12 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/27 12:51:50 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <fcntl.h>
#include <unistd.h>

static char	*cw_convert(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i] - 48;
		i++;
	}
	return (str);
}

void		cw_create_file(t_asm *comp)
{
	int		fd;
	int		len;

	if ((fd = open(comp->cor_file, O_CREAT | O_TRUNC | O_WRONLY, 00644)) == -1)
		cw_error(comp, "Error when creating .cor\n");
	len = ft_strlen(comp->data);
	write(fd, cw_convert(comp->data), len);
	close(fd);
}
