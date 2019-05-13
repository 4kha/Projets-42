/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:02:25 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 01:11:12 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_set(t_print_trigger *trigger)
{
	(*trigger).trigger1 = 0;
	(*trigger).trigger2 = 0;
	(*trigger).trigger3 = 0;
	(*trigger).trigger4 = 0;
	(*trigger).trigger5 = 0;
	(*trigger).trigger6 = 0;
	(*trigger).trigger7 = 0;
	(*trigger).taille = 0;
	(*trigger).precision = 0;
	(*trigger).format = 0;
	(*trigger).hexamaj = 0;
}
