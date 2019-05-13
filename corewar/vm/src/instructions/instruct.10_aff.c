/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.10_aff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:42:27 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/29 01:04:32 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Usage : aff S(RG)
** Durée : 2
** OCP : Oui
** Adressage Restreint : Non
** Modifie le carry : Oui
** Affiche a l'ecran le char correspondant a la valeure du registre passé en
** parametre, modulo 256. Si ce char est NUL, alors le carry passe a l'etat 1,
** sinon a l'état 0. A vous de choisir le formattage de la sortie ecran. Vous
** pouvez par exemple preciser a chaque aff l'id de sont p d'origine, ou
** bien attribuer une couleur a chaque p, ou encore attribuer une ligne
** de aff par p, ou n'importe quoi d'autre avec les p,
** l'important reste que votre sortie de aff soit le plus swag possible.
** Idée de bonus : L'instruction aff a pour seul but de taunter son adversaire
** (ce qui est une part non negligeable du jeu). Mais, en envoyant les chars
** au compte goute, il est tres difficile de sortir une phrase propre a l'ecran,
** sans etre interompu par un live ou un autre aff. Pour palier a ca, vous
** pouvez bufferiser le aff. Dans ce cas chaque p possede son buffer.
** A chaque appel de aff, l'instruction rajoute le char dans le buffer du
** p. Lors d'un appel de aff avec le char NUL, l'instruction vide le
** buffer a l'ecran. Un char NUL definissant egalement le carry a 1, cette
** construction permet de facilement faire des boucle pour display des strings,
** si tant est qu'elles se terminent par un NUL char.
**
** aff : L’opcode est 10 en hexadécimal. Il y a un octet de codage des
** paramètres, même si c’est un peu bête car il n’y a qu’un paramètre, qui
** est un registre, dont le contenu est interprété comme la valeur ASCII
** d’un caractère à afficher sur la sortie standard. Ce code est modulo 256.
*/

static int	aff_is_error(t_a *a, t_p *p, char *ocp)
{
	if (!is_reg(ocp, 0) || !is_empty(ocp, 2) || !is_empty(ocp, 4)
	|| !is_empty(ocp, 6))
	{
		mv(p, ocp, DIR_SIZE, 1);
		if (a->hard)
			delete_processus(a, p);
		else
			p->need_init = 1;
		return (1);
	}
	return (0);
}

void		exec_aff(t_a *a, t_p *p)
{
	char	*ocp;
	int		param;

	if (!(ocp = get_ocp(a->mem[(p->mem + 1) % MEM_SIZE]->octet)))
		error(a, 0, "Error: cannot malloc ocp memory");
	if (aff_is_error(a, p, ocp))
		return ;
	param = get_dir(a, p, (p->mem + 2) % MEM_SIZE, REG_IDX) % 256;
	if (param >= 1 && param <= REG_NUMBER && get_reg_val(&param, p))
		if (!a->visual)
			ft_putchar(param % 256);
	p->mem = (p->mem + 2 + REG_IDX) % MEM_SIZE;
	ft_strdel(&ocp);
	p->need_init = 1;
}
