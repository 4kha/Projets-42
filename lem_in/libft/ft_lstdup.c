/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:40:36 by khtran            #+#    #+#             */
/*   Updated: 2018/05/17 04:30:24 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *target)
{
	t_list	*cpy;
	t_list	*tmp;

	cpy = NULL;
	while (target != NULL)
	{
		tmp = ft_lstnew(target->content, sizeof(target->content));
		tmp->content_size = target->content_size;
		ft_lstlast(&cpy, tmp);
		target = target->next;
	}
	return (cpy);
}
