/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:40:59 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/27 01:13:34 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		cw_check_reg(t_asm *comp, char *str, int i)
{
	int		start;
	int		nbr;
	char	*tmp;

	if (str[i] != 'r')
		cw_error(comp, "Bad parameter (not a register)\n");
	i++;
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(tmp = ft_strsub(str, start, i - start)))
		cw_error(comp, "Malloc error (checking register)\n");
	nbr = ft_atoi(tmp);
	free(tmp);
	if (nbr < 1 || nbr > REG_NUMBER)
		cw_error(comp, "Bad reg number\n");
	i = ft_skip_whitespace(str, i);
	if (str[i] && str[i] != SEPARATOR_CHAR)
		cw_error(comp, "Syntax error\n");
	return (i);
}

int		cw_check_ind(t_asm *comp, char *str, int i)
{
	if (str[i] == DIRECT_CHAR || str[i] == 'r')
		cw_error(comp, "Bad parameter (not an indirect)\n");
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	i = ft_skip_whitespace(str, i);
	if (str[i] && str[i] != SEPARATOR_CHAR)
		cw_error(comp, "Syntax error\n");
	return (i);
}

int		cw_check_dir(t_asm *comp, char *str, int i)
{
	if (str[i] != DIRECT_CHAR)
		cw_error(comp, "Bad parameter (not a direct)\n");
	i++;
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	i = ft_skip_whitespace(str, i);
	if (str[i] && str[i] != SEPARATOR_CHAR)
		cw_error(comp, "Syntax error\n");
	return (i);
}

void	cw_count_args(t_asm *comp, char *str, int nbr)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] != SEPARATOR_CHAR && !ft_iswhitespace(str[i]))
			i++;
		i = ft_skip_whitespace(str, i);
		if (str[i] == SEPARATOR_CHAR)
			i = ft_skip_whitespace(str, i + 1);
		nb++;
	}
	if (nb != nbr)
		cw_error(comp, "Bad number of parameters\n");
}
