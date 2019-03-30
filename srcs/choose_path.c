/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:15 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:27:43 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <time.h>

int		ft_compare(t_infos *infos, int *tab1, int *tab2)
{
	int i;
	int j;
	int l1;
	int l2;

	i = 0;
	l1 = ft_length_path(tab1, infos->nb_of_box);
	l2 = ft_length_path(tab2, infos->nb_of_box);
	while (++i < l1 - 1)
	{
		j = 0;
		while (++j < l2 - 1)
			if (tab1[i] == tab2[j])
				return (0);
	}
	return (1);
}

int		ft_compare_tab(t_infos *in, int *tab, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (!(ft_compare(in, in->t_p[tab[i]], in->t_p[tab[j]])))
				return (j);
	}
	return (0);
}

int		ft_up_index(t_infos *infos, int *t_p_c, int index_to_up, int n)
{
	int tmp;
	int i;

	i = 1;
	while (index_to_up >= 0
		&& t_p_c[index_to_up] == infos->t_p[0][0] - n + index_to_up)
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
	int		k;
	int		index_to_up;
	int		nb_path_compatible;
	int		lpm;
	time_t	t;

	t = time(NULL);
	index_to_up = 0;
	nb_path_compatible = 1;
	lpm = ft_length_path(inf->t_p[n], inf->nb_of_box);
	while (nb_path_compatible < n)
	{
		k = -1;
		while (++k < n && k < inf->t_p[0][0])
			tpc_i[k] = k + 1;
		t = time(NULL);
		while (nb_path_compatible < n
			&& ft_length_path(inf->t_p[tpc_i[n - 1]], inf->nb_of_box) <= lpm)
		{
			if (time(NULL) - t > 1)
				return (0);
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

int		ft_choose_paths(t_infos *inf)
{
	int i;
	int r = 0;

	i = -1;
	if (inf->jpp++)
		ft_free_tab_int(inf->t_p_c, inf->nb_path_max);
	if (!(inf->t_p_c = (int**)ft_memalloc(sizeof(int*) * inf->nb_path_max)))
		return (-1);
	while (++i < ft_min_int(inf->nb_path_max, inf->t_p[0][0]))
	{
		if (!(inf->t_p_c[i] = (int*)ft_memalloc(sizeof(int) * (i + 1))))
		{
			ft_free_tab_int(inf->t_p_c, i);
			return (-1);
		}
		if (i == 0)
			inf->t_p_c[i][0] = 1;
		else if (i > 0 && (r = ft_choose_path_i(inf, inf->t_p_c[i], i + 1)) <= 0)
		{
			if (!r)
				return (i);
			inf->jpp = 0;
			ft_free_tab_int(inf->t_p_c, i + 1);
			return (0);
		}
	}
	return (i);
}
