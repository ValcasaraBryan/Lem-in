/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weights.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:15 by glebouch          #+#    #+#             */
/*   Updated: 2019/04/01 11:00:34 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**		RAPPEL:
**		I = inf
**		NP = n_piece = numero piece
**		W = weight
**		C = commands
*/

/*
**		Si on arrive sur une salle valide:
**		Si on arrive a la salle end, on enregistre le path
**		Sinon on enregistre le path complété dans un nouvel element de liste
*/
/*
int		ft_save_paths2(t_infos *inf, int i)
{
	inf->data[inf->l->c_r].weight = 0;
	if (ft_check_precedents(inf, inf->l->path,
				inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].n_piece)
			&& inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].W)
	{
		if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
		{
			if (!(inf->t_p = ft_update_tab_path(inf,
							ft_updated_path(inf, inf->l->path,
								I->data[I->data[I->l->c_r].pipe[i]->NP].NP))))
				return (0);
		}
		else
			ft_add_graph_end(inf, &inf->l, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (1);
}

int		ft_save_paths(t_infos *inf)
{
	int i;
	int *tmp;

	i = 0;
	while (inf->data[i].commands != 1)
		i++;
	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (0);
	ft_add_graph_end(inf, &inf->l, tmp, i);
	free(tmp);
	while (*(&inf->l))
	{
		i = -1;
		while (++i < inf->data[inf->l->c_r].nb_of_link)
			if (!ft_save_paths2(inf, i))
				return (0);
		ft_graph_del_start(&inf->l);
		if (!inf->l || inf->t_p[0][0] >= 4 * inf->nb_path_max)
			return (1);
	}
	return (1);
}
*/

void	ft_switch_tabs(t_infos *inf, t_w *w)
{
	int i;

	i = 0;
	while ((w->tab2[i] >= 0 || w->tab[i] >= 0) && i < inf->nb_of_box)
	{
		w->tab[i] = w->tab2[i];
		w->tab2[i] = -1;
		i++;
	}
}

void	ft_put_weights2(t_infos *inf, t_w *w)
{
	int j;

	j = -1;
	w->k = -1;
	w->k2 = 0;
	while (w->tab[++w->k] >= 0)
	{
		j = -1;
		while (++j < inf->data[w->tab[w->k]].nb_of_link)
		{
			if (inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W == 0)
			{
				inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W = 1;
//				ft_printf("la salle %d mise a %d\n", inf->data[w->tab[w->k]].pipe[j]->n_piece, 1);
				if (inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].C != 1)
				{
					w->tab2[w->k2] = inf->data[w->tab[w->k]].pipe[j]->NP;
//					ft_printf("tab2[%d] = %d\n", w->k2, w->tab2[w->k2]);
					w->k2++;
				}
			}
		}
	}
	ft_switch_tabs(inf, w);
}

int		ft_put_weights(t_infos *inf)
{
	t_w w;
	int j;

	j = -1;
	if (!(ft_init_w(inf, &w)))
		return (0);
	while (++j < inf->nb_of_box)
		inf->data[j].W = 0;
	inf->data[inf->ind_end].weight = 1;
	while (++w.k < inf->data[inf->ind_end].nb_of_link)
	{
		w.tab[w.k] = inf->data[inf->ind_end].pipe[w.k]->n_piece;
		inf->data[inf->ind_end].pipe[w.k]->W = 1;
//		ft_printf("la salle %d mise a %d\n", inf->data[inf->ind_end].pipe[w.k]->n_piece, 1);
	}
	while (w.tab[0] >= 0)
		ft_put_weights2(inf, &w);
	free(w.tab);
	free(w.tab2);
	j = -1;
//	while (++j < inf->nb_of_box)
//		ft_printf("salle [%s]  w = %d \n", inf->data[j].name_box, inf->data[j].W);
	if (!inf->data[inf->ind_start].weight)
		return (0);
	return (1);
}
