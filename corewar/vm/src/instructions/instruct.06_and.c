/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.06_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:46 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:54:44 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : and S(RG/ID/D4), S(RG/ID/D4), D(RG)
** Durée : 6
** OCP : Oui
** Adressage Restreint : Oui
** Modifie le carry : Oui
** Effectue un AND logique entre les deux premiers paramametres et stock le
** resultat dans le troisieme paramametre. Si la valeur resultante est egale
** a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
**
** and : Applique un & (ET bit-à-bit) sur les deux premiers paramètres, et
** stocke le résultat dans le registre qui est le 3ème paramètre.
** Opcode 0x06. Modifie le carry.
*/

static int	assess_param(t_a *a, t_p *p, char *ocp, int i)
{
	int	value;
	int	move;

	value = 0;
	move = (i / 2) ? get_mv(ocp, i - 2, 4) + 2 : 2;
	if (is_dir(ocp, i))
		value = get_dir(a, p, (p->mem + move) % MEM_SIZE, 4);
	else if (is_ind(ocp, i))
		value = get_ind(a, p, (p->mem + move) % MEM_SIZE, IND_SIZE);
	else
		value = get_dir(a, p, (p->mem + move) % MEM_SIZE, REG_IDX);
	return (value);
}

static int	and_is_error(t_a *a, t_p *p, char *ocp)
{
	if (is_empty(ocp, 0) || is_empty(ocp, 2) || !is_reg(ocp, 4)
	|| !is_empty(ocp, 6))
	{
		mv(p, ocp, 4, 3);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

void		exec_and(t_a *a, t_p *p)
{
	int32_t	p1;
	int32_t	p2;
	int		reg;
	char	*ocp;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (and_is_error(a, p, ocp))
		return ;
	p1 = assess_param(a, p, ocp, 0);
	p2 = assess_param(a, p, ocp, 2);
	reg = get_dir(a, p, (p->mem + 2 + get_mv(ocp, 0, 4) + get_mv(ocp, 2, 4))
	% MEM_SIZE, REG_IDX);
	if (reg >= 1 && reg <= REG_NUMBER && ((is_reg(ocp, 0)
	&& p1 >= 1 && p1 <= REG_NUMBER && get_reg_val(&p1, p)) || !is_reg(ocp, 0))
	&& ((is_reg(ocp, 2) && p2 >= 1 && p2 <= REG_NUMBER && get_reg_val(&p2, p))
	|| !is_reg(ocp, 2)))
	{
		p->reg[reg] = p1 & p2;
		p->carry = (p->reg[reg] == 0) ? 1 : 0;
	}
	p->mem = (p->mem + 2 + get_mv(ocp, 0, 4) + get_mv(ocp, 2, 4) + REG_IDX)
	% MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
