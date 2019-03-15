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

int		ft_un_el_l_commence_par_tab_i(t_infos *inf, int tabi, int nbc)
{
	t_graph	*tmp;
	int		i;
	int		track;

	track = 0;
	i = 0;
	tmp = inf->l;
	while (tmp)
	{
		if (tmp->path[1] == tabi)
			return (1);
		if (tmp->path[1] != -1)
			track++;
		tmp = tmp->next;
	}
	if (!track)
		return(1);
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
	tab = NULL;
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
				return (0);
			if (r >= 0)
			{
				r = ft_olalala(in, start, r);
				if (r)
					return ((r < 0) ? -1 : 0);
			}
		}
		else
			ft_add_graph_end(in, &in->l, in->l->path,
				in->data[in->data[in->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (1);
}

int		ft_search_path1(t_infos *inf, int start, t_q *q)
{
	while (*(&inf->l))
	{
		while (ft_length_path(inf->l->path, inf->nb_of_box)
		== q->lp && q->lp <= inf->nb_of_box)
		{
			q->i = -1;
			while (++q->i < inf->data[inf->l->c_r].nb_of_link)
			{
				if (ft_check_precedents(inf, inf->l->path,
					inf->data[inf->data[inf->l->c_r].
						pipe[q->i]->n_piece].n_piece))
				{
					q->ret = ft_search_path2(inf, q->i, start);
					if (q->ret <= 0)
						return ((q->ret < 0) ? 0 : 1);
				}
			}
			ft_graph_del_start(&inf->l);
			if (!inf->l)
				return (1);
		}
		q->lp++;
	}
	return (1);
}

int		ft_search_path(t_infos *inf, int start)
{
	int *tmp;
	t_q q;

	q.i = 0;
	q.lp = 1;
	q.ret = 0;
	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (0);
	ft_add_graph_end(inf, &inf->l, tmp, start);
	free(tmp);
	if (!ft_search_path1(inf, start, &q))
		return (0);
	return (1);
}
