/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:45:39 by khtran            #+#    #+#             */
/*   Updated: 2018/05/08 16:58:38 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"

void	push_swap_fonction(t_list *start, t_list **command,
		int (tri_algo)(t_list *a, t_list **b, int c))
{
	t_list	*other_command;
	int		len;

	len = ft_lstlen(*command);
	other_command = NULL;
	tri_algo(ft_lstdup(start), &other_command, len);
	if (len > ft_lstlen(other_command))
	{
		ft_lstfree(*command);
		*command = other_command;
		len = ft_lstlen(*command);
	}
	else
		ft_lstfree(other_command);
	other_command = NULL;
}

void	push_swap_quick(t_list *start, t_list **command,
		int (tri_algo)(t_list *a, t_list **b, int c))
{
	t_list	*other_command;
	int		len1;
	int		len2;
	int		count;

	count = 10;
	len1 = ft_lstlen(*command);
	len2 = ft_lstlen(start);
	other_command = NULL;
	while (count < len2 && len2 <= 200)
	{
		tri_algo(ft_lstdup(start), &other_command, count);
		if (len1 > ft_lstlen(other_command))
		{
			ft_lstfree(*command);
			*command = other_command;
			len1 = ft_lstlen(*command);
		}
		else
			ft_lstfree(other_command);
		count += 5;
		other_command = NULL;
	}
}

void	push_swap_sort(t_list *start)
{
	t_list	*command;
	t_list	*begin;

	command = NULL;
	push_swap_sort_1_setup(ft_lstdup(start), ft_lstlen(start), &command);
	push_swap_quick(start, &command, &push_swap_sort_5_setup);
	push_swap_fonction(start, &command, &push_swap_sort_3_setup);
	push_swap_fonction(start, &command, &push_swap_sort_2_setup_min);
	push_swap_fonction(start, &command, &push_swap_sort_2_setup_max);
	begin = command;
	while (command != NULL)
	{
		ft_putstr(command->content);
		ft_putchar('\n');
		command = command->next;
	}
	ft_lstfree(begin);
	ft_lstfree(start);
}

void	push_swap_parse(int ac, char **av, int index)
{
	char		*chr;
	t_list		*tmp;
	t_list		*start;

	start = NULL;
	while (index < ac)
	{
		if ((chr = ft_strchr(av[index], ' ')) == NULL)
		{
			tmp = ft_lstnew("\0", 2);
			if (tmp == NULL)
				exit(0);
			tmp->content_size = ft_atoi(av[index++]);
			ft_lstlast(&start, tmp);
		}
		else
			checker_parse(&start, av[index++], chr);
	}
	if (ft_lstlen(start) == 1)
		exit(0);
	check_doublon(start);
	push_swap_sort(start);
}

int		main(int ac, char *av[])
{
	int			index;

	if (ac == 1)
		return (0);
	if (checker_check_arg(ac, av, 1))
		ft_error();
	index = 1;
	push_swap_parse(ac, av, index);
	return (0);
}
