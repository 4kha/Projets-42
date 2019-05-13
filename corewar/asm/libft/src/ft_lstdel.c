/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:50:34 by rbechir           #+#    #+#             */
/*   Updated: 2018/01/17 18:35:01 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst != NULL && del != NULL)
		if (*alst != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
}

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;

	if (alst != NULL && del != NULL)
		while (*alst)
		{
			next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next;
		}
}
