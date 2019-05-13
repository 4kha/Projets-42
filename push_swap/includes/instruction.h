/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:06:11 by khtran            #+#    #+#             */
/*   Updated: 2018/04/12 22:41:36 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

# include "libft.h"

void	ft_ko(void);
void	ft_error(void);
int		ft_lstlen(t_list *list);
int		ft_lstmax(t_list *find);
void	ft_lstfree(t_list *to_free);
t_list	*ft_lstdup(t_list *target);
t_list	*ft_lsttail(t_list *list);
int		ft_lstmin_until(t_list *find, int list_len);
void	ft_lstlast(t_list **alst, t_list *newe);
void	push_swap_px(t_list **pile1, t_list **pile2);
void	push_swap_rx(t_list **pile_x);
void	push_swap_rr(t_list **pile_a, t_list **pile_b);
void	push_swap_rrx(t_list **pile_x);
void	push_swap_rrr(t_list **pile_a, t_list **pile_b);
void	push_swap_sx(t_list **pile_x);
void	push_swap_ss(t_list **pile_a, t_list **pile_b);
int		checker_check_arg(int ac, char **av, int index);
void	checker_order(t_list *pile_a, t_list *pile_b);
void	checker_parse(t_list **start, char *nbr, char *chr);
int		*checker_ptr(char *to_atoi);
void	check_doublon(t_list *start);
void	ft_lstdelmail(t_list **command, t_list *remove);
int		ft_lstunder(t_list *pile, int value);

#endif
