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

int save_paths2(t_infos *inf, int i)
{
	inf->data[inf->l->c_r].weight = 0;
	if (ft_check_precedents(inf, inf->l->path,
			inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].n_piece)
		&& inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].weight > 0)
	{
		if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
			if (!(inf->t_p = ft_update_tab_path(inf, ft_updated_path(inf, inf->l->path,
				inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece))))
				return (0);
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
		if (!inf->l)
			return (1);
	}
	return (0);
}

int		*ft_switch_tabs(t_infos *inf, int *tab2)
{
//	ft_putendl("ici");
	int *tab;
	int i;

	i = 0;
	if (!(tab = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (NULL);
	while (tab2[i] >= 0 && i < inf->nb_of_box)
	{
//		ft_printf("i = %d, tab[i] = %d tab2[i] = %d\n",i, tab[i], tab2[i]);
		tab[i] = tab2[i];
		tab2[i] = -1;
//		ft_printf("i = %d, tab[i] = %d tab2[i] = %d\n",i, tab[i], tab2[i]);
		i++;
	}
//	ft_putendl("icil");
	return (tab);
}

int		ft_put_weights(t_infos *inf)
{
//	ft_putendl("ici");
	int j;
	int w = 1;
	int k = -1;
	int k2 = 0;
	int *tab;
	int *tab2;

	j = 0;
	//proteger//
	tab = ft_alloc_tab_int(inf->nb_of_box, -1);
	//proteger//
	tab2 = ft_alloc_tab_int(inf->nb_of_box, -1);
	while (inf->data[j].commands != 2)
		j++;
	inf->data[j].weight = w;
	while (++k < inf->data[j].nb_of_link)
		tab[k] = inf->data[j].pipe[k]->n_piece;
	while (tab[0] >= 0)
	{
		w++;
		k = -1;
		k2 = 0;
		while (tab[++k] > 0)
		{
			j = -1;
			while (++j < inf->data[tab[k]].nb_of_link)
				if (inf->data[inf->data[tab[k]].pipe[j]->n_piece].weight == 0)
				{
					inf->data[inf->data[tab[k]].pipe[j]->n_piece].weight = w;
					if (inf->data[inf->data[tab[k]].pipe[j]->n_piece].commands != 1)
					{
						tab2[k2] = inf->data[tab[k]].pipe[j]->n_piece;
						k2++;
					}
				}
		}
		free(tab);
		if (!(tab = ft_switch_tabs(inf, tab2)))
		{
			free(tab2);
			return (0);
		}
//		ft_printf("totttooooooooooooooooo i = %d, tab[i] = %d tab2[i] = %d\n", i, tab[0], tab2[0]);
	}
	free(tab);
	free(tab2);
	return (1);
}
/*
void	ft_put_tab_path(t_infos *inf)
{
	ft_putendl("tab_path :");
	int i = 0;
	int j = -1;

	while (++i < inf->t_p[0][0])
	{
		j = -1;
		while (inf->t_p[i][++j] >= 0)
			ft_printf("%04d ", inf->t_p[i][j]);
		ft_putendl("");
	}
}
*/