/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:09:30 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/18 13:09:33 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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

/*
**	t_i_try = tableau index des inf->pipe a essayer
**	tp_tmp = tab_path_n_piece, tableau qui contient
**				les num des pieces et forme le chemin
*/

void	ft_relay(t_s *s)
{
	s->t_i_try[s->i] = 0;
	s->tp_tmp[s->j - 1] = -1;
	s->j--;
	s->i = s->tp_tmp[s->j - 1];
}

void	ft_search_path2(t_infos *inf, t_s *s)
{
	while (s->t_i_try[s->i] < inf->data[s->i].nb_of_link && \
		inf->data[s->i].commands != 2)
	{
		if (ft_check_precedents(inf, s->tp_tmp, \
			inf->data[inf->data[s->i].pipe[s->t_i_try[s->i]]->n_piece].n_piece))
		{
			s->t_i_try[s->i]++;
			s->i = inf->data[\
				inf->data[s->i].pipe[s->t_i_try[s->i] - 1]->n_piece].n_piece;
			s->tp_tmp[s->j] = s->i;
			s->j++;
		}
		else
			s->t_i_try[s->i]++;
	}
	if (inf->data[s->i].commands == 2)
	{
		inf->t_p = ft_update_tab_path(inf, s->tp_tmp);
		s->j--;
		s->tp_tmp[s->j] = -1;
		s->i = s->tp_tmp[s->j - 1];
	}
	else if (s->t_i_try[s->i] >= inf->data[s->i].nb_of_link)
		ft_relay(s);
}

int		ft_search_path(t_infos *infos, int start)
{
	t_s s;

	s.i = start;
	s.j = 1;
	if (!(s.tp_tmp = ft_alloc_tab_int(infos->nb_of_box, -1)))
		return (0);
	if (!(s.t_i_try = ft_alloc_tab_int(infos->nb_of_box, 0)))
	{
		free(s.tp_tmp);
		return (0);
	}
	s.tp_tmp[0] = start;
	while (s.i != start || s.t_i_try[start] < infos->data[start].nb_of_link)
	{
		ft_search_path2(infos, &s);
	}
	free(s.tp_tmp);
	free(s.t_i_try);
	return (infos->t_p[0][0]);
}
