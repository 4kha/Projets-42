/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.ocp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:33:54 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 17:34:25 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*get_ocp(int octet)
{
	int		i;
	int		size;
	char	*binary;
	char	*ocp;

	i = 8;
	if (octet < 0)
		return (NULL);
	if (!(binary = lltoa_base("01", octet)))
		return (NULL);
	if (!(ocp = ft_memsets(ft_strnew(8), '0', 8)))
	{
		ft_strdel(&binary);
		return (NULL);
	}
	size = ft_strlen(binary);
	while (--i >= 0 && --size >= 0)
		ocp[i] = binary[size];
	ft_strdel(&binary);
	return (ocp);
}
