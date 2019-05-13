/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.00_nothing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:20:38 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:02:54 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exec_nothing(t_a *a, t_p *p)
{
	p->mem = (p->mem + 1) % MEM_SIZE;
	if (a->hard == 1)
		delete_processus(a, p);
	else
		p->need_init = 1;
}
