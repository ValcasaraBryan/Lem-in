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

void	ft_octal_no_prefixe(t_stringinfo *t, int base)
{
	int len;
	int print_nullunbr;

	print_nullunbr = (!t->precision && !t->unbr) ? 0 : 1;
	len = ft_size_base((size_t)t->unbr, base);
	if (!t->precision && !t->unbr)
		len = 0;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len) ? \
				t->sizemin - (t->precision + len) : 0;
	t->len += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	ft_putc_times('0', t->precision);
	if (print_nullunbr)
		ft_putnbr_base(t->unbr, base, 0, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
	t->ret += t->len;
}

void	ft_octal_prefixe(t_stringinfo *t, int base)
{
	int len;

	len = ft_size_base((size_t)t->unbr, base);
	if (!t->unbr)
		len = 0;
	t->precision = (t->precision > len) ? t->precision - len : 0;
	if (t->precision == 0)
		t->precision = 1;
	t->sizemin = (t->sizemin > t->precision + len) ? \
				t->sizemin - (t->precision + len) : 0;
	t->ret += t->sizemin + t->precision + len;
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	ft_putc_times('0', t->precision);
	if (t->unbr)
		ft_putnbr_base(t->unbr, base, 0, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
}

void	ft_pointeur2(t_stringinfo *t, int base, int maj, int print_nbr)
{
	if (!t->aligne_g)
	{
		if (t->zeros > 0)
		{
			ft_prefix(t, base, maj);
			t->prefixe = 0;
		}
		if (t->zeros > 0)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	if (t->prefixe == 2)
		ft_prefix(t, base, maj);
	ft_putc_times('0', t->precision);
	if (print_nbr)
		ft_putnbr_base(t->unbr, base, maj, 0);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
}

void	ft_pointeur(t_stringinfo *t, int base, int maj)
{
	int len;
	int print_nbr;

	print_nbr = 1;
	len = ft_size_base((size_t)t->unbr, base);
	if (!t->unbr && t->zeros)
		t->aligne_g = 0;
	if (t->precision == 0 && !t->unbr)
	{
		len = 0;
		print_nbr = 0;
	}
	t->precision = (t->precision > len) ? t->precision - len : 0;
	t->sizemin = (t->sizemin > t->precision + len + t->prefixe) ? \
				t->sizemin - (t->precision + len + t->prefixe) : 0;
	t->ret += t->sizemin + t->precision + len + t->prefixe;
	ft_pointeur2(t, base, maj, print_nbr);
}
