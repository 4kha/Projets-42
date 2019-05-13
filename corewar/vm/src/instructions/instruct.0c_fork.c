/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.0c_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:28 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:10:33 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : fork S(D2)
** Durée : 800
** OCP : Non
** Adressage Restreint : Oui
** Modifie le carry : Non
** Genere un nouveau p a l'adresse passée en parametre par copie du
** p appelant. Le nouveau p garde donc l'etat de tout les
** registres et du carry, seul le PC differe ( sauf dans le cas d'un fork %0 ).
**
** fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
** Crée un nouveau p, qui hérite des diférents états de son père, a
** part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD)).
*/

void	exec_fork(t_a *a, t_p *p)
{
	int	i;
	int	n;

	i = -1;
	n = count_pc(a);
	if (!(a->pc = (t_p **)realloc(a->pc, sizeof(t_p *) * (n + 2))))
		error(a, 0, "Error: cannot realloc PC memory");
	a->pc[n + 1] = 0;
	if (!(a->pc[n] = (t_p *)ft_memalloc(sizeof(t_p))))
		error(a, 0, "Error: cannot malloc PC memory");
	while (++i <= REG_NUMBER)
		a->pc[n]->reg[i] = p->reg[i];
	a->pc[n]->carry = p->carry;
	a->pc[n]->live = p->live;
	a->pc[n]->mem = p->mem + (int16_t)get_dir(a, p, (p->mem + 1) % MEM_SIZE, 2)
	% IDX_MOD;
	while (a->pc[n]->mem < 0)
		a->pc[n]->mem += MEM_SIZE;
	a->pc[n]->mem %= MEM_SIZE;
	a->pc[n]->owner = p->owner;
	a->pc[n]->need_init = 1;
	p->mem = (p->mem + 1 + IND_SIZE) % MEM_SIZE;
	p->need_init = 1;
}
