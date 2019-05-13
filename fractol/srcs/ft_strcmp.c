/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:24:13 by khtran            #+#    #+#             */
/*   Updated: 2017/12/20 22:40:59 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	*dup1;
	unsigned char	*dup2;

	dup1 = (unsigned char*)s1;
	dup2 = (unsigned char*)s2;
	while (*dup1 == *dup2 && (*dup1 != 0 || *dup2 != 0))
	{
		dup1++;
		dup2++;
	}
	return (*dup1 - *dup2);
}
