/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:50:13 by khtran            #+#    #+#             */
/*   Updated: 2018/05/15 14:43:30 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MODE 0
# define BUFF_SIZE 64
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	int				content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
char				*ft_itoa(int value);
char				*ft_itoa_base(int value, int base);
int					ft_nbrlen_base(int n, int base);
int					ft_nbrlen(int n);
char				ft_hexlet(int chiffre);
void				ft_error(char *error);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
void				ft_lstadd(t_list **alst, t_list *newe);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstlast(t_list **alst, t_list *newe);
int					ft_lstlen(t_list *list);
t_list				*ft_lstdup(t_list *target);
void				ft_lstfree(t_list *to_free);
void				ft_fd_close(int fd);
void				ft_fd_open(char *str, int *fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *c);
void				ft_putstr_fd(char const *c, int fd);
void				ft_putnbr(int value);
void				ft_putnbr_fd(int value, int fd);
void				ft_puttab(char **tab);
char				*ft_read(int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *src, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					get_next_line(const int fd, char **line);
void				ft_lstdelone(t_list **command, t_list *remove);
char				*ft_strjoin_and_free(char *s1, char *s2);

#endif
