/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.instructs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:55:04 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/28 23:57:39 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_proc_num(t_a *a, t_p *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->pc[i])
	{
		if (a->pc[i] == p)
			j = i;
		i++;
	}
	return (j);
}

static char		*get_instruct_name_next(t_p *p)
{
	if (p->instruct == 0x08)
		return ("xor (0x08)");
	else if (p->instruct == 0x09)
		return ("zjmp (0x09)");
	else if (p->instruct == 0x0a)
		return ("ldi (0x0a)");
	else if (p->instruct == 0x0b)
		return ("sti (0x0b)");
	else if (p->instruct == 0x0c)
		return ("fork (0x0c)");
	else if (p->instruct == 0x0d)
		return ("lld  (0x0d)");
	else if (p->instruct == 0x0e)
		return ("lldi (0x0e)");
	else if (p->instruct == 0x0f)
		return ("lfork(0x0f)");
	else if (p->instruct == 0x10)
		return ("aff (0x10)");
	else
		return ("");
}

static char		*get_instruct_name(t_p *p)
{
	if (p->instruct == 0x01)
		return ("live (0x01)");
	else if (p->instruct == 0x02)
		return ("ld (0x02)");
	else if (p->instruct == 0x03)
		return ("st (0x03)");
	else if (p->instruct == 0x04)
		return ("add (0x04)");
	else if (p->instruct == 0x05)
		return ("sub (0x05)");
	else if (p->instruct == 0x06)
		return ("and (0x06)");
	else if (p->instruct == 0x07)
		return ("or (0x07)");
	else
		return (get_instruct_name_next(p));
}

static void		exec_instruct_next(t_a *a, t_p *p)
{
	if (p->instruct == 0x07)
		exec_or(a, p);
	else if (p->instruct == 0x08)
		exec_xor(a, p);
	else if (p->instruct == 0x09)
		exec_zjmp(a, p);
	else if (p->instruct == 0x0a)
		exec_ldi(a, p);
	else if (p->instruct == 0x0b)
		exec_sti(a, p);
	else if (p->instruct == 0x0c)
		exec_fork(a, p);
	else if (p->instruct == 0x0d)
		exec_lld(a, p);
	else if (p->instruct == 0x0e)
		exec_lldi(a, p);
	else if (p->instruct == 0x0f)
		exec_lfork(a, p);
	else if (p->instruct == 0x10)
		exec_aff(a, p);
	else
		exec_nothing(a, p);
}

void			exec_instruct(t_a *a, t_p *p)
{
	if (!a || !p)
		return ;
	while (p->mem < 0)
		p->mem += MEM_SIZE;
	if (a->verbose && !a->visual && a->mem[p->mem % MEM_SIZE]->octet != 0)
		ft_printf("%sProcessus %d (0x%04x) is executing %s [%d]%s\n",
		get_color(p->owner, 0), get_proc_num(a, p), (p->mem) % MEM_SIZE,
		get_instruct_name(p), get_exec(p->instruct), get_color(p->owner, 1));
	if (p->instruct == 0x01)
		exec_live(a, p);
	else if (p->instruct == 0x02)
		exec_ld(a, p);
	else if (p->instruct == 0x03)
		exec_st(a, p);
	else if (p->instruct == 0x04)
		exec_add(a, p);
	else if (p->instruct == 0x05)
		exec_sub(a, p);
	else if (p->instruct == 0x06)
		exec_and(a, p);
	else
		exec_instruct_next(a, p);
}
