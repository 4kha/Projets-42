/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 05:08:08 by khtran            #+#    #+#             */
/*   Updated: 2017/12/21 18:19:07 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ftmlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_trigger
{
	int			*trigger;
	int			count_t;
}				t_trigger;

typedef struct	s_env
{
	t_value		value;
	t_trigger	t;
	t_lim		env;
	t_lim		env2;
	t_lim		env3;
	t_lim		env4;
	t_img		interface;
	double		zoom;
	double		zoom_inc;
	int			it_max;
	t_pos		click;
	t_rgb		rgb;
	t_rgb		stock;
	t_pos		pos;
}				t_env;

t_value			mlx_value_set(double x1, double x2, double x3, double x4);
int				mlx_interaction1_hold(int x, int y, t_env *param);
void			mlx_image_set(t_env *env);
void			mlx_interface(t_env *env);
void			mlx_fractale(t_env env, int x_start, t_lim envmore);
void			mlx_calculate(t_env env);
int				mlx_interaction1_click(int button, int x, int y, t_env *param);
int				mlx_interaction1_key_click(int button, t_env *param);
void			mlx_trigger_set(t_trigger *trigger);
t_trigger		mlx_trigger_create(int count);
int				mlx_interaction1_release(int button, int x, int y,
		t_env *param);
void			mlx_fractale_julia(t_env env, int x_start, t_lim envmore);
void			mlx_fractale_mandel(t_env env, int x_start, t_lim envmore);
void			mlx_fractale_tapis(t_env env, int x_start, t_lim envmore);
void			mlx_fractale_julia_3(t_env env, int x_start, t_lim envmore);
void			mlx_fractale_mandel_3(t_env env, int x_start, t_lim envmore);
void			mlx_fractale_burning(t_env env, int x_start, t_lim envmore);
void			mlx_interface_choice(t_env *env);
int				mlx_interaction1_key_click(int button, t_env *param);
void			mlx_interface_color(t_lim win);
void			mlx_interface_color_click(int button, int x, int y, t_env
		*param);
void			mlx_interface_color_while(int x, t_env *param);
int				mlx_interface_color_release(t_env *param);
void			mlx_param_set(t_env *env);
void			mlx_rgb_move(int x, int *test);
void			mlx_interaction6_click(int button, int x, int y, t_env *param);
int				mlx_get_color(t_env env, int iteration);
int				mlx_get_color_tapis(t_env env, int iteration);
char			*ft_itoa(int value);
int				ft_lenght(int value);
void			mlx_info(t_env env);
int				ft_strlen(char *str);
void			ft_putstr(char *c);
int				ft_strcmp(char *s1, char *s2);
void			party_parrot_of_doom(t_env *parrot);
void			mlx_fractale_set(t_env *param);
int				mlx_close(void);

#endif
