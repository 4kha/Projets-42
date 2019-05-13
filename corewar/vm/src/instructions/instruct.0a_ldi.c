/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.0a_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:20 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 21:51:05 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : ldi S(RG/ID/D2), S(D2/RG), D(RG)
** Durée : 25
** OCP : Oui
** Adressage Restreint : Oui
** Modifie le carry : NON
** Transfert indirect RAM > Registre. Charge la valeur a l'adresse resultante
** de l'addition des deux premiers paramametres, dans le registre passé en
** troisieme parametre. Si cette valeur est nulle, alors le carry passe a
** l'etat un, sinon a l'ettat zero.
**
** ldi : ldi, comme son nom l’indique, n’implique nullement de se baigner
** dans de la crème de marrons, même si son opcode est 0x0a. Au lieu de ça,
** ca prend 2 index et 1 registre, additionne les 2 premiers, traite ca comme
** une adresse, y lit une valeur de la taille d’un registre et la met dans
** le 3eme.
*/

static int	assess_param(t_a *a, t_p *p, char *ocp, int i)
{
	int	value;
	int	move;

	value = 0;
	move = (i / 2) ? get_mv(ocp, i - 2, 2) + 2 : 2;
	if (is_dir(ocp, i))
		value = (int16_t)get_dir(a, p, (p->mem + move) % MEM_SIZE, 2);
	else if (is_ind(ocp, i))
		value = (int32_t)get_ind(a, p, (p->mem + move) % MEM_SIZE, IND_SIZE);
	else
		value = get_reg(a, p, (p->mem + move) % MEM_SIZE, REG_IDX);
	return (value);
}

static int	ldi_is_error(t_a *a, t_p *p, char *ocp)
{
	if (is_empty(ocp, 0) || !(is_dir(ocp, 2) || is_reg(ocp, 2))
	|| !is_reg(ocp, 4) || !is_empty(ocp, 6))
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

void		exec_ldi(t_a *a, t_p *p)
{
	int32_t	p1;
	int32_t	p2;
	int		reg;
	char	*ocp;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (ldi_is_error(a, p, ocp))
		return ;
	p1 = assess_param(a, p, ocp, 0);
	p2 = assess_param(a, p, ocp, 2);
	reg = get_dir(a, p, (p->mem + 2 + get_mv(ocp, 0, 2) + get_mv(ocp, 2, 2))
	% MEM_SIZE, REG_IDX);
	if (reg >= 1 && reg <= REG_NUMBER)
		p->reg[reg] = get_dir(a, p, p->mem + (((int32_t)(p1 + p2))
		% IDX_MOD + MEM_SIZE) % MEM_SIZE, REG_SIZE);
	p->mem = (p->mem + 2 + get_mv(ocp, 0, 2) + get_mv(ocp, 2, 2) + REG_IDX)
	% MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
