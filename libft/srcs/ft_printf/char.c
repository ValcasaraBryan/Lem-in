/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char2(t_stringinfo *t)
{
	int oct;

	oct = (t->ch == 0 || (*t->str == 'c' && t->conversion < 3)) ? \
				1 : ft_octet((int)t->ch);
	t->sizemin = (t->sizemin > oct) ? t->sizemin - oct : 0;
	t->len += t->sizemin + oct;
	if (!t->aligne_g)
	{
		if (t->zeros)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	if (t->ch < 127)
		ft_putchar((char)t->ch);
	else if (t->ch && (*t->str == 'C' || t->conversion == 3))
		ft_putchar_unicode(t->ch, oct);
	else
	{
		ft_putchar((char)t->ch);
		t->len += 1 - oct;
	}
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
	t->ret += t->len;
}

void	ft_char(t_stringinfo *t)
{
	if (*t->str != 'c' && *t->str != 'C')
		t->ch = *t->str;
	else if (t->conversion == 3 || *t->str == 'C')
		t->ch = (wchar_t)va_arg(t->ap, unsigned int);
	else if (*t->str == 'c')
		t->ch = (unsigned char)va_arg(t->ap, unsigned int);
	ft_char2(t);
}
