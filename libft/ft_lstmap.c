/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:36:25 by khtran            #+#    #+#             */
/*   Updated: 2017/11/11 19:57:46 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	start = NULL;
	if ((f) == NULL || lst == NULL)
		return (NULL);
	while (lst)
	{
		tmp = f(lst);
		if (start == NULL)
		{
			start = tmp;
			new = tmp;
			new->next = NULL;
		}
		else
		{
			new->next = tmp;
			new = tmp;
			new->next = NULL;
		}
		lst = lst->next;
	}
	return (start);
}
