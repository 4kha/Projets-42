/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 06:30:23 by khtran            #+#    #+#             */
/*   Updated: 2019/01/31 18:38:07 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	char	*wf_strjoin_and_free2(char *s1, char *s2, int ret, int *clen)
{
	char	*str;

	(*clen) = (*clen) + ret;
	str = (char*)malloc(sizeof(char) * ((*clen) + 1));
	if (str == NULL)
		return (NULL);
	str[(*clen)] = '\0';
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if ((*clen - ret))
		free(s1);
	return (str);
}

int				wf_buffer_check(char *buff)
{
	int		index;

	index = 0;
	while (buff[index])
	{
		if (ft_strchr(MAP_SYMBOL, buff[index]) == NULL)
			return (1);
		index++;
	}
	return (0);
}

char			*wf_read(int fd)
{
	int		ret;
	int		clen;
	char	buffer[BUFF_SIZE + 1];
	char	*new;

	clen = 0;
	new = "\0";
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if ((*new == '\0' && *buffer == '\0')
				|| wf_buffer_check(buffer))
			return (NULL);
		new = wf_strjoin_and_free2(new, buffer, ret, &clen);
		if (new == NULL)
			return (NULL);
	}
	return (new);
}

void			wf_event_press_start2(t_env *env)
{
	int		index;

	index = 0;
	SDL_ShowCursor(SDL_DISABLE);
	while (env->stop && env->pause == 1)
	{
		while (SDL_PollEvent(&(env->event)))
		{
			if (env->event.type == SDL_QUIT || (env->event.type == SDL_KEYDOWN
				&& env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
				env->stop = 0;
			if (env->keyboard[SDL_SCANCODE_SPACE])
				env->pause = 0;
		}
		SDL_Delay(20);
		index++;
		if (index == 20)
		{
			index = 0;
			SDL_RenderPresent(env->render);
		}
	}
}
