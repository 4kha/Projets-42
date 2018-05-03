/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 04:55:06 by khtran            #+#    #+#             */
/*   Updated: 2018/04/20 09:16:41 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../instruction.h"
#include "../../ftmlx/ftmlx.h"
#include "../mlx.h"
#include "../visual.h"

void	visual_maillon2(t_env *env)
{
	t_list	**pile;
	t_list	*pile_tmp;
	int		cumul;
	int		index;

	index = 1;
	cumul = 0;
	pile = (*env).pile_b;
	pile_tmp = *pile;
	while (pile_tmp != NULL)
	{
		mlx_square_img(mlx_pos_set((int)cumul, 247 - pile_tmp->content_size,
			0x0000), mlx_pos_set((int)(*env).one_h,
			(int)(pile_tmp->content_size * 2), 0), (*env).mail, &(*env).env);
		cumul = ((double)(index / (*env).one_x) * 1200);
		pile_tmp = pile_tmp->next;
		index++;
	}
	mlx_put_image_to_window((*env).env.mlx, (*env).env.win,
			(*env).mail.img, 0, 0);
}

void	visual_maillon(t_env *env)
{
	t_list		**pile;
	t_list		*pile_tmp;
	double		cumul;
	int			index;

	index = 1;
	cumul = 0;
	pile = (*env).pile_a;
	pile_tmp = *pile;
	mlx_square_img(mlx_pos_set(0, 0, 0xFF000000), mlx_pos_set(1200, 1000, 0),
				(*env).mail, &(*env).env);
	while (pile_tmp != NULL)
	{
		mlx_square_img(mlx_pos_set((int)cumul, 753 - pile_tmp->content_size,
			0x0000), mlx_pos_set((int)(*env).one_h,
			(int)(pile_tmp->content_size * 2), 0), (*env).mail, &(*env).env);
		cumul = ((double)(index / (*env).one_x) * 1200);
		pile_tmp = pile_tmp->next;
		index++;
	}
	visual_maillon2(env);
}

void	visual_set(t_env *env)
{
	t_list	*tmp;
	t_list	**pile;

	pile = (*env).pile_a;
	tmp = *pile;
	mlx_square_img(mlx_pos_set(0, 0, 0x00EEEEEE),
			mlx_pos_set(1200, 1000, 0x00FFFFFF), (*env).fond, &(*env).env);
	mlx_square_img(mlx_pos_set(0, 495, 0x00),
			mlx_pos_set(1200, 10, 0x00222222), (*env).fond, &(*env).env);
	mlx_square_img(mlx_pos_set(0, 497, 0x0CCCCCC),
			mlx_pos_set(1200, 6, 0x00222222), (*env).fond, &(*env).env);
	mlx_put_image_to_window((*env).env.mlx, (*env).env.win,
			(*env).fond.img, 0, 0);
	while (tmp != NULL)
	{
		tmp->content_size = (double)247
			* (double)((double)tmp->content_size / (double)(*env).max);
		tmp = tmp->next;
	}
	visual_maillon(env);
}
