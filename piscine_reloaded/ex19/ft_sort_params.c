/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:31:40 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 18:08:08 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *c)
{
	int		index;

	index = 0;
	while (c[index])
	{
		ft_putchar(c[index]);
		index++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	return (s1[index] - s2[index]);
}

int		main(int ac, char *av[])
{
	int		index;

	index = 1;
	if (ac > 1)
	{
		while (index + 1 < ac)
		{
			if (ft_strcmp(av[index], av[index + 1]) > 0)
			{
				ft_swap(&av[index], &av[index + 1]);
				index = 0;
			}
			index++;
		}
	}
	index = 1;
	while (index < ac)
	{
		ft_putstr(av[index]);
		index++;
		ft_putchar('\n');
	}
	return (0);
}
