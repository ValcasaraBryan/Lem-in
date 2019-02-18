/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <glebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:37:39 by glebouch          #+#    #+#             */
/*   Updated: 2018/11/01 18:18:51 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tab(unsigned char *tab)
{
	tab[0] = 192;
	tab[1] = 128;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
}

void	ft_putchar_unicode(wchar_t caract, int oct)
{
	unsigned char	tab[5];
	int				i;

	i = 1;
	init_tab(tab);
	if (oct == 3)
	{
		tab[0] = 224;
		tab[2] = 128;
	}
	else if (oct == 4)
	{
		tab[0] = 240;
		tab[2] = 128;
		tab[3] = 128;
	}
	while (i <= oct)
	{
		tab[oct - i] += caract & 63;
		caract = caract >> 6;
		i++;
	}
	i = 0;
	while (tab[i])
		ft_putchar(tab[i++]);
}

int		ft_octet(wchar_t caract)
{
	int len;

	len = ft_size_base(caract, 2);
	if (len <= 7)
		return (1);
	if (len <= 11)
		return (2);
	if (len <= 16)
		return (3);
	if (len <= 21)
		return (4);
	return (0);
}

void	ft_parse_specifier(t_stringinfo *t)
{
	if (ft_strchr("Ddi", *t->str))
		ft_signed(t);
	else if (*t->str == 'f')
		ft_putfloat(t);
	else if (ft_strchr("oOuUxXp", *t->str))
	{
		if (t->prefixe && (*t->str == 'x' || *t->str == 'X' || *t->str == 'p'))
			t->prefixe = 2;
		ft_unsigned(t);
	}
	else if (*t->str == 's' || *t->str == 'S')
		ft_str(t);
	else if (*t->str)
		ft_char(t);
}
