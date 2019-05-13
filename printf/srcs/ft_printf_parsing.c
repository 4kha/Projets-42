/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:42:33 by khtran            #+#    #+#             */
/*   Updated: 2018/01/06 17:43:47 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfp_flag(char **string, t_print_trigger *arg)
{
	while (**string == ' ' || **string == '#' || **string == '0'
			|| **string == '-' || **string == '+')
	{
		if (**string == '#')
			(*arg).trigger1 = 1;
		if (**string == '0')
			(*arg).trigger2 = 1;
		if (**string == '-')
			(*arg).trigger3 = 1;
		if (**string == '+')
			(*arg).trigger4 = 1;
		if (**string == ' ')
			(*arg).trigger5 = 1;
		(*string)++;
	}
}

void	ft_printfp_taille(char **string, t_print_trigger *arg, va_list list)
{
	int		tmp;

	while (ft_isdigit(**string) || **string == '*')
	{
		if (**string == '*')
		{
			(*string)++;
			tmp = va_arg(list, int);
			if (tmp < 0)
				(*arg).trigger3 = 1;
			(*arg).trigger6 = 1;
			(*arg).taille = ft_abs(tmp);
		}
		else
		{
			(*arg).trigger6 = 1;
			(*arg).taille = 0;
			while (ft_isdigit(**string))
			{
				(*arg).taille *= 10;
				(*arg).taille += (**string - '0');
				(*string)++;
			}
		}
	}
}

void	ft_printfp_precis(char **string, t_print_trigger *arg, va_list list)
{
	int		tmp;

	if (**string == '.')
	{
		(*arg).precision = 0;
		(*arg).trigger7 = 1;
		(*string)++;
		if (**string == '*')
		{
			(*string)++;
			tmp = va_arg(list, int);
			if (tmp >= 0)
				(*arg).precision = tmp;
			else
				(*arg).trigger7 = 0;
		}
		else
		{
			while (ft_isdigit(**string))
			{
				(*arg).precision = ((*arg).precision * 10) + (**string - '0');
				(*string)++;
			}
		}
	}
}

void	ft_printfp_longueur(char **string, t_print_trigger *arg)
{
	if ((string[0][1]) && *(string[0]) == 'h' && (string[0][1] == 'h'))
	{
		(*arg).format = ft_max(1, (*arg).format);
		(*string) += 2;
	}
	else if ((string[0][1]) && *(string[0]) == 'l' && ((string[0][1]) == 'l'))
	{
		(*arg).format = ft_max(4, (*arg).format);
		(*string) += 2;
	}
	else if (**string == 'h' || **string == 'l' || **string == 'j'
			|| **string == 'z')
	{
		if (**string == 'h')
			(*arg).format = ft_max(2, (*arg).format);
		else if (**string == 'l')
			(*arg).format = ft_max(3, (*arg).format);
		else if (**string == 'j')
			(*arg).format = ft_max(5, (*arg).format);
		else if (**string == 'z')
			(*arg).format = ft_max(6, (*arg).format);
		(*string)++;
	}
}
