/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:22:07 by khtran            #+#    #+#             */
/*   Updated: 2018/05/15 14:46:24 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	t_list		*ft_get_fd(int fd, t_list **start)
{
	t_list			*current;
	t_list			*test;

	current = (*start);
	test = current;
	while (current)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	if (current == NULL)
		exit(0);
	ft_lstadd(start, current);
	return (current);
}

static	int			ft_copy_line(char **line, char *src)
{
	int				index;
	int				len;

	len = 0;
	index = 0;
	while (src[len] != '\n' && src[len])
		len++;
	(*line) = (char*)malloc(sizeof(char) * (len + 1));
	if ((*line) == NULL)
		exit(0);
	(*line)[len] = 0;
	while (src[index] != '\n' && src[index])
	{
		(*line)[index] = src[index];
		index++;
	}
	return (len);
}

static	void		ft_decal_n_free(int size, t_list **new)
{
	char	*tmp;
	char	*tmp2;

	if ((*new)->content != NULL)
	{
		tmp = (*new)->content;
		if (ft_strlen((*new)->content) != (size_t)size)
			(*new)->content = (*new)->content + (size + 1);
		else
			(*new)->content = (*new)->content + (size);
		tmp2 = ft_strdup((*new)->content);
		if (tmp2 == NULL)
			exit(0);
		free(tmp);
		(*new)->content = tmp2;
	}
}

static int			gnl_ret(char **line, t_list **new, t_list **start, int ret)
{
	int				a;

	a = 0;
	if ((a = ft_copy_line(line, (*new)->content)) == -1 || ret == -1)
		return (-1);
	if (ret == 0 && ft_strlen((*new)->content) == 0)
	{
		ft_lstdelone(start, *new);
		return (0);
	}
	ft_decal_n_free(a, new);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*start;
	t_list			*new;
	char			buffer[BUFF_SIZE + 1];
	int				a;

	a = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	new = ft_get_fd(fd, &start);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = 0;
		new->content = ft_strjoin_and_free(new->content, buffer);
		if (new->content == NULL)
			exit(0);
		if (ft_strchr(new->content, '\n') != NULL)
			break ;
	}
	return (gnl_ret(line, &new, &start, ret));
}
