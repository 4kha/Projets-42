/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:46:52 by khtran            #+#    #+#             */
/*   Updated: 2017/12/10 22:20:26 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		ft_exit(int keycode, t_lim *param)
{
	if (keycode == 125)
		(*param).prof += 1;
	if (keycode == 126 && (*param).prof > 0)
		(*param).prof -= 1;
	if (keycode == 53)
		exit(0);
	mlx_grid_open(*param);
	return (0);
}

int		mlx_open(char *str, int *fd)
{
	if ((*fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Open failure\n", 2);
		exit(1);
	}
	return (0);
}

int		mlx_close(int fd)
{
	if ((fd = close(fd)) == -1)
	{
		ft_putstr_fd("Close failure\n", 2);
		exit(1);
	}
	return (0);
}

int		mlx_grid_open(t_lim fen)
{
	int		endien;
	int		size;

	fen.img.img = mlx_new_image(fen.mlx, 1200, 800);
	fen.img.src = (int*)mlx_get_data_addr(fen.img.img, &size,
			&fen.img.line, &endien);
	fen.img.line = fen.img.line / 4;
	mlx_grid(&fen);
	mlx_put_image_to_window(&fen, fen.win, fen.img.img, 0, 0);
	mlx_destroy_image(fen.mlx, fen.img.img);
	return (0);
}

int		main(int ac, char *av[])
{
	t_lim	win;
	int		fd;

	if (ac == 2)
	{
		win.mlx = mlx_init();
		win.img.y = 800;
		win.win = mlx_new_window(win.mlx, 1440, 800, "fdf");
		mlx_open(av[1], &fd);
		mlx_prepare_pos(fd, &win);
		mlx_close(fd);
		mlx_open(av[1], &fd);
		win.matrice = mlx_matrice(fd, win);
		mlx_close(fd);
		win.size_z = mlx_matrice_highest(win.matrice, win);
		mlx_interface_all(&win);
		mlx_loop(win.mlx);
	}
	else
		ft_putstr("usage: ./fdf target_file\n");
	return (0);
}
