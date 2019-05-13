/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:07:30 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 17:34:24 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_dir(t_a *a, t_p *p, int start, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!a || !p)
		return (-1);
	while (start < 0)
		start += MEM_SIZE;
	while (i < size)
	{
		result += a->mem[(start + i) % MEM_SIZE]->octet
				* ft_pow(256, size - i - 1);
		i++;
	}
	return (result);
}

int	get_ind(t_a *a, t_p *p, int start, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!a || !p)
		return (-1);
	while (i < size)
	{
		res += a->mem[(start + i) % MEM_SIZE]->octet
				* ft_pow(256, size - i - 1);
		i++;
	}
	res = (int16_t)res % IDX_MOD;
	res += p->mem;
	while (res < 0)
		res += MEM_SIZE;
	res = a->mem[(res) % MEM_SIZE]->octet * ft_pow(256, 3)
	+ a->mem[(res + 1) % MEM_SIZE]->octet * ft_pow(256, 2)
	+ a->mem[(res + 2) % MEM_SIZE]->octet * 256
	+ a->mem[(res + 3) % MEM_SIZE]->octet;
	return (res);
}

int	get_reg(t_a *a, t_p *p, int start, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!a || !p)
		return (-1);
	while (i < size)
	{
		result += a->mem[(start + i) % MEM_SIZE]->octet
				* ft_pow(256, size - i - 1);
		i++;
	}
	if (result >= 1 && result <= REG_NUMBER)
		return (p->reg[result]);
	return (0);
}

int	get_reg_val(int *param, t_p *p)
{
	*param = p->reg[*param];
	return (1);
}
