/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:56:22 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 17:14:37 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		result;

	result = 0;
	if (nb < 0)
		return (0);
	while (result * result != nb && result < (nb / 2))
		result++;
	if (result * result == nb)
		return (result);
	else
		return (0);
}
