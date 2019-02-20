/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/05/18 15:37:41 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(uintmax_t n)
{
	int	size;

	size = 1;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int		ft_size_base(uintmax_t n, int base)
{
	if ((n / base) != 0)
		return (ft_size_base(n / base, base) + 1);
	return (1);
}

void	ft_putnbr_base(uintmax_t n, int base, int maj, int neg)
{
	char *tab;

	if (neg)
		write(1, "-", 1);
	if (maj)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if ((n / base) != 0)
		ft_putnbr_base(n / base, base, maj, 0);
	ft_putchar(tab[n % base]);
}

void	ft_init(t_stringinfo *t)
{
	t->conversion = 0;
	t->space = 0;
	t->zeros = 0;
	t->aligne_g = 0;
	t->sign = 0;
	t->precision = -1;
	t->prefixe = 0;
	t->sizemin = 0;
	t->len = 0;
	t->nbr = 0;
	t->unbr = 0;
	t->string = NULL;
	t->wstring = NULL;
	t->ch = 0;
	t->f = 0;
	t->long_double = 0;
}
