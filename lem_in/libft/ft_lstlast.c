/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:39:07 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 18:39:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlast(t_list **alst, t_list *newe)
{
	t_list		*tmp;

	tmp = *alst;
	if (tmp == NULL)
	{
		*alst = newe;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newe;
}
