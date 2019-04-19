/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/15 17:59:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**ft_cp(t_infos *inf, int **tab)
{
	int		**tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(tmp = malloc(sizeof(int *) * tab[0][0])))
		return (NULL);
	while (++i < tab[0][0])
		if (!(tmp[i] = malloc(sizeof(int) * inf->nb_of_box)))
		{
			ft_free_tab_int(tmp, i - 1);
			return (NULL);
		}
	i = -1;
	while (++i < tab[0][0])
	{
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i][j] = tab[i + 1][j];
	}
	return (tmp);
}

int			ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	return (inf->data[r1].p_state[i]);
}

void		ft_put_pipes_to_zero(t_infos *inf, int r1, int r2)
{
	int		i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
}

void		ft_put_pipe_to_one(t_infos *inf, int r1, int r2)
{
	int		i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
}

int			**alloc_init_tmp(t_infos *inf, int **tmp, int size)
{
	if (!(tmp[size] = (int *)malloc(sizeof(int) * inf->nb_of_box)))
	{
		ft_free_tab_int(tmp, size);
		return (NULL);
	}
	return (tmp);
}

int			**ft_init_tmp(t_infos *inf, int **tmp, int n)
{
	int		j;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (!(tmp = alloc_init_tmp(inf, tmp, i)))
			return (NULL);
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i][j] = inf->tp_final[i][j];
	}
	i = -1;
	while (++i < inf->t_p[0][0])
	{
		if (!(tmp = alloc_init_tmp(inf, tmp, i + n)))
			return (NULL);
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i + n][j] = inf->t_p[i + 1][j];
	}
	return (tmp);
}

int			**ft_put_t_p_to_tpfinal(t_infos *inf, int i, int n)
{
	int		**tmp;

	inf->tp_final_capacity += inf->t_p[0][0];
	if (!(tmp = (int **)malloc(sizeof(int*) * (n + inf->t_p[0][0]))))
		return (NULL);
	if (!(tmp = ft_init_tmp(inf, tmp, n)))
		return (NULL);
	if (!(inf->t_p_c[inf->t_p[0][0] - 1] = (int*)malloc(sizeof(int)
		* inf->t_p[0][0])))
	{
		ft_free_tab_int(tmp, inf->tp_final_capacity);
		ft_free_tab_int(inf->t_p_c, inf->t_p[0][0] - 1);
		return (NULL);
	}
	while (++i < inf->t_p[0][0])
		inf->t_p_c[inf->t_p[0][0] - 1][i] = n + i;
	ft_free_tab_int(inf->t_p, inf->t_p[0][0] + 1);
	ft_free_tab_int(inf->tp_final, n);
	return (tmp);
}

void		ft_norm_save_path(t_infos *inf, int *pathtmp, int *cr)
{
	int		i;
	int		j;

	j = 1;
	while (inf->data[*cr].C != 2)
	{
		i = 0;
		while (i < inf->data[*cr].nb_of_link
			&& inf->data[*cr].p_state[i] != 1)
			i++;
		if (i < inf->data[*cr].nb_of_link)
		{
			pathtmp[j] = *cr;
			*cr = inf->data[*cr].pipe[i]->NP;
			j++;
		}
	}
	pathtmp[j] = inf->ind_end;
}

int			ft_save_path(t_infos *inf, int k, int nb_path_found, int cr)
{
	int		*pathtmp;

	if (!(ft_init_tab_path(inf)))
		return (0);
	while (k < inf->data[inf->ind_start].nb_of_link)
	{
		while (k < inf->data[inf->ind_start].nb_of_link
			&& inf->data[inf->ind_start].p_state[k] != 1)
			k++;
		if (k == inf->data[inf->ind_start].nb_of_link)
			return (nb_path_found);
		if (!(pathtmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
			return (-1);
		pathtmp[0] = inf->ind_start;
		cr = inf->data[inf->ind_start].pipe[k]->NP;
		ft_norm_save_path(inf, pathtmp, &cr);
		if (!(inf->t_p = ft_update_tab_path(inf, pathtmp)))
		{
			free(pathtmp);
			return (-1);
		}
		nb_path_found++;
		k++;
	}
	return (nb_path_found);
}

void		ft_save_p_states(t_infos *inf)
{
	int		i;

	i = 0;
	while (i < inf->nb_of_box && inf->l->path[i + 1] > -1)
	{
		if (ft_pipe_state(inf, inf->l->path[i + 1], inf->l->path[i]))
			ft_put_pipes_to_zero(inf, inf->l->path[i + 1], inf->l->path[i]);
		else
			ft_put_pipe_to_one(inf, inf->l->path[i], inf->l->path[i + 1]);
		i++;
	}
	ft_put_pipe_to_one(inf, inf->l->path[i], inf->ind_end);
}

int			ft_ed2(t_infos *inf, int i)
{
	if (ft_check_precedents(inf, inf->l->path,
				inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].n_piece)
			&& inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].W
			&& !inf->data[inf->l->c_r].p_state[i])
	{
		if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
		{
			ft_save_p_states(inf);
			inf->r = ft_save_path(inf, 0, 0, 0);
			inf->nb_group_path = ft_max_int(inf->r, inf->nb_group_path);
			inf->tp_final = ft_put_t_p_to_tpfinal(inf, -1,
				inf->tp_final_capacity);
			return (inf->r);
		}
		else
			ft_add_graph_end(inf, &inf->l, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (0);
}

int			ft_is_room_on_a_path(t_infos *inf, int cr)
{
	int		i;
	int		prev;
	int		j;

	prev = -1;
	i = 0;
	while (i < inf->data[cr].nb_of_link && !inf->data[cr].p_state[i])
		i++;
	if (i < inf->data[cr].nb_of_link)
	{
		i = -1;
		while (++i < inf->data[cr].nb_of_link)
		{
			j = -1;
			prev = inf->data[cr].pipe[i]->NP;
			while (++j < inf->data[prev].nb_of_link)
			{
				if (inf->data[prev].pipe[j]->NP == cr
					&& inf->data[prev].p_state[j] == 1)
					return (prev);
			}
		}
	}
	return (-1);
}

void		ft_ed2_special(t_infos *inf, int r_to_go)
{
	t_graph	*tmp;

	tmp = inf->l;
	if (ft_check_precedents(inf, inf->l->path, r_to_go)
			&& inf->data[r_to_go].W)
	{
		ft_add_graph_end(inf, &inf->l, inf->l->path, r_to_go);
		while (tmp->next)
			tmp = tmp->next;
		tmp->climbe = 0;
	}
}

int			ft_return_ed(int val, int nb_path_max)
{
	if (val < 0)
		return (-1);
	else if (val == nb_path_max)
		return (2);
	else if (val > 0)
		return (1);
	else
		return (0);
}

int			ft_ed(t_infos *inf)
{
	int		i;
	int		*tmp;

	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (-1);
	ft_add_graph_end(inf, &inf->l, tmp, inf->ind_start);
	free(tmp);
	while (*(&inf->l))
	{
		i = -1;
		if ((inf->r = ft_is_room_on_a_path(inf, inf->l->c_r)) >= 0
			&& inf->l->climbe)
			ft_ed2_special(inf, inf->r);
		else
		{
			inf->data[inf->l->c_r].weight = 0;
			while (++i < inf->data[inf->l->c_r].nb_of_link)
				if ((inf->r = ft_ed2(inf, i)))
				{
					ft_lstdel_all_graph(&inf->l);
					if (inf->r != 0)
						return (ft_return_ed(inf->r, inf->nb_path_max));
				}
		}
		ft_graph_del_start(&inf->l);
	}
	return (2);
}
