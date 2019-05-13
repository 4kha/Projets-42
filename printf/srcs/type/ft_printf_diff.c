/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 03:50:02 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:46:48 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_diff(size_t used, size_t size, char motif)
{
	size_t	diff;
	char	*serie;
	size_t	index;

	index = 0;
	diff = 0;
	while (used < size)
	{
		diff++;
		used++;
	}
	serie = (char*)malloc(sizeof(char) * (diff + 1));
	if (serie == NULL)
	{
		ft_putstrn("Malloc/ft_printf_diff/failled\n");
		exit(1);
	}
	serie[diff] = 0;
	while (index < diff)
		serie[index++] = motif;
	ft_putstrn(serie);
	free(serie);
	serie = NULL;
}
