/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:38:07 by khtran            #+#    #+#             */
/*   Updated: 2018/05/08 18:17:18 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "checker.h"

void	checker_find_tag(t_list **pile_a, t_list **pile_b, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		push_swap_sx(pile_a);
	else if (ft_strcmp(line, "sb") == 0)
		push_swap_sx(pile_b);
	else if (ft_strcmp(line, "ss") == 0)
		push_swap_ss(pile_a, pile_b);
	else if (ft_strcmp(line, "pa") == 0)
		push_swap_px(pile_b, pile_a);
	else if (ft_strcmp(line, "pb") == 0)
		push_swap_px(pile_a, pile_b);
	else if (ft_strcmp(line, "ra") == 0)
		push_swap_rx(pile_a);
	else if (ft_strcmp(line, "rb") == 0)
		push_swap_rx(pile_b);
	else if (ft_strcmp(line, "rr") == 0)
		push_swap_rr(pile_a, pile_b);
	else if (ft_strcmp(line, "rra") == 0)
		push_swap_rrx(pile_a);
	else if (ft_strcmp(line, "rrb") == 0)
		push_swap_rrx(pile_b);
	else if (ft_strcmp(line, "rrr") == 0)
		push_swap_rrr(pile_a, pile_b);
	else
		ft_error();
}

int		checker_read(t_list *pile_a, t_list *pile_b, int option)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) == 1)
	{
		if (!line)
			ft_error();
		checker_find_tag(&pile_a, &pile_b, line);
		if (option == 1)
			checker_visual_flat(pile_a, pile_b, line);
		if (option == 2)
			checker_count_command(line, 0);
		free(line);
	}
	if (ret == -1)
		exit(0);
	if (option == 1)
		checker_visual_flat(pile_a, pile_b, "end");
	if (option == 2)
		checker_count_command(line, 1);
	checker_order(pile_a, pile_b);
	ft_lstfree(pile_a);
	ft_lstfree(pile_b);
	free(line);
	return (0);
}

void	checker_start(int ac, char **av, int index, int option)
{
	char	*chr;
	t_list	*start;
	t_list	*pile_b;
	t_list	*tmp;

	pile_b = NULL;
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
	checker_read(start, pile_b, option);
	ft_putstr("OK\n");
}

int		main(int ac, char *av[])
{
	int		index;
	int		option;

	option = 0;
	index = 1;
	if (ac == 1)
		return (0);
	if (ft_strcmp(av[1], "-v") == 0)
	{
		index++;
		option = 1;
	}
	if (ft_strcmp(av[1], "-s") == 0)
	{
		index++;
		option = 2;
	}
	if (option != 0 && ac == 2)
		return (0);
	if (checker_check_arg(ac, av, index))
		ft_error();
	checker_start(ac, av, index, option);
	return (0);
}
