/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbechir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:58:52 by rbechir           #+#    #+#             */
/*   Updated: 2018/06/20 00:22:20 by rbechir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFF_SIZE 2056

# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_print
{
	va_list	args;
	char	*format;
	char	*buff;
	char	*flags;
	int		len;
	int		start_f;
	int		end_f;
	int		offset;
	int		flag;
	int		width;
	int		precision;
	int		modifier;
}				t_print;

int				ft_abs(int n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_wstrlen(wchar_t *s);
int				ft_nbrlen(int n);
int				ft_nbrlen_base(int n, int base);
int				ft_nbrlenmax_base(intmax_t n, int base);
int				ft_unbrlenmax_base(uintmax_t n, int base);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isnumber(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_iswhitespace(int c);
int				ft_isgreyspace(int c);
int				ft_isint(char *str);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_skip_whitespace(char *str, int i);
int				ft_atoi(const char *str);
intmax_t		ft_atoimax(char *str);
int				ft_hextoi(char *str);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strchri(const char *s, int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				*ft_intjoin(int *nb1, int *nb2, int size1, int size2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				*ft_intsplit(char *str, char c, int *size);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base, int maj);
char			*ft_imaxtoa(intmax_t n);
char			*ft_imaxtoa_base(intmax_t n, int base, int maj);
char			*ft_uimaxtoa_base(uintmax_t n, int base, int maj);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_printstrtab(char **tab);
void			ft_free_tab(char **tab);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_insert_char(char *str, int n, char c, int pos);
int				ft_sqrt(int n);
int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
int				ft_check_offset(t_print *wal);
int				ft_check_flag(t_print *wal);
int				ft_check_precision(t_print *wal);
int				ft_check_width(t_print *wal);
int				ft_check_modifier(t_print *wal);
int				ft_process_flags(t_print *wal);
int				ft_get_modifiers(t_print *wal);
int				ft_verif_modifiers_diou(char *c, int *mod);
int				ft_verif_modifiers_csp(char *c, int *mod);
char			*ft_conv_dioux(t_print *wal, char c);
char			*ft_conv_oux(t_print *wal, char c, int mod);
char			*ft_apply_modifs_oux(t_print *wal, int mod, int base, int maj);
char			*ft_conv_csp(t_print *wal, char c);
char			*ft_cut_mask(char *str);
char			*ft_flags_width(t_print *wal, char *str, char c);
char			*ft_precision(t_print *wal, char *str, char c);
int				ft_write_and_free(t_print *wal);
int				ft_free_and_quit(t_print *wal);

#endif
