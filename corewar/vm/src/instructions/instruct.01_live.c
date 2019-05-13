/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.01_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:18:37 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 22:03:33 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : live S(D4)
** Durée : 10
** OCP : Non
** Adressage Restreint : Non
** Modifie le carry : Non
** Rapporte le joueur designé par le premier parametre comme etant en vie.
** L'instruction ecrit sur la sortie standard un message du type "Le joueur
** $player_name ( $player_id ), a été raporter comme étant en vie". Libre a
** vous de 'pimper' le message comme bon vous semble, du moment que l'idée
** passe et qu'il contienne les variables sus nommée. Un joueur ne vie que
** tant qu'au moins un p effectue un live avec sont id, et ce au minimun
** une fois tout les CYCLE_TO_DIE. Si le parametre passé ne correspond a l'id
** d'aucun joueurs, le comportement est indefinit. A vous de decider si c'est
** une erreur et que le p crash, ou si osef, l'instruction ne fait rien
** et on passe a la suite, avec eventuelement en supplément un petit message
** sur la sortie standard, message incohérent ou message d'avertissement, votre
** seul limite est celle de votre creativité.
**
** live : L’instruction qui permet à un p de rester vivant.
** A également pour e et de rapporter que le joueur dont le numéro
** est en paramètre est en vie. Pas d’octet de codage des paramètres,
** opcode 0x01. Oh, et son seul paramètre est sur 4 octets.
*/

void	exec_live(t_a *a, t_p *p)
{
	int		i;
	int		id;

	i = 0;
	p->live++;
	a->lives++;
	a->lives_total++;
	id = get_dir(a, p, p->mem + 1, 4);
	while (a->champ[i])
	{
		if (a->champ[i]->number == ~id)
		{
			if (!a->visual)
				ft_printf("%sPlayer %s [%d] is alive%s\n",
			get_color(a->champ[i], 0),
			a->champ[i]->name,
			a->champ[i]->number,
			get_color(a->champ[i], 1));
			a->last_alive = a->champ[i];
			a->champ[i]->lives++;
		}
		i++;
	}
	p->mem = (p->mem + 4 + 1) % MEM_SIZE;
	p->need_init = 1;
}
