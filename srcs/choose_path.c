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
		{
			if (!(ft_compare(in, in->tab_path[tab[i]], in->tab_path[tab[j]])))
				return (j);
		}
	}
	return (0);
}

int		ft_up_index(t_infos *infos, int *t_p_c, int index_to_up, int n)
{
	int tmp;
	int i;

	i = 1;
	while (index_to_up >= 0 &&
			t_p_c[index_to_up] == infos->tab_path[0][0] - n + index_to_up)
		index_to_up--;
	if (index_to_up < 0)
		return (-1);
	t_p_c[index_to_up]++;
	tmp = t_p_c[index_to_up];
	while (++index_to_up < n)
	{
		t_p_c[index_to_up] = tmp + i;
		i++;
	}
	return (0);
}

int		ft_choose_path_i(t_infos *infos, int *t_p_c, int n)
{
	int k;
	int index_to_up;
	int nb_path_compatible;
	int l_path_max;

	index_to_up = 0;
	nb_path_compatible = 1;
	l_path_max = ft_length_path(infos->tab_path[n], infos->nb_of_box);
	while (nb_path_compatible < n)
	{
		k = -1;
		while (++k < n && k < infos->tab_path[0][0])
			t_p_c[k] = k + 1;
		while (nb_path_compatible < n &&
				ft_length_path(infos->tab_path[t_p_c[n - 1]], infos->nb_of_box) <= l_path_max)
		{
			if (!(index_to_up = ft_compare_tab(infos, t_p_c, n)))
				return (1);
			else if (ft_up_index(infos, t_p_c, index_to_up, n) == -1)
				return (-1);
		}
		if (nb_path_compatible != n && t_p_c[0] < infos->tab_path[0][0] - (n - 1))
			l_path_max = ft_length_path(infos->tab_path[t_p_c[n - 1]], infos->nb_of_box);
	}
	return (0);
}

int		ft_choose_paths(t_infos *infos)
{
	int i;

	i = 0;
	if (!(infos->tab_paths_compatibles = (int**)malloc(sizeof(int*) * infos->nb_path_max)))
		return (0);
	while (i < ft_min_int(infos->nb_path_max, infos->tab_path[0][0]))
	{
		if (!(infos->tab_paths_compatibles[i] = (int*)malloc(sizeof(int) * (i + 1))))
		{
			ft_free_tab_int(infos->tab_paths_compatibles, i);
			return (0);
		}
		if (i == 0)
		{
			infos->tab_paths_compatibles[i][0] = 1;
		}
		else if (i > 0 && ft_choose_path_i(infos, infos->tab_paths_compatibles[i], i + 1) < 0)
		{
			ft_free_tab_int(infos->tab_paths_compatibles, i);
			return (0);
		}
		i++;
	}
	return (i);
}
