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

int		ft_init_w(t_infos *inf, t_w *w)
{
	w->k = -1;
	w->k2 = 0;
	if (!(w->tab = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (0);
	if (!(w->tab2 = ft_alloc_tab_int(inf->nb_of_box, -1)))
	{
		free(w->tab);
		return (0);
	}
	return (1);
}

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
				if (inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].C != 1)
				{
					w->tab2[w->k2] = inf->data[w->tab[w->k]].pipe[j]->NP;
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
	}
	while (w.tab[0] >= 0)
		ft_put_weights2(inf, &w);
	free(w.tab);
	free(w.tab2);
	j = -1;
	if (!inf->data[inf->ind_start].weight)
		return (0);
	return (1);
}
