/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 06:22:47 by khtran            #+#    #+#             */
/*   Updated: 2018/02/05 12:40:14 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_H
# define FTMLX_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct		s_img
{
	int				line_x;
	int				line_y;
	void			*img;
	int				*src;
	int				endian;
}					t_img;

typedef struct		s_value
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_value;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				color;
	int				inc_x;
	int				inc_y;
	int				color_inc;
}					t_pos;

typedef struct		s_vec
{
	t_pos			x;
	t_pos			y;
	t_pos			z;
	t_pos			w;
}					t_vec;

typedef struct		s_lim
{
	void			*win;
	void			*mlx;
	t_img			img;
	t_vec			vec;
	int				c_dep;
	int				c_end;
}					t_lim;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

int					mlx_square(t_pos start, int x, int y, t_lim win);
void				mlx_put_pixel_img(int x, int y, int col, t_img *win);
void				mlx_line(t_pos dep, t_pos end, t_img *win);
t_pos				mlx_pos_set(int x, int y, int color);
int					mlx_color_med(int color_dep, int color_end, double rapport);
int					mlx_color_set(int r, int g, int b);
int					mlx_square_img(t_pos start, t_pos go, t_img img, t_lim
		*win);

#endif
