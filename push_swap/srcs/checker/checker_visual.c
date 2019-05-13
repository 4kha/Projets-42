/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:56:44 by khtran            #+#    #+#             */
/*   Updated: 2018/05/04 20:07:42 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "instruction.h"

int				ft_nbrlen(int number)
{
	int				count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		count++;
	while (number != 0)
	{
		count++;
		number = number / 10;
	}
	return (count);
}

void			ft_repchar(int space, char i)
{
	int				count;

	count = 0;
	while (count != space)
	{
		ft_putchar(i);
		count++;
	}
}

void			checker_visual_flat(t_list *pile_a, t_list *pile_b, char *line)
{
	int				size;

	size = 12;
	ft_putstr(line);
	ft_putstr("\n--------------------------\n");
	while (pile_a != NULL || pile_b != NULL)
	{
		if (pile_a != NULL)
		{
			ft_putnbr(pile_a->content_size);
			ft_repchar(size - ft_nbrlen(pile_a->content_size), ' ');
			pile_a = pile_a->next;
		}
		else
			ft_repchar(size, ' ');
		ft_putstr(" | ");
		if (pile_b != NULL)
		{
			ft_putnbr(pile_b->content_size);
			pile_b = pile_b->next;
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

static	t_list	*ft_get_line(char *type, t_list **start)
{
	t_list			*current;
	t_list			*test;

	current = (*start);
	test = current;
	while (current)
	{
		if (ft_strcmp(current->content, type) == 0)
			return (current);
		current = current->next;
	}
	current = ft_lstnew(type, ft_strlen(type));
	if (current == NULL)
		exit(0);
	current->content_size = 0;
	ft_lstadd(start, current);
	return (current);
}

void			checker_count_command(char *line, int mode)
{
	static t_list	*chain;
	t_list			*new;

	if (mode == 0)
	{
		new = ft_get_line(line, &chain);
		new->content_size++;
	}
	if (mode == 1)
	{
		new = chain;
		while (new != NULL)
		{
			ft_putstr(new->content);
			ft_putstr(" : ");
			ft_putnbr(new->content_size);
			ft_putstr("\n");
			new = new->next;
		}
		ft_lstfree(chain);
	}
}
