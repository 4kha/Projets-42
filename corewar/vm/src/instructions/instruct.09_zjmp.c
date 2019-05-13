/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.09_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:52 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 18:05:20 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : zjmp S(D2)
** Durée : 20
** OCP : Non
** Adressage Restreint : Non
** Modifie le carry : Non
** Saute a l'adresse passé en parametre si le carry est a l'etat un. L'adresse
** devient alors celle de la prochaine instruction. Si le carry est a l'etat
** zero, rien ne se passe et le flot continue normalement jusqu'a l'instruction
** suivante. Rien ne precise si l'instruction consomme la totalité de ces
** cycles dans ce cas, a vous d'en decider.
**
** zjmp : Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage
** des paramètres derrière cette opération dont l’opcode est de 9. Elle
** prendra un index, et fait un saut à cette adresse si le carry est à 1.
*/

void	exec_zjmp(t_a *a, t_p *p)
{
	int	param;

	param = get_dir(a, p, (p->mem + 1) % MEM_SIZE, 2);
	if (p->carry)
		p->mem = (p->mem + (int16_t)param % IDX_MOD) % MEM_SIZE;
	else
		p->mem = (p->mem + 1 + 2) % MEM_SIZE;
	while (p->mem < 0)
		p->mem += MEM_SIZE;
	p->need_init = 1;
}
