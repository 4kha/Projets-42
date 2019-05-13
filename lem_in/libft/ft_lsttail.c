/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:42:07 by khtran            #+#    #+#             */
/*   Updated: 2018/06/15 00:54:35 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lsttail(t_list *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}
