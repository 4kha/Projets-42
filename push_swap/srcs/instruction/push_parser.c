/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:01:58 by khtran            #+#    #+#             */
/*   Updated: 2018/05/08 18:19:00 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "instruction.h"

int		checker_check_arg(int ac, char **av, int index)
{
	int		index_y;
	int		index_x;
	char	actual;
	char	next;

	index_y = index;
	while (index_y < ac)
	{
		index_x = 0;
		while (av[index_y][index_x])
		{
			actual = av[index_y][index_x];
			next = av[index_y][index_x + 1];
			if (!ft_isdigit(actual) && !(ft_isdigit(next) && actual == ' '
				&& index_x != 0) && !(actual == '+' && ft_isdigit(next)) &&
				!(ft_isdigit(next) && actual == '-')
				&& !(actual == ' ' && next == '-'))
				return (1);
			index_x++;
		}
		if (index_x == 0)
			return (1);
		index_y++;
	}
	return (0);
}

void	checker_order(t_list *pile_a, t_list *pile_b)
{
	int		biggest;
	int		addr;
	int		tmp;

	if (pile_b != NULL)
		ft_ko();
	addr = pile_a->content_size;
	biggest = addr;
	while (pile_a != NULL)
	{
		addr = pile_a->content_size;
		tmp = addr;
		pile_a = pile_a->next;
		if (tmp >= biggest)
			biggest = tmp;
		else
			ft_ko();
	}
}

int		*checker_ptr(char *to_atoi)
{
	int		*result;
	int		tmp;

	tmp = ft_atoi(to_atoi);
	result = &tmp;
	return (result);
}

void	checker_parse(t_list **start, char *nbr, char *chr)
{
	t_list		*tmp;

	tmp = ft_lstnew("\0", 0);
	tmp->content_size = ft_atoi(nbr);
	ft_lstlast(start, tmp);
	while (*chr)
	{
		if (ft_isdigit(*chr) || *chr == '-')
		{
			tmp = ft_lstnew("\0", 0);
			tmp->content_size = ft_atoi(chr);
			ft_lstlast(start, tmp);
			while ((ft_isdigit(*chr) || *chr == '-') && *chr)
				chr++;
		}
		else
			chr++;
	}
}

void	check_doublon(t_list *start)
{
	t_list		*tmp;
	int			nbr;

	tmp = start;
	if (ft_lstlen(start) == 1)
	{
		ft_putstr("OK\n");
		exit(0);
	}
	while (start != NULL)
	{
		tmp = start->next;
		nbr = start->content_size;
		while (tmp)
		{
			if (tmp->content_size == nbr)
				ft_error();
			tmp = tmp->next;
		}
		start = start->next;
	}
}
