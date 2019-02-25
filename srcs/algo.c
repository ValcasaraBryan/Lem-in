/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:39:42 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/15 17:40:01 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_update_tab_path_2(t_infos *infos, int **tmp, int *tab, t_t *t)
{
	int k;

	k = -1;
	if (!(tmp[t->i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
		return (0);
	if (t->r == 1 && (t->i == t->n || ft_length_path(tab, infos->nb_of_box) < \
				ft_length_path(infos->t_p[t->j], infos->nb_of_box)))
	{
		while (++k < infos->nb_of_box)
			tmp[t->i][k] = tab[k];
		t->i++;
		if (t->i <= t->n)
			if (!(tmp[t->i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
				return (0);
		k = -1;
		t->r = 0;
	}
	if (t->i <= t->n)
		while (++k < infos->nb_of_box)
			tmp[t->i][k] = infos->t_p[t->j][k];
	t->j++;
	return (1);
}

int		**ft_update_tab_path(t_infos *infos, int *tab)
{
	ft_putendl("update_tab_path");
	t_t t;
	int **tmp;

	t.i = 0;
	t.j = 1;
	t.r = 1;
	t.n = infos->t_p[0][0] + 1;
	if (!(tmp = (int **)malloc(sizeof(int*) * (t.n + 2))))
		return (NULL);
	if (!(tmp[0] = (int *)malloc(sizeof(int) * 1)))
		return (NULL);
	while (++t.i <= t.n)
	{
		if (!(ft_update_tab_path_2(infos, tmp, tab, &t)))
		{
			ft_free_tab_int(tmp, t.i);
			return (NULL);
		}
	}
	tmp[0][0] = t.n;
	ft_free_tab_int(infos->t_p, t.n);
	return (tmp);
}

int		ft_algo_2(t_infos *infos)
{
	int nbr_group_path;

	nbr_group_path = 0;
	if (!infos->nb_path_max || !ft_init_path(infos))
	{
		ft_free_tab_int(infos->t_p, infos->t_p[0][0] + 1);
		return (0);
	}
	if (!(nbr_group_path = ft_choose_paths(infos)))
	{
		ft_free_tab_int(infos->t_p, infos->t_p[0][0] + 1);
		return (0);
	}
	if (ft_resolve(infos, nbr_group_path) <= 0)
	{
		ft_free_all(infos);
		return (0);
	}
	ft_free_all(infos);
	return (1);
}

int		ft_algo(t_infos *infos)
{
	ft_putendl("toto");
	int i;

	i = -1;
	if (!(ft_init_tab_path(infos)))
		return (0);
	while (++i < infos->nb_of_box)
	{
		if (infos->data[i].commands != 0)
		{
			if (infos->nb_path_max == -1)
				infos->nb_path_max = infos->data[i].nb_of_link;
			else
				infos->nb_path_max = \
			ft_min_int(infos->nb_path_max, infos->data[i].nb_of_link);
		}
 	}
	if (!(ft_algo_2(infos)))
		return (0);
	return (1);
}
