/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:53:39 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 18:54:11 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_debug(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
	{
		ft_putstr_debug(tab[index]);
		index++;
	}
}
