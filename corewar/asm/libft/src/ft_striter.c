/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:21:38 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:15:48 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s != NULL && f != NULL)
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
}

void	ft_striter(char *s, void (*f)(char*))
{
	int	i;

	i = 0;
	if (s != NULL && f != NULL)
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
}
