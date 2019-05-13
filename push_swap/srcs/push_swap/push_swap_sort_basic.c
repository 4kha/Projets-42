/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:13:21 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:09:04 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

void	push_swap_tag(t_list **pile_a, t_list **pile_b,
		t_list **command, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		push_swap_sx(pile_a);
	else if (ft_strcmp(line, "sb") == 0)
		push_swap_sx(pile_b);
	else if (ft_strcmp(line, "ss") == 0)
		push_swap_ss(pile_a, pile_b);
	else if (ft_strcmp(line, "pa") == 0)
		push_swap_px(pile_b, pile_a);
	else if (ft_strcmp(line, "pb") == 0)
		push_swap_px(pile_a, pile_b);
	else if (ft_strcmp(line, "ra") == 0)
		push_swap_rx(pile_a);
	else if (ft_strcmp(line, "rb") == 0)
		push_swap_rx(pile_b);
	else if (ft_strcmp(line, "rr") == 0)
		push_swap_rr(pile_a, pile_b);
	else if (ft_strcmp(line, "rra") == 0)
		push_swap_rrx(pile_a);
	else if (ft_strcmp(line, "rrb") == 0)
		push_swap_rrx(pile_b);
	else if (ft_strcmp(line, "rrr") == 0)
		push_swap_rrr(pile_a, pile_b);
	ft_lstlast(command, ft_lstnew(line, ft_strlen(line)));
}

int		ft_lstmed(t_list *list, int list_len)
{
	t_list	*move;
	int		min_act;
	int		count;
	int		min_min;
	int		index;

	count = 1;
	min_act = list->content_size;
	min_min = ft_lstmin_until(list, list_len);
	while (count < list_len / 2 && list != NULL)
	{
		index = 0;
		move = list;
		while (move != NULL && index < list_len)
		{
			if ((move->content_size < min_act && move->content_size > min_min)
					|| (min_min == min_act && !(move->content_size < min_act)))
				min_act = move->content_size;
			move = move->next;
			index++;
		}
		count++;
		min_min = min_act;
	}
	return (min_min);
}

int		ft_lstmin(t_list *find)
{
	int		min;

	min = find->content_size;
	while (find != NULL)
	{
		if (find->content_size < min)
			min = find->content_size;
		find = find->next;
	}
	return (min);
}

int		push_swap_stack_opti(t_list *pile_a, t_list *pile_b, int len_a)
{
	int		min_b;
	int		min_a;

	if (pile_a == NULL)
		return (ft_lstmin(pile_b));
	min_a = ft_lstmin_until(pile_a, len_a);
	min_b = min_a;
	if (pile_b != NULL)
		min_b = ft_lstmin(pile_b);
	if (min_a > min_b)
		return (min_b);
	else
		return (min_a);
}

int		push_swap_pre_opti(t_list *pile_a, t_list *pile_b)
{
	int		index;
	int		min;
	t_list	*pile;

	index = 0;
	if (pile_a != NULL)
	{
		min = ft_lstmin(pile_a);
		pile = pile_a;
		while (pile->content_size != min)
		{
			pile = pile->next;
			index++;
		}
	}
	index = push_swap_stack_opti(pile_a, pile_b, index);
	return (index);
}
