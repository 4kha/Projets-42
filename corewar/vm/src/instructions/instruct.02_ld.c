/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.02_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:39 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:50:17 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : ld S(ID/D4), D(RG)
** Durée : 5
** OCP : Oui
** Adressage Restreint : Oui
** Modifie le carry : Oui
** Transfert direct RAM > Registre. Charge le premier parametre dans le registre
** passé en second parametre. Si la valeur du premier parametre est egale a
** zero, alors le carry passe a l'etat un, sinon a l'etat zero.
**
** ld : Prend un paramètre quelconque et un registre. Charge la valeur du
** premier paramètre dans le registre. Son opcode est 10 en binaire, et il
** changera le carry.
*/

static int	assess_param(t_a *a, t_p *p, char *ocp, int i)
{
	int	value;

	value = 0;
	if (is_dir(ocp, i))
	{
		value = get_dir(a, p, (p->mem + 2) % MEM_SIZE, 4);
		p->mem = (p->mem + 2 + 4) % MEM_SIZE;
	}
	else if (is_ind(ocp, i))
	{
		value = get_dir(a, p, (p->mem + 2) % MEM_SIZE, IND_SIZE);
		value = (int16_t)value % IDX_MOD;
		value = get_dir(a, p, (p->mem + value % IDX_MOD) % MEM_SIZE, DIR_SIZE);
		p->mem = (p->mem + 2 + IND_SIZE) % MEM_SIZE;
	}
	return (value);
}

static int	ld_is_error(t_a *a, t_p *p, char *ocp)
{
	if (!(is_dir(ocp, 0) || is_ind(ocp, 0)) || !is_reg(ocp, 2)
	|| !is_empty(ocp, 4) || !is_empty(ocp, 6))
	{
		mv(p, ocp, 4, 2);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

void		exec_ld(t_a *a, t_p *p)
{
	int32_t	param;
	int		reg;
	char	*ocp;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (ld_is_error(a, p, ocp))
		return ;
	param = assess_param(a, p, ocp, 0);
	reg = get_dir(a, p, p->mem, REG_IDX);
	if (reg >= 1 && reg <= REG_NUMBER)
	{
		p->reg[reg] = param;
		p->carry = (p->reg[reg] == 0) ? 1 : 0;
	}
	p->mem = (p->mem + REG_IDX) % MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
