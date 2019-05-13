/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 07:15:12 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/28 21:12:11 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <fcntl.h>
#include <unistd.h>

void		cw_create_file(t_asm *comp)
{
	comp->fd = open(comp->cor_file, O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (comp->fd == -1)
		cw_error(comp, "Error when creating .cor\n");
	write(comp->fd, comp->data, comp->i);
	ft_printf("File %s created\n", comp->cor_file);
	close(comp->fd);
}
