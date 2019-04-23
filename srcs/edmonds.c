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

int			ft_ed(t_infos *inf, int i, int *tmp)
{
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
