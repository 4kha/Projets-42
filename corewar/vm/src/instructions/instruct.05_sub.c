/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.05_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:44 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:50:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : sub S(RG), S(RG), D(RG)
** Durée : 10
** OCP : Oui
** Adressage Restreint : Non
** Modifie le carry : Oui
** Soustrait le second parametre au premier parametre, et stock le resultat
** dans le troisieme parametre. Si la valeur resultante est egale a zero, alors
** le carry passe a l'etat un, sinon a l'etat zero.
**
** sub : Pareil que add, mais l’opcode est 0b101, et utilise une soustraction.
*/

static int	sub_is_error(t_a *a, t_p *p, char *ocp)
{
	if (!is_reg(ocp, 0) || !is_reg(ocp, 2) || !is_reg(ocp, 4)
	|| !is_empty(ocp, 6))
	{
		mv(p, ocp, DIR_SIZE, 3);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

static void	perfom_sub(t_a *a, t_p *p)
{
	int		reg_one;
	int		reg_two;
	int		reg_three;

	reg_one = get_dir(a, p, (p->mem + 2) % MEM_SIZE, REG_IDX);
	reg_two = get_dir(a, p, (p->mem + 2 + REG_IDX) % MEM_SIZE, REG_IDX);
	reg_three = get_dir(a, p, (p->mem + 2 + REG_IDX * 2) % MEM_SIZE, REG_IDX);
	if (reg_one >= 1 && reg_one <= REG_NUMBER
	&& reg_two >= 1 && reg_two <= REG_NUMBER
	&& reg_three >= 1 && reg_three <= REG_NUMBER)
	{
		p->reg[reg_three] = p->reg[reg_one] - p->reg[reg_two];
		p->carry = (p->reg[reg_three] == 0) ? 1 : 0;
	}
}

void		exec_sub(t_a *a, t_p *p)
{
	char	*ocp;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (sub_is_error(a, p, ocp))
		return ;
	perfom_sub(a, p);
	p->mem = (p->mem + 2 + REG_IDX * 3) % MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
