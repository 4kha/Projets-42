/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:41:25 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 18:56:33 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# define PI 3.1415926535897932384626433832795

typedef struct	s_pos
{
	int			x;
	int			y;
	int			color;
	int			inc_x;
	int			inc_y;
	int			color_inc;
}				t_pos;

typedef struct	s_tab
{
	int			high;
	int			color;
}				t_tab;

typedef struct	s_vec
{
	t_pos		pos;
	t_pos		x;
	t_pos		y;
	t_pos		z;
	t_pos		last;
	t_pos		center;
	t_tab		varx;
	t_tab		vary;
	t_tab		varb;
	t_tab		varlast;
}				t_vec;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_img
{
	int			line;
	int			y;
	void		*img;
	int			*src;
}				t_img;

typedef struct	s_lim
{
	char		*dest;
	int			size_x;
	int			size_y;
	int			size_z;
	int			index_x;
	int			index_y;
	double		rot;
	int			y_start;
	int			x_start;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			camhigh;
	int			prof;
	int			trigger_1;
	int			trigger_2;
	int			trigger_3;
	int			trigger_4;
	int			trigger_5;
	int			trigger_6;
	int			trigger_7;
	int			trigger_8;
	int			trigger_9;
	int			trigger_10;
	int			trigger_11;
	t_rgb		rgb;
	t_rgb		rgb2;
	int			color_def;
	int			color_high;
	int			block;
	int			fd;
	int			high;
	int			level;
	t_img		img;
	t_vec		map;
	t_tab		**matrice;
	int			ret;
}				t_lim;

void			mlx_line(t_pos dep, t_pos end, t_lim *win);
t_pos			mlx_pos_set(int x, int y, int color);
void			mlx_tab_set(int high, int color, t_tab *tab);
void			mlx_grid(t_lim *fen);
void			mlx_prepare_pos(int fd, t_lim *tab);
t_tab			mlx_atoi_at(char *nb, int at);
void			mlx_rgb_set(t_lim *win, int r, int g, int b);
void			mlx_interface(t_lim win);
int				mlx_square(t_pos start, int x, int y, t_lim win);
int				mlx_interface_5_bis(t_lim *param, int y, int x);
int				mlx_interface_6(t_lim *param, int y, int x);
void			mlx_rgb_move_2(int y, int *test);
void			mlx_rgb_move(int y, int *test);
int				mlx_interface_1(int x, int y, t_lim *param);
int				mlx_color_resume(t_lim *param);
int				mlx_interface_5(int x, int y, t_lim *param);
int				mlx_interface_4(int x, int y, t_lim *param);
int				mlx_interface_2(int button, int x, int y, t_lim *param);
int				mlx_interface_all(t_lim *win);
int				mlx_interface_3(int button, int x, int y, t_lim *param);
int				mlx_grid_open(t_lim fen);
int				ft_exit(int keycode, t_lim *param);
void			mlx_put_pixel_img(int x, int y, int col, t_lim *win);
t_tab			**mlx_matrice(int fd, t_lim fen);
int				mlx_matrice_highest(t_tab **matrice, t_lim fen);
void			mlx_interface_text(t_lim win);
void			mlx_vec_set(t_vec *start, t_lim *data);
int				mlx_colorset(int color_dep, int color_end, double rapport);
int				mlx_interface_7(int x, int y, t_lim *win);
int				mlx_trigger_9(t_lim *param, int x, int y);
void			mlx_vec_set3(t_vec *start, t_lim *data);
void			mlx_reset(t_lim *win);
int				mlx_rot_set(t_lim *data);
void			mlx_pre_color(t_tab *var, t_lim fen);
void			mlx_vec_set2(t_vec *start, t_lim *data);
void			mlx_interface_8(int x, int y, t_lim *param);
void			mlx_interface_9(int x, int y, t_lim *param);
void			mlx_loading(int percent, t_lim *param);

#endif
