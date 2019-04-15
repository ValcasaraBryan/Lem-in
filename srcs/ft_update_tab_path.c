/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_tab_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:15 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/15 17:59:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_update_tab_path_2(t_infos *infos, int **tmp, int *tab, t_t *t)
{
	int k;

	k = -1;
	if (!(tmp[t->i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
		return (0);
	if (t->r == 1 && (t->i == t->n || ft_length_path(tab, infos->nb_of_box)
		< ft_length_path(infos->t_p[t->j], infos->nb_of_box)))
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
	free(tab);
	return (tmp);
}
