/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 22:45:20 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 18:07:14 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	mv(t_p *p, char *ocp, int lbl_size, int n_params)
{
	int	i;

	i = 0;
	p->mem = (p->mem + 2) % MEM_SIZE;
	if (!ocp)
		return ;
	while (i < n_params * 2)
	{
		if (is_dir(ocp, i))
			p->mem = (p->mem + lbl_size) % MEM_SIZE;
		else if (is_reg(ocp, i))
			p->mem = (p->mem + REG_IDX) % MEM_SIZE;
		else if (is_ind(ocp, i))
			p->mem = (p->mem + IND_SIZE) % MEM_SIZE;
		i += 2;
	}
	ft_strdel(&ocp);
}

int		get_mv(char *ocp, int i, int dir)
{
	if (is_dir(ocp, i))
		return (dir);
	else if (is_ind(ocp, i))
		return (IND_SIZE);
	else if (is_reg(ocp, i))
		return (REG_IDX);
	return (0);
}
