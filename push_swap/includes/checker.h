/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 01:10:34 by khtran            #+#    #+#             */
/*   Updated: 2018/05/03 17:53:23 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

void	ft_error(void);
void	checker_visual_flat(t_list *pile_a, t_list *pile_b, char *line);
void	checker_count_command(char *line, int mode);
void	ft_lstlast(t_list **alst, t_list *newe);
void	push_swap_px(t_list **pile1, t_list **pile2);
void	push_swap_rx(t_list **pile_x);
void	push_swap_rr(t_list **pile_a, t_list **pile_b);
void	push_swap_rrx(t_list **pile_x);
void	push_swap_rrr(t_list **pile_a, t_list **pile_b);
void	push_swap_sx(t_list **pile_x);
void	push_swap_ss(t_list **pile_a, t_list **pile_b);

#endif
