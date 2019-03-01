/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:09:30 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:28:07 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
   void ft_puttamere(t_infos *in)
   {
   int i = 0;

   while (i < in->nb_of_box)
   {
   int j = 0;
   while(j < in->data[i].nb_of_link)
   {
   ft_putchar('[');
   ft_putnbr(j);
   ft_putchar('-');
   ft_putnbr(in->data[i].pipe[j]->n_piece);
   ft_putchar(']');
   j++;
   }
   ft_putchar('\n');
   i++;
   }
   }*/

int		ft_check_precedents(t_infos *infos, int *tab_path_n_piece, int n)
{
	int i;

	i = 0;
	while (i < infos->nb_of_box)
	{
		if (tab_path_n_piece[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int		ft_un_el_l_commence_par_tab_i(t_infos *inf, int tabi, int nbc)
{
	t_graph	*tmp;
	int		i;

	i = 0;
	tmp = inf->l;
	while (tmp)
	{
		if (tmp->path[1] == tabi)
			return (1);
		tmp = tmp->next;
	}
	while (i < nbc)
	{
		if (inf->t_p[inf->t_p_c[nbc - 1][i]][1] == tabi)
			return (1);
		i++;
	}
	return (0);
}

int		ft_olalala(t_infos *inf, int start, int nbc)
{
	int i;
	int *tab;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * inf->data[start].nb_of_link)))
		return (-1);
	while (i < inf->data[start].nb_of_link)
	{
		tab[i] = inf->data[start].pipe[i]->n_piece;
		i++;
	}
	i = 0;
	while (i < inf->data[start].nb_of_link)
	{
		if (!ft_un_el_l_commence_par_tab_i(inf, tab[i], nbc))
			inf->nb_path_max--;
		i++;
	}
	free(tab);
	if (nbc == inf->nb_path_max)
		return (1);
	return (0);
}

int		ft_search_path2(t_infos *in, int i, int start)
{
	int r;

	r = 0;
	if (ft_check_precedents(in, in->l->path,
		in->data[in->data[in->l->c_r].pipe[i]->n_piece].n_piece))
	{
		if (in->data[in->data[in->l->c_r].pipe[i]->n_piece].commands == 2)
		{
			in->t_p = ft_update_tab_path(in, ft_updated_path(in, in->l->path,
				in->data[in->data[in->l->c_r].pipe[i]->n_piece].n_piece));
			if ((r = ft_choose_paths(in)) == in->nb_path_max)
			{
				ft_lstdel_all_graph(&in->l);
				return (0);
			}
			r = ft_olalala(in, start, r);
			if (r)
				return ((r < 0) ? -1 : 0);
		}
		else
			ft_add_graph_end(in, &in->l, in->l->path,
				in->data[in->data[in->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (1);
}

int		ft_search_path(t_infos *inf, int start)
{
	int lp;
	int i;
	int *tmp;
	int ret;

	lp = 1;
	tmp = ft_alloc_tab_int(inf->nb_of_box, -1);
	ft_add_graph_end(inf, &inf->l, tmp, start);
	free(tmp);
	while (*(&inf->l))
	{
		while (ft_length_path(inf->l->path, inf->nb_of_box) ==
		lp && lp <= inf->nb_of_box)
		{
			i = -1;
			while (++i < inf->data[inf->l->c_r].nb_of_link)
				if (ft_check_precedents(inf, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece))
				{
					ret = ft_search_path2(inf, i, start);
					if (ret <= 0)
						return ((ret < 0) ? 0 : 1);
				}
			ft_graph_del_start(&inf->l);
			if (!inf->l)
				return (1);
		}
		lp++;
	}
	return (1);
}
