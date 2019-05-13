/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:53:52 by rbechir           #+#    #+#             */
/*   Updated: 2017/12/16 18:10:04 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp_malloc;
	t_list	*newlist;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(tmp_malloc = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	newlist = tmp_malloc;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(tmp_malloc->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		tmp_malloc = tmp_malloc->next;
		lst = lst->next;
	}
	return (newlist);
}
