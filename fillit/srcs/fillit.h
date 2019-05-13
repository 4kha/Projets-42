/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:04:59 by rbechir           #+#    #+#             */
/*   Updated: 2017/11/22 16:27:36 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 128

char	**ft_grow_all_shape(char **tab, int n);
int		ft_check_block(char **tab);
int		ft_check_format(char *string, int *tetrimino);
int		ft_check_four(char **string);
int		ft_check_line(char **string, int *symbol);
char	**ft_convert(char *string, int figure);
char	*ft_convert_one(char *string);
char	*ft_strtrim_fillit(char const *s);
int		ft_init(char **tab, int figure);
char	*ft_read(int fd);
char	*ft_strjoin_and_free(char *s1, char *s2, int ret, int *clen);
int		ft_have_place(char *str, char *figure);
void	ft_place(char *str, char *tetri, char symb);
int		ft_solve(char **tab, char *grid, int figure, int state);
char	*ft_prepare(int size);
int		ft_errors(int fd);
void	ft_putstr(char const *s);
char	*ft_insert_char(char *str, int n, char c, int pos);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);

#endif
