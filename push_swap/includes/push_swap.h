/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:42:11 by khtran            #+#    #+#             */
/*   Updated: 2018/04/15 21:00:37 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_pile
{
	t_list		*pile_a;
	t_list		*pile_b;
	int			len_a;
	int			len_b;
}				t_pile;

void			push_swap_tag(t_list **pile_a, t_list **pile_b,
				t_list **command, char *line);
void			push_swap_command_opti(t_list **command);
void			push_swap_sort_command_opti_2(t_list **command, int len);
int				push_swap_sort_1_setup(t_list *pile_a, int list_len,
		t_list **command);
int				push_swap_sort_2_setup_min(t_list *pile_a, t_list **command,
		int nbr);
int				push_swap_sort_2_setup_max(t_list *pile_a, t_list **command,
		int nbr);
int				push_swap_sort_3_setup(t_list *pile_a, t_list **command,
		int nbr);
int				push_swap_stack_opti(t_list *pile_a, t_list *pile_b,
		int len_a);
int				push_swap_pre_opti(t_list *pile_a, t_list *pile_b);
int				ft_lstmin(t_list *find);
int				ft_lstlen(t_list *list);
int				ft_lstmed(t_list *list, int list_len);
int				checker_order_safe(t_list *pile_a, t_list *pile_b);
void			push_swap_command_opti(t_list **command);
void			push_swap_sort_command_opti_2(t_list **command, int len);
void			push_swap_sort_1_recursive(t_list **pile_a, t_list **pile_b,
				t_list **command);
void			push_swap_sort_pa_ra(t_list **pile_a, t_list **pile_b,
				t_list **command, int *small);
void			push_swap_sort_1_pull(t_list **pile_a, t_list **pile_b,
		t_list **command, int count);
int				push_swap_sort_5_setup(t_list *pile_a, t_list **command,
		int pivot);
int				push_swap_sort_1_put(t_list **pile_a, t_list **pile_b,
		t_list **command, int len);
void			push_swap_sort_1_setup_put_2(t_list **pile_a, t_list
		**pile_b, t_list **command, int min);

#endif
