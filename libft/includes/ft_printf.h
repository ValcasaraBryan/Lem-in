/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:27:37 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/22 19:10:50 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <locale.h>

typedef struct	s_stringinfo
{
	int			ret;
	char		*line;
	int			conversion;
	int			space;
	int			zeros;
	int			aligne_g;
	int			sign;
	int			precision;
	int			prefixe;
	int			sizemin;
	int			len;
	char		*str;
	intmax_t	nbr;
	uintmax_t	unbr;
	long double	fl;
	wchar_t		*wstring;
	char		*string;
	wchar_t		ch;
	va_list		ap;
	long double	f;
	int			long_double;
}				t_stringinfo;

int				ft_printf(char *str, ...);
char			*ft_strndup(const char *line, size_t i);
void			ft_putc_times(char c, int i);
void			ft_parse_flags(t_stringinfo *t);
void			ft_parse_specifier(t_stringinfo *t);
void			ft_unsigned(t_stringinfo *t);
void			ft_signed(t_stringinfo *t);
void			ft_char(t_stringinfo *t);
int				ft_str(t_stringinfo *t);
int				ft_str2(t_stringinfo *t);
void			ft_init(t_stringinfo *t);
int				ft_size(uintmax_t n);
void			ft_putnbr_base(uintmax_t n, int base, int maj, int neg);
int				ft_size_base(uintmax_t n, int base);
void			ft_putchar_unicode(wchar_t caract, int oct);
int				ft_octet(wchar_t caract);
void			ft_oct_print(t_stringinfo *t, int *oct);
void			ft_putfloat(t_stringinfo *t);
void			ft_pointeur(t_stringinfo *t, int base, int maj);
void			ft_octal_no_prefixe(t_stringinfo *t, int base);
void			ft_octal_prefixe(t_stringinfo *t, int base);
int				ft_prefix(t_stringinfo *t, int base, int maj);

#endif
