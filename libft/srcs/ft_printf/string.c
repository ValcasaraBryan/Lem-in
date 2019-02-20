/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oct_print(t_stringinfo *t, int *oct)
{
	int i;

	i = 0;
	if (t->precision == 0)
		return ;
	else if (t->precision == -1)
	{
		while (t->wstring[i])
		{
			*oct += ft_octet(t->wstring[i]);
			i++;
		}
	}
	else
	{
		while (*oct < t->precision && t->wstring[i])
		{
			if (*oct + ft_octet(t->wstring[i]) <= t->precision)
				*oct += ft_octet(t->wstring[i]);
			else
				return ;
			i++;
		}
	}
}

void	ft_wstr3(t_stringinfo *t, int oct)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!t->aligne_g)
	{
		if (t->zeros)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	while (j < oct)
	{
		if (t->wstring[i] < 127)
			ft_putchar(t->wstring[i]);
		else
			ft_putchar_unicode(t->wstring[i], ft_octet(t->wstring[i]));
		j += ft_octet(t->wstring[i]);
		i++;
	}
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
}

int		ft_wstr2(t_stringinfo *t)
{
	int oct;

	oct = 0;
	if (t->wstring == NULL)
	{
		t->string = "(null)";
		ft_str2(t);
		return (0);
	}
	if (!t->precision)
		t->wstring = NULL;
	ft_oct_print(t, &oct);
	t->sizemin = (oct < t->sizemin) ? t->sizemin - oct : 0;
	t->ret += t->sizemin + oct;
	ft_wstr3(t, oct);
	return (0);
}

int		ft_str2(t_stringinfo *t)
{
	int len;

	len = 0;
	if (!t->precision)
		t->string = "";
	if (t->string == NULL)
		t->string = "(null)";
	len = ft_strlen((char*)t->string);
	if (t->precision > len || t->precision < 0)
		t->precision = len;
	t->sizemin = (t->precision < t->sizemin) ? t->sizemin - t->precision : 0;
	t->ret += t->sizemin + t->precision;
	if (!t->aligne_g)
	{
		if (t->zeros)
			ft_putc_times('0', t->sizemin);
		else
			ft_putc_times(' ', t->sizemin);
	}
	if (t->string[0])
		ft_putnstr((char *)t->string, t->precision);
	if (t->aligne_g)
		ft_putc_times(' ', t->sizemin);
	return (0);
}

int		ft_str(t_stringinfo *t)
{
	if (*t->str == 'S' || t->conversion == 3)
	{
		t->wstring = (wchar_t *)va_arg(t->ap, wchar_t *);
		ft_wstr2(t);
	}
	else if (*t->str == 's')
	{
		t->string = (char*)va_arg(t->ap, char *);
		ft_str2(t);
	}
	return (0);
}
