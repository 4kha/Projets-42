/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 05:30:18 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 19:02:12 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "../ftmlx/ftmlx.h"
# include "libft.h"

typedef struct		s_env
{
	t_lim			env;
	int				size;
	double			one_h;
	double			one_x;
	int				min;
	int				max;
	t_list			**pile_a;
	t_list			**pile_b;
	t_list			**command;
	t_img			fond;
	t_img			mail;
	int				index;
	int				t_pause;
}					t_env;

void				visual_set(t_env *env);
void				visual_maillon(t_env *env);
void				visual_find_tag(t_list **pile_a, t_list **pile_b,
		char *line);
int					visual_step(t_list **pile_a, t_list **pile_b, t_env *env);
int					visual_while(t_env *env);
void				visual_event_all(t_env env);

#endif
