/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:15 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/15 17:40:29 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_compare(t_infos *infos, int *tab1, int *tab2)
{
	// ft_putendl("compare deb");
	int i;
	int j;
	int l1;
	int l2;

	i = 0;
	l1 = ft_length_path(tab1, infos->nb_of_box);
	// ft_putendl("compare deb3");
	l2 = ft_length_path(tab2, infos->nb_of_box);
	// ft_putendl("compare deb2");
	while (++i < l1 - 1)
	{
		j = 0;
		while (++j < l2 - 1)
		{
			// ft_putendl("compare deb2222");
			if (tab1[i] == tab2[j])
			{
				// ft_putnbr(j);
				return (0);
			}
		}
	}
	// ft_putendl("out comp");
	return (1);
}

int		ft_compare_tab(t_infos *in, int *tab, int n)
{
	// ft_putendl("compare tb");
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{
			if (!(ft_compare(in, in->t_p[tab[i]], in->t_p[tab[j]])))
				return (j);
		}
	}
	// ft_putendl("comp 2");
	return (0);
}

int		ft_up_index(t_infos *infos, int *t_p_c, int index_to_up, int n)
{
	int tmp;
	int i;

	i = 1;
	while (index_to_up >= 0 &&
			t_p_c[index_to_up] == infos->t_p[0][0] - n + index_to_up)
		index_to_up--;
	if (index_to_up < 0)
		return (-1);
	t_p_c[index_to_up]++;
	if (t_p_c[index_to_up] > infos->t_p[0][0])
		return (-1);
	tmp = t_p_c[index_to_up];
	while (++index_to_up < n)
	{
		t_p_c[index_to_up] = tmp + i;
		i++;
	}
	return (0);
}

/*
**	lpm = length path max
**	t_p = tab_path
**	tpci = tab_path_compatibles[i], contient les index des chemins du groupe i
*/

int		ft_choose_path_i(t_infos *inf, int *tpc_i, int n)
{
	int k;
	int index_to_up;
	int nb_path_compatible;
	int lpm;

	index_to_up = 0;
	nb_path_compatible = 1;
	lpm = ft_length_path(inf->t_p[n], inf->nb_of_box);
	while (nb_path_compatible < n)
	{
		k = -1;
		while (++k < n && k < inf->t_p[0][0])
			tpc_i[k] = k + 1;
		while (nb_path_compatible < n && \
			ft_length_path(inf->t_p[tpc_i[n - 1]], inf->nb_of_box) <= lpm)
		{
			if (!(index_to_up = ft_compare_tab(inf, tpc_i, n)))
				return (1);
			else if (ft_up_index(inf, tpc_i, index_to_up, n) == -1)
				return (-1);
		}
		if (nb_path_compatible != n && tpc_i[0] < inf->t_p[0][0] - (n - 1))
			lpm = ft_length_path(inf->t_p[tpc_i[n - 1]], inf->nb_of_box);
	}
	return (0);
}

void ft_put_tab_path(t_infos *inf)
{
	int i = 0;
	int j = 0;

	while (++i < inf->t_p[0][0])
	{
		j = 0;
		while(j < inf->nb_of_box && inf->t_p[i][j] != -1)
		{
			// ft_putnbr(inf->t_p[i][j]);
			// ft_putchar(' ');
			j++;
		}
		// ft_putendl("");
	} 
}

int		ft_choose_paths(t_infos *infos)
{
	int i;
	// ft_put_tab_path(infos);

	i = 0;
	if (!infos->jpp++)
		ft_free_tab_int(infos->t_p_c, infos->nb_path_max);
	if (!(infos->t_p_c = (int**)ft_memalloc(sizeof(int*) * infos->nb_path_max)))
		return (0);
	// ft_putnbr(infos->t_p[0][0]);
	while (i < ft_min_int(infos->nb_path_max, infos->t_p[0][0]))
	{
		if (!(infos->t_p_c[i] = (int*)ft_memalloc(sizeof(int) * (i + 1))))
		{
			ft_free_tab_int(infos->t_p_c, i);
			return (-1);
		}
		if (i == 0)
			infos->t_p_c[i][0] = 1;
		else if (i > 0 && ft_choose_path_i(infos, infos->t_p_c[i], i + 1) < 0)
		{
//			ft_free_tab_int(infos->t_p_c, i);
			return (i);
		}
		i++;
	}
	return (i);
}
