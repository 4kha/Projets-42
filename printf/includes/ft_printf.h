/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 22:41:08 by khtran            #+#    #+#             */
/*   Updated: 2018/01/08 03:05:12 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CHECK 1
# define PRINT 2

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>

typedef struct		s_print_trigger
{
	int				trigger1;
	int				trigger2;
	int				trigger3;
	int				trigger4;
	int				trigger5;
	int				trigger6;
	int				trigger7;
	unsigned int	precision;
	unsigned int	taille;
	int				format;
	int				hexamaj;
	char			*stock;
	int				have_stock;
}					t_print_trigger;

int					ft_printf(const char *string, ...);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_printf_wstr_count_error(wchar_t *var, size_t size);
int					ft_printf_wcount_error(wint_t var);
void				ft_putstrm(t_print_trigger arg);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
size_t				ft_min(size_t num, size_t num2);
void				ft_putstrn(char const *c);
void				ft_putnwstr(wchar_t const *c, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
size_t				ft_strwlen(const wchar_t *s);
size_t				ft_strwlen_cut(const wchar_t *s, size_t cut);
int					ft_printf_wcount(wchar_t var);
void				ft_printf_set(t_print_trigger *trigger);
int					ft_printf_error(char *string, va_list list, int ret);
void				ft_printfp_flag(char **string, t_print_trigger *arg);
void				ft_printfp_taille(char **string, t_print_trigger *arg,
		va_list list);
void				ft_printfp_precis(char **string, t_print_trigger *arg,
		va_list list);
void				ft_printfp_longueur(char **string, t_print_trigger *arg);
int					ft_abs(int num);
size_t				ft_max(size_t num, size_t num2);
size_t				ft_max_neg(int num, int num2);
size_t				ft_printf_nbrlen(uintmax_t nbr, int base);
void				ft_printf_putnbr(uintmax_t n, t_print_trigger arg);
void				ft_printf_putnbr_base(uintmax_t n, int base,
		t_print_trigger arg);
size_t				ft_printf_nbrlen_cumul(uintmax_t nbr, t_print_trigger arg,
		char *pre);
size_t				ft_printf_nbrlen_cumul_base(uintmax_t nbr, t_print_trigger
		arg, char *pre, int base);
intmax_t			ft_printf_type_convert_int(va_list list,
		t_print_trigger arg);
uintmax_t			ft_printf_type_convert_unsigned(va_list list,
		t_print_trigger arg);
void				ft_printf_diff(size_t used, size_t size, char motif);
int					ft_printf_last_flag(char **string, size_t *index,
		t_print_trigger arg, va_list list);
void				ft_printf_type_none(t_print_trigger arg, size_t *index);
int					ft_printf_type_str(size_t *index, t_print_trigger arg,
		va_list list);
int					ft_printf_type_wstr(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_unsigned(size_t *index, uintmax_t nbr,
		t_print_trigger arg, char *pre);
void				ft_printf_type_unsigned_hexa(size_t *index, uintmax_t nbr,
		t_print_trigger arg, char *pre);
void				ft_printf_type_int(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_pre_nbr_hexa(size_t *index, intmax_t nbr,
		t_print_trigger arg, char *pre);
void				ft_printf_type_ptr(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_long(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_pre_unsigned(size_t *index, t_print_trigger
		arg, va_list list);
void				ft_printf_type_long_unsigned(size_t *index, t_print_trigger
		arg, va_list list);
void				ft_printf_type_hexa_s(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_hexa_b(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_octal(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_octal_long(size_t *index, t_print_trigger
		arg, va_list list);
int					ft_printf_type_char(size_t *index, t_print_trigger
		arg, va_list list);
int					ft_printf_type_wchar(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_bin_long(size_t *index, t_print_trigger arg,
		va_list list);
void				ft_printf_type_bin(size_t *index, t_print_trigger arg,
		va_list list);

#endif
