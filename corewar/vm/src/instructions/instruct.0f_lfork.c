/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.0f_lfork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:35 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:04:21 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : lfork S(D2)
** Durée : 1000
** OCP : Non
** Adressage Restreint : Non
** Modifie le carry : Non
** Identique a Fork mais sans restriction de l'adressage.
**
** lfork : Ca signifie long-fork, pour pouvoir fourcher de la paille à une
** distance de 15 mètres, exactement comme son opcode. Pareil qu’un fork sans
** modulo à l'adresse.
*/

void	exec_lfork(t_a *a, t_p *p)
{
	int	i;
	int	n;

	i = 0;
	n = count_pc(a);
	if (!(a->pc = (t_p **)realloc(a->pc, sizeof(t_p *) * (n + 2))))
		error(a, 0, "Error: cannot rmalloc PC memory");
	a->pc[n + 1] = 0;
	if (!(a->pc[n] = (t_p *)ft_memalloc(sizeof(t_p))))
		error(a, 0, "Error: cannot malloc PC memory");
	while (i <= REG_NUMBER)
	{
		a->pc[n]->reg[i] = p->reg[i];
		i++;
	}
	a->pc[n]->carry = p->carry;
	a->pc[n]->live = p->live;
	a->pc[n]->mem = p->mem + (int16_t)get_dir(a, p, (p->mem + 1) % MEM_SIZE, 2);
	while (a->pc[n]->mem < 0)
		a->pc[n]->mem += MEM_SIZE;
	a->pc[n]->mem %= MEM_SIZE;
	a->pc[n]->owner = p->owner;
	a->pc[n]->need_init = 1;
	p->mem = (p->mem + 1 + IND_SIZE) % MEM_SIZE;
	p->need_init = 1;
}
