/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 08:42:08 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 02:45:40 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_parsing(char **string, va_list list, size_t *index,
		t_print_trigger *arg)
{
	int		ret;

	ft_printf_set(arg);
	if (*(++(*string)) == 0)
	{
		ft_putstrm(*arg);
		return (0);
	}
	while (ft_strchr(" #0-+*.hljz123456789", **string) != NULL && **string)
	{
		ft_printfp_flag(string, arg);
		ft_printfp_taille(string, arg, list);
		ft_printfp_precis(string, arg, list);
		ft_printfp_longueur(string, arg);
	}
	if (**string == 0)
	{
		ft_putstrm(*arg);
		return (0);
	}
	ret = ft_printf_last_flag(string, index, *arg, list);
	(*string)++;
	free((*arg).stock);
	(*arg).stock = NULL;
	return (ret);
}

void	ft_printf_arg_pont(int *ret, t_print_trigger *arg)
{
	(*arg).stock = NULL;
	(*ret) = 0;
}

int		ft_printf_arg(char *string, va_list list, size_t index_glob)
{
	char			*next;
	t_print_trigger arg;
	int				ret;

	ft_printf_arg_pont(&ret, &arg);
	while (string)
	{
		next = ft_strchr(string, '%');
		if (next == NULL)
		{
			ft_putstrn(string);
			return (index_glob + ft_strlen(string));
		}
		else if (next > string)
		{
			arg.stock = ft_strsub(string, 0, next - string);
			index_glob = index_glob + (next - string);
			string = string + (next - string);
		}
		else
			ret = ft_printf_parsing(&string, list, &index_glob, &arg);
		if (ret == -1)
			return (ret);
	}
	return (index_glob);
}

int		ft_printf(const char *string, ...)
{
	va_list	list;
	int		ret;

	va_start(list, string);
	ret = ft_printf_arg((char*)string, list, 0);
	va_end(list);
	return (ret);
}
