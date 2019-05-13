/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:16:11 by khtran            #+#    #+#             */
/*   Updated: 2017/11/06 17:29:38 by khtran           ###   ########.fr       */
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

int		main(int ac, char *av[])
{
	int		index;

	index = 1;
	while (index < ac)
	{
		ft_putstr(av[index]);
		index++;
		ft_putchar('\n');
	}
	return (0);
}
