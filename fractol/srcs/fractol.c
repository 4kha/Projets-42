/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 00:57:38 by khtran            #+#    #+#             */
/*   Updated: 2018/01/27 18:31:54 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	mlx_calculate(t_env env)
{
	mlx_fractale(env, 0, env.env);
	mlx_put_image_to_window(&env, env.env.win, env.env.img.img, 0, 0);
	mlx_fractale(env, 250, env.env2);
	mlx_put_image_to_window(&env, env.env.win, env.env2.img.img, 250, 0);
	mlx_fractale(env, 500, env.env3);
	mlx_put_image_to_window(&env, env.env.win, env.env3.img.img, 500, 0);
	mlx_fractale(env, 750, env.env4);
	mlx_put_image_to_window(&env, env.env.win, env.env4.img.img, 750, 0);
	mlx_info(env);
	if (env.t.trigger[9] == 0 && (env.t.trigger[2] == 4
				|| env.t.trigger[2] == 5))
		mlx_string_put(env.env.mlx, env.env.win,
			5, 5, 0x00A00000, "Press P to pause the mouse tracking");
	if (env.t.trigger[9] == 1 && (env.t.trigger[2] == 4
				|| env.t.trigger[2] == 5))
		mlx_string_put(env.env.mlx, env.env.win,
			5, 5, 0x00A00000, "Pause");
	if (env.it_max > 1000)
	{
		mlx_string_put(env.env.mlx, env.env.win,
		10, 770, 0x00A00000, "Ah le batard ...");
	}
}

void	mlx_fractale(t_env env, int start, t_lim envmore)
{
	if (env.t.trigger[2] == 0)
		mlx_fractale_mandel(env, start, envmore);
	if (env.t.trigger[2] == 1)
		mlx_fractale_julia(env, start, envmore);
	if (env.t.trigger[2] == 2)
		mlx_fractale_burning(env, start, envmore);
	if (env.t.trigger[2] == 3)
		mlx_fractale_tapis(env, start, envmore);
	if (env.t.trigger[2] == 4)
		mlx_fractale_mandel_3(env, start, envmore);
	if (env.t.trigger[2] == 5)
		mlx_fractale_julia_3(env, start, envmore);
}

int		mlx_while(t_env *env)
{
	if ((*env).t.trigger[7] == 1)
	{
		party_parrot_of_doom(env);
		mlx_calculate(*env);
	}
	return (0);
}

int		mlx_init_main(int fractale)
{
	t_env	env;

	env.t = mlx_trigger_create(10);
	env.t.trigger[2] = fractale;
	mlx_param_set(&env);
	env.env.mlx = mlx_init();
	env.env.win = mlx_new_window(env.env.mlx, 1240, 800, "Fract'Ol");
	mlx_image_set(&env);
	mlx_interface(&env);
	if (env.t.trigger[2] == 0)
		env.value = mlx_value_set(-2.1, 0.6, -1.2, 1.2);
	if (env.t.trigger[2] == 1)
		env.value = mlx_value_set(-1.7, 0.3, -1.2, 1.2);
	if (env.t.trigger[2] == 2)
		env.value = mlx_value_set(-1.2, 1, -1.8, 1.2);
	mlx_calculate(env);
	mlx_mouse_hook(env.env.win, &mlx_interaction1_click, &env);
	mlx_key_hook(env.env.win, &mlx_interaction1_key_click, &env);
	mlx_hook(env.env.win, 6, 0, &mlx_interaction1_hold, &env);
	mlx_hook(env.env.win, 5, 0, &mlx_interaction1_release, &env);
	mlx_hook(env.env.win, 17, 0, &mlx_close, &env);
	mlx_loop_hook(env.env.mlx, mlx_while, &env);
	mlx_loop(env.env.mlx);
	return (0);
}

int		main(int ac, char *av[])
{
	int		fract;

	fract = -1;
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			fract = 0;
		if (fract == -1 && ft_strcmp(av[1], "julia") == 0)
			fract = 1;
		if (fract == -1 && ft_strcmp(av[1], "burningship") == 0)
			fract = 2;
		if (fract != -1)
			mlx_init_main(fract);
	}
	if (fract == -1)
		ft_putstr("usage: ./fractol [mandelbrot/julia/burningship]\n");
	return (0);
}
