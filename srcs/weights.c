/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weights.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:15 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:27:43 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	ft_switch_tabs(t_infos *inf, int **tab, int **tab2)
{
	return;
}*/

int ft_save_paths(t_infos *inf);

int	ft_put_weights(t_infos *inf)
{
//	ft_putendl("ici");
	int i = -1;
	int j = 0;
	int w = 1;
	int k = 0;
	int k2 = 0;
	int *tab;
	int *tab2;

	if(!(tab = (int*)malloc(sizeof(int) * inf->nb_of_box)))
		return (0);
	while (++i < inf->nb_of_box)
		tab[i] = -1;
	if(!(tab2 = (int*)malloc(sizeof(int) * inf->nb_of_box)))
		return (0);
	i = -1;
	while (++i < inf->nb_of_box)
		tab2[i] = -1;
	i = 0;
	while (inf->data[i].commands != 2)
		i++;
	inf->data[i].weight = w;
	while(k < inf->data[i].nb_of_link)
	{
		tab[k] = inf->data[i].pipe[k]->n_piece;
		k++;
	}
	while (tab[0] >= 0)
	{
		w++;
		k = 0;
		k2 = 0;
		while (tab[k] > 0)
		{
//			ft_printf("k = %d\n", k);
			j = 0;
			while (j < inf->data[tab[k]].nb_of_link)
			{
//				ft_printf("j = %d\n", j);
//				ft_printf("poid salle %d = %d", inf->data[tab[k]].pipe[j]->n_piece, inf->data[inf->data[tab[k]].pipe[j]->n_piece].weight);
				if (inf->data[inf->data[tab[k]].pipe[j]->n_piece].weight == 0)
				{
//					ft_printf("pro salle n'a pas de poids\n");
					inf->data[inf->data[tab[k]].pipe[j]->n_piece].weight = w;
					if (inf->data[inf->data[tab[k]].pipe[j]->n_piece].commands != 1)
					{
//						ft_printf("no _piece pro %d\n", inf->data[tab[k]].pipe[j]->n_piece);
						tab2[k2] = inf->data[tab[k]].pipe[j]->n_piece;
						k2++;
//						ft_printf("tab2[%d] = %d\n", k2 - 1, tab2[k2 - 1]);
					}
//					else
//						ft_putendl("                                ici");
				}
				j++;
			}
			k++;
		}
		i = 0;
		while ((tab2[i] >= 0 || tab[i] >= 0) && i < inf->nb_of_box)
		{
//			ft_printf("i = %d, tab[i] = %d tab2[i] = %d\n",i, tab[i], tab2[i]);
			tab[i] = tab2[i];
			tab2[i] = -1;
//			ft_printf("i = %d, tab[i] = %d tab2[i] = %d\n",i, tab[i], tab2[i]);
			i++;
		}
	}
//	int l = -1;
//	while (++l < inf->nb_of_box)
//		ft_printf("salle %d, poids: %d\n", l, inf->data[l].weight);
	free(tab);
	free(tab2);
	if (!ft_save_paths(inf))
		return(0);
	return(1);
}

void ft_put_tab_path(t_infos *inf)
{
	ft_putendl("tab_path :");
	int i = 0;
	int j = -1;

//	ft_putnbr(inf->t_p[1][0]);
//	ft_putnbr(inf->t_p[1][1]);
//	ft_putendl("tab_path :");

	while (++i < inf->t_p[0][0])
	{
		j = -1;
		while (inf->t_p[i][++j] >= 0)
			ft_printf("%04d ", inf->t_p[i][j]);
		ft_putendl("");
	}
//	ft_putendl("tab_path fin");
}

int ft_save_paths(t_infos *inf)
{
//	ft_putendl("save paths");
	int i = 0;
	int *tmp;
	
	while (inf->data[i].commands != 1)
		i++;
//	ft_putnbr(inf->data[i].weight);
//	ft_putnbr(inf->data[i].n_piece);
	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (0);
	ft_add_graph_end(inf, &inf->l, tmp, i);
	free(tmp);
	while (*(&inf->l))
	{
		i = -1;
		while (++i < inf->data[inf->l->c_r].nb_of_link)
		{
//			ft_putnbr(inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].weight);
			inf->data[inf->l->c_r].weight = 0;
			if (ft_check_precedents(inf, inf->l->path,
					inf->data[inf->data[inf->l->c_r].
						pipe[i]->n_piece].n_piece)
				&& inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].weight > 0)
			{
				if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
					inf->t_p = ft_update_tab_path(inf, ft_updated_path(inf, inf->l->path,
						inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece));
				else
					ft_add_graph_end(inf, &inf->l, inf->l->path,
						inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
			}
		}
//		ft_putnbr(inf->data[inf->l->c_r].nb_of_link);
		ft_graph_del_start(&inf->l);
		if (!inf->l)
		{
//			ft_put_tab_path(inf);
			return(1);
		}
	}
//	ft_put_tab_path(inf);
	return(0);
}




























