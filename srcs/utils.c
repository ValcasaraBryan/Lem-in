/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:25:13 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:01 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int			ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			*ft_alloc_tab_int(int n, int val_initial)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n)
	{
		tab[i] = val_initial;
		i++;
	}
	return (tab);
}

int			ft_length_path(int *tab, int n)
{
	int		i;

	i = 0;
	if (!tab || n <= 0)
		return (0);
	while (i < n && i >= 0 && tab[i] >= 0)
		i++;
	return (i);
}
