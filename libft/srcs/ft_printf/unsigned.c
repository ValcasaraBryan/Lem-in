/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:58 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:27:36 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefix(t_stringinfo *t, int base, int maj)
{
	if (!t->prefixe)
		return (0);
	if (base == 8)
		ft_putchar('0');
	else if (base == 16 && maj)
		ft_putstr("0X");
	else if (base == 16)
		ft_putstr("0x");
	return (0);
}

void	ft_hexa_dec2(t_stringinfo *t, int base, int maj, int len)
{
	if (!t->aligne_g)
	{
		if (t->prefixe && t->zeros > 0 && t->unbr)
		{
			ft_prefix(t, base, maj);
			t->prefixe = 0;
		}
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	if (t->unbr || (!t->unbr && t->prefixe == 2))
		ft_prefix(t, base, maj);
	ft_putc_times('0', t->precision);
	if (len || (!t->unbr && t->prefixe))
		ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
}

void	ft_hexa_dec(t_stringinfo *t, int base, int maj)
{
	int len;
	int precision_init_zero;

	precision_init_zero = 0;
	if (t->unbr == 0 || *t->str == 'u' || *t->str == 'U')
		t->prefixe = 0;
	len = ft_size_base((size_t)t->unbr, base) + t->prefixe;
	if (t->precision == 0 && t->unbr == 0)
		len = 0;
	t->precision = (t->precision > (len - t->prefixe)) ? \
				t->precision - (len - t->prefixe) : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? \
				t->sizemin - (t->precision + len) : 0;
	t->ret += t->sizemin + t->precision + len;
	ft_hexa_dec2(t, base, maj, len);
}

void	ft_unsigned2(t_stringinfo *t)
{
	if ((*t->str == 'o' || *t->str == 'O') && t->prefixe)
		ft_octal_prefixe(t, 8);
	else if ((*t->str == 'o' || *t->str == 'O') && !t->prefixe)
		ft_octal_no_prefixe(t, 8);
	else if (*t->str == 'u' || *t->str == 'U')
		ft_hexa_dec(t, 10, 0);
	else if (*t->str == 'x')
		ft_hexa_dec(t, 16, 0);
	else if (*t->str == 'X')
		ft_hexa_dec(t, 16, 1);
	else if (*t->str == 'p')
	{
		t->prefixe = 2;
		ft_pointeur(t, 16, 0);
	}
}

void	ft_unsigned(t_stringinfo *t)
{
	if (t->conversion == 3 || ft_strchr("OUp", *t->str))
		t->unbr = va_arg(t->ap, unsigned long int);
	else if (t->conversion == 1)
		t->unbr = (unsigned char)va_arg(t->ap, unsigned int);
	else if (t->conversion == 2)
		t->unbr = (unsigned short)va_arg(t->ap, unsigned int);
	else if (t->conversion == 4)
		t->unbr = va_arg(t->ap, unsigned long long);
	else if (t->conversion == 5)
		t->unbr = va_arg(t->ap, uintmax_t);
	else if (t->conversion == 6)
		t->unbr = va_arg(t->ap, size_t);
	else if (t->conversion == 0)
		t->unbr = (unsigned int)va_arg(t->ap, int);
	ft_unsigned2(t);
}
