/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:41:28 by khtran            #+#    #+#             */
/*   Updated: 2018/05/10 18:41:29 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *to_free)
{
	t_list	*tmp;

	while (to_free != NULL)
	{
		tmp = to_free->next;
		free(to_free->content);
		free(to_free);
		to_free = tmp;
	}
}
