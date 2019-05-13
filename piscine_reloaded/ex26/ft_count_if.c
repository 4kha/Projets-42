/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:23:20 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 19:36:30 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (tab[index] != 0)
	{
		if ((f)(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
