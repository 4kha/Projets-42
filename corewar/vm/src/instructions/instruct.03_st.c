/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.03_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:41 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:50:25 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : st S(RG), D(RG/ID)
** Durée : 5
** OCP : Oui
** Adressage Restreint : Oui
** Modifie le carry : Oui
** Transfert direct Registre > RAM / Registre. Charge le contenu du registre
** passé en premier parametre dans le second parametre. Si la valeur du
** premier parametre est egale a zero, alors le carry passe a l'etat un, sinon
** a l'etat zero.
**
** st : Prend un registre et un registre ou un indirect, et stocke la valeur du
** registre vers le second paramètre. Son opcode est 0x03. Par exemple, st r1,
** 42 stocke la valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
*/

static int	assess_param(t_a *a, t_p *p, char *ocp, int i)
{
	int	value;

	value = 0;
	if (is_reg(ocp, i))
	{
		value = get_dir(a, p, (p->mem + 2 + REG_IDX) % MEM_SIZE, REG_IDX);
		p->mem = (p->mem + 2 + REG_IDX * 2) % MEM_SIZE;
	}
	else
	{
		value = get_dir(a, p, (p->mem + 2 + REG_IDX) % MEM_SIZE, IND_SIZE);
		p->mem = (p->mem + 2 + REG_IDX + IND_SIZE) % MEM_SIZE;
	}
	return (value);
}

static int	st_is_error(t_a *a, t_p *p, char *ocp)
{
	if (!is_reg(ocp, 0) || !(is_reg(ocp, 2) || is_ind(ocp, 2))
	|| !is_empty(ocp, 4) || !is_empty(ocp, 6))
	{
		mv(p, ocp, DIR_SIZE, 2);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

static void	change_value_ind(t_a *a, int param, int reg, t_c *owner)
{
	param += MEM_SIZE;
	a->mem[param % MEM_SIZE]->octet = (reg >> 24) & 0xff;
	a->mem[(param + 1) % MEM_SIZE]->octet = (reg >> 16) & 0xff;
	a->mem[(param + 2) % MEM_SIZE]->octet = (reg >> 8) & 0xff;
	a->mem[(param + 3) % MEM_SIZE]->octet = (reg) & 0xff;
	a->mem[param % MEM_SIZE]->owner = owner;
	a->mem[(param + 1) % MEM_SIZE]->owner = owner;
	a->mem[(param + 2) % MEM_SIZE]->owner = owner;
	a->mem[(param + 3) % MEM_SIZE]->owner = owner;
}

void		exec_st(t_a *a, t_p *p)
{
	int		param;
	int		reg;
	int		pos;
	char	*ocp;

	pos = p->mem;
	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (st_is_error(a, p, ocp))
		return ;
	reg = get_dir(a, p, (p->mem + 2) % MEM_SIZE, REG_IDX);
	param = assess_param(a, p, ocp, 2);
	if (reg >= 1 && reg <= REG_NUMBER)
	{
		if (is_reg(ocp, 2) && param >= 1 && param <= REG_NUMBER)
			p->reg[param] = p->reg[reg];
		else if (is_ind(ocp, 2))
			change_value_ind(a, pos + (int16_t)param % IDX_MOD,
			p->reg[reg], p->owner);
	}
	ft_strdel(&ocp);
	p->need_init = 1;
}
