/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.is_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:23:45 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 17:32:33 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_dir(char *str, int i)
{
	return (str[i] == '1' && str[i + 1] == '0');
}

int	is_empty(char *str, int i)
{
	return (str[i] == '0' && str[i + 1] == '0');
}

int	is_ind(char *str, int i)
{
	return (str[i] == '1' && str[i + 1] == '1');
}

int	is_reg(char *str, int i)
{
	return (str[i] == '0' && str[i + 1] == '1');
}
