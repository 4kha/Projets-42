/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:16:50 by khtran            #+#    #+#             */
/*   Updated: 2018/06/20 10:08:36 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(*new) + 1);
	if (new == NULL)
		exit(0);
	new->next = NULL;
	if (content != NULL)
	{
		new->content = (void*)malloc(sizeof(new->content)
				* (content_size + 1));
		if (new->content == NULL)
			exit(0);
		ft_memcpy(new->content, content, content_size + 1);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	return (new);
}
