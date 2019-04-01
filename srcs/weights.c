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
int ft_check_weights(t_infos *inf)
{
	int i = -1;
	
	while (++i < ft_length_path(inf->l->path, inf->nb_of_box))
	{
		// ft_printf("%d ", inf->data[inf->t_p[inf->t_p[0][0]][i]].weight);
		if (inf->data[inf->l->path[i]].weight <= 0)
			return(0);
		// ft_printf("%d ", inf->data[inf->t_p[inf->t_p[0][0]][i]].weight);
	}
	return(1);
}

void ft_change_weights(t_infos *inf)
{
	int i = -1;
	
	while (++i < ft_length_path(inf->t_p[inf->t_p[0][0]], inf->nb_of_box))
	{
		ft_printf("%d ", inf->data[inf->t_p[inf->t_p[0][0]][i]].weight);
		inf->data[inf->t_p[inf->t_p[0][0]][i]].weight--;
		// ft_printf("%d ", inf->data[inf->t_p[inf->t_p[0][0]][i]].weight);
	}
	ft_printf("\n");
}

int		ft_save_paths2(t_infos *inf, int i)
{
	ft_putendl("save path2");
	// inf->data[inf->l->c_r].weight--;
	ft_printf("%d - %d\n", ft_check_precedents(inf, inf->l->path, inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece), ft_check_weights(inf));
	if (ft_check_precedents(inf, inf->l->path,
				inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].n_piece)
			&& ft_check_weights(inf))
	{
	ft_putendl("save path3");
		if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
		{
	ft_putendl("save path4");
			if (!(inf->t_p = ft_update_tab_path(inf,
							ft_updated_path(inf, inf->l->path,
								I->data[I->data[I->l->c_r].pipe[i]->NP].NP))))
				return (0);
		ft_putendl("touveeeeeeeeeeeeeee");
			ft_change_weights(inf);
		}
		else
			ft_add_graph_end(inf, &inf->l, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
		ft_putendl("trouvé une salle viable");
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
		ft_putendl("save path");
		i = -1;
		while (++i < inf->data[inf->l->c_r].nb_of_link)
		{
			ft_putendl("save path1");
			if (!ft_save_paths2(inf, i))
				return (0);
		}
		ft_graph_del_start(&inf->l);
//		ft_putnbr(inf->t_p[0][0]);
//		ft_putendl("");
		if (!inf->l || inf->t_p[0][0] >= 4 * inf->nb_path_max)
			return (1);
	}
	return (0);
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

int		ft_put_weights2(t_infos *inf, t_w *w)
{
	int j;

	j = -1;
	w->k = -1;
	w->k2 = 0;
	while (w->tab[++w->k] > 0)
	{
		j = -1;
		while (++j < inf->data[w->tab[w->k]].nb_of_link)
		{
			if (inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W == 0)
			{
				inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W =
				inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].nb_of_link;
				// ft_putnbr(inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W);
				// ft_putendl("");
				if (inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].C == 1)
				{
					inf->data[inf->data[w->tab[w->k]].pipe[j]->n_piece].W += 1;
					ft_printf("%d\n", inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].nb_of_link);
					ft_printf("DEBUT ====================================== %d\n", inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].W);
				}
				if (inf->data[inf->data[w->tab[w->k]].pipe[j]->NP].C != 1)
					w->tab2[w->k2++] =
						inf->data[w->tab[w->k]].pipe[j]->NP;
			}
		}
	}
	ft_switch_tabs(inf, w);
	return (1);
}

int		ft_put_weights(t_infos *inf)
{
	t_w w;
	int j;

	ft_printf("nb of box %d\n", inf->nb_of_box);
	j = 0;
	if (!(ft_init_w(inf, &w)))
		return (0);
	while (inf->data[j].commands != 2)
		j++;
	inf->data[j].weight = inf->nb_path_max;
	while (++w.k < inf->data[j].nb_of_link)
		w.tab[w.k] = inf->data[j].pipe[w.k]->n_piece;
	while (w.tab[0] >= 0)
	{
		if (!ft_put_weights2(inf, &w))
			return (0);
	}
	free(w.tab);
	free(w.tab2);
	j = 0;
	while (inf->data[j].commands != 1)
		j++;
	if (!inf->data[j].weight)
		return (0);
//	int i = 0;
//	j = -1;
//	while (inf->data[i].commands != 1)
//		i++;
//	ft_putnbr(inf->data[i].W);
//	while (++j < inf->data[i].nb_of_link)
//	{
//		ft_putnbr(inf->data[i].pipe[j]->W);
//		ft_putendl("");
//	}
	return (1);
}
