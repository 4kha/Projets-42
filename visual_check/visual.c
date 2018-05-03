/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 02:41:35 by khtran            #+#    #+#             */
/*   Updated: 2018/05/03 22:57:38 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../instruction.h"
#include "../../ftmlx/ftmlx.h"
#include "../mlx.h"
#include "../visual.h"

int		visual_step(t_list **pile_a, t_list **pile_b, t_env *env)
{
	char	*line;
	int		ret;

	if ((ret = get_next_line(0, &line)) == 1)
	{
		if (!line)
			ft_error();
		visual_find_tag(pile_a, pile_b, line);
		mlx_put_image_to_window((*env).env.mlx, (*env).env.win,
			(*env).fond.img, 0, 0);
		visual_maillon(env);
		free(line);
		line = NULL;
	}
	if (ret == -1)
		exit(0);
	free(line);
	return (0);
}

void	visual_env_set(t_env *env)
{
	(*env).t_pause = 0;
	(*env).fond.line_x = 1200;
	(*env).fond.line_y = 1000;
	(*env).mail.line_x = 1200;
	(*env).mail.line_y = 1000;
	visual_set(env);
}

void	visual_read(t_list *pile_a)
{
	t_list	*pile_b;
	t_env	env;
	int		len;

	pile_b = NULL;
	env.index = 0;
	env.pile_a = &pile_a;
	env.pile_b = &pile_b;
	len = ft_lstlen(pile_a);
	env.one_h = (double)(1200 / len);
	env.one_x = len;
	env.min = ft_lstmin_until(pile_a, len);
	env.max = ft_lstmax(pile_a);
	env.env.mlx = mlx_init();
	env.env.win = mlx_new_window(env.env.mlx, 1200, 1000, "Visual push_swap");
	env.fond.img = mlx_new_image(env.env.mlx, 1200, 1000);
	env.fond.src = (int*)mlx_get_data_addr(env.fond.img, &env.fond.line_x,
			&env.fond.line_y, &env.fond.endian);
	env.mail.img = mlx_new_image(env.env.mlx, 1200, 1000);
	env.mail.src = (int*)mlx_get_data_addr(env.mail.img, &env.mail.line_x,
			&env.mail.line_y, &env.mail.endian);
	visual_env_set(&env);
	visual_event_all(env);
}

void	visual_parse(int ac, char **av, int index)
{
	char	*chr;
	t_list	*start;
	t_list	*tmp;

	start = NULL;
	while (index < ac)
	{
		if ((chr = ft_strchr(av[index], ' ')) == NULL)
		{
			tmp = ft_lstnew("\0", 0);
			if (tmp == NULL)
				exit(0);
			tmp->content_size = ft_atoi(av[index++]);
			ft_lstlast(&start, tmp);
		}
		else
			checker_parse(&start, av[index++], chr);
	}
	check_doublon(start);
	visual_read(start);
}

int		main(int ac, char *av[])
{
	int		index;

	if (ac == 1)
		return (0);
	if (checker_check_arg(ac, av, 1))
		ft_error();
	index = 1;
	visual_parse(ac, av, index);
	return (0);
}
