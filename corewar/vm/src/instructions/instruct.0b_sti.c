/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.0b_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:25 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:03:28 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : sti S(RG), S(RG/ID/D2), S(RG/D2)
** Durée : 25
** OCP : Oui
** Adressage Restreint : Oui
** Modifie le carry : NON
** Transfert indirect Registre > RAM. Charge la valeur contenu dans le registre
** passé en premier parametre a l'adresse resultante de l'addition des deux
** derniers paramametres. Si cette valeur est nulle, alors le carry passe a
** l'etat un, sinon a l'ettat zero.
**
** sti : Opcode 11. Prend un registre, et deux index (potentiellement des
** registres). Additionne les deux derniers, utilise cette somme comme une
** adresse ou sera copiée la valeur du premier paramètre.
*/

static int		assess_param(t_a *a, t_p *p, char *ocp, int i)
{
	int	value;
	int	move;

	value = 0;
	move = ((i - 2) / 2) ? get_mv(ocp, i - 2, 2) + 2 : 2;
	if (is_ind(ocp, i))
		value = (int16_t)get_ind(a, p, (p->mem + REG_IDX + move) % MEM_SIZE,
		IND_SIZE);
	else if (is_dir(ocp, i))
		value = (int16_t)get_dir(a, p, (p->mem + REG_IDX + move) % MEM_SIZE, 2);
	else
		value = get_dir(a, p, (p->mem + REG_IDX + move) % MEM_SIZE, REG_IDX);
	return (value);
}

static int		sti_is_error(t_a *a, t_p *p, char *ocp)
{
	if (!is_reg(ocp, 0) || is_empty(ocp, 2) || !(is_dir(ocp, 4)
	|| is_reg(ocp, 4)) || !is_empty(ocp, 6))
	{
		mv(p, ocp, 2, 3);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

static void		copy_data(t_a *a, int reg, int16_t addr, t_c *owner)
{
	addr += MEM_SIZE;
	a->mem[addr % MEM_SIZE]->octet = (reg >> 24) & 0xff;
	a->mem[(addr + 1) % MEM_SIZE]->octet = (reg >> 16) & 0xff;
	a->mem[(addr + 2) % MEM_SIZE]->octet = (reg >> 8) & 0xff;
	a->mem[(addr + 3) % MEM_SIZE]->octet = (reg) & 0xff;
	a->mem[addr % MEM_SIZE]->owner = owner;
	a->mem[(addr + 1) % MEM_SIZE]->owner = owner;
	a->mem[(addr + 2) % MEM_SIZE]->owner = owner;
	a->mem[(addr + 3) % MEM_SIZE]->owner = owner;
}

void			exec_sti(t_a *a, t_p *p)
{
	int32_t	p1;
	int32_t	p2;
	int		reg;
	char	*ocp;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (sti_is_error(a, p, ocp))
		return ;
	reg = get_dir(a, p, (p->mem + 2) % MEM_SIZE, REG_IDX);
	p1 = assess_param(a, p, ocp, 2);
	p2 = assess_param(a, p, ocp, 4);
	if (reg >= 1 && reg <= REG_NUMBER
	&& ((is_reg(ocp, 2) && p1 >= 1 && p1 <= REG_NUMBER
	&& get_reg_val(&p1, p)) || !is_reg(ocp, 2))
	&& ((is_reg(ocp, 4) && p2 >= 1 && p2 <= REG_NUMBER
	&& get_reg_val(&p2, p)) || !is_reg(ocp, 4)))
		copy_data(a, p->reg[reg], (p->mem + ((int16_t)((p1 + p2) % IDX_MOD)))
		+ MEM_SIZE % MEM_SIZE, p->owner);
	p->mem = (p->mem + 2 + REG_IDX + get_mv(ocp, 2, 2) + get_mv(ocp, 4, 2))
	% MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
