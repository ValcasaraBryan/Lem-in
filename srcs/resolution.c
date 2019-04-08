/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:17 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:31:58 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** t_p_t = tab_path_turn, t = infos
*/

int		ft_fill_tab_path_turn_i(t_infos *t, int n, int **t_p_t, int nb_turn_max)
{
	int i;
	int j;
	int to_add;
	t_path_comp *tmp;

	i = -1;
	j = 0;
	to_add = 0;
	tmp = t->pc;
	while (tmp->npc < n + 1)
		tmp = tmp->next;
	while (++i < nb_turn_max)
	{
		j = 0;
		while (j < n + 1)
		{
			if (ft_length_path(tmp->tpc[j],
						t->nb_of_box) - 1 == i + 1)
				to_add++;
			j++;
		}
		t_p_t[n][i] = (i > 0) ? t_p_t[n][i - 1] + to_add : to_add;
	}
	return (1);
}

/*
**	nb_gp = nombre de groupes qu'on a pu former de 0 a n chemins possibles
**	tgt = tableau qui contient le nb de fourmis arrivées en fonction du
**			groupe de path et du tour
*/

int		ft_find_group(t_infos *infos, int **tgt, int nb_gp, int nb_turn_max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (nb_gp == 1)
	{
		ft_putendl("le pb");
		return (0);
	}
	while (i < nb_turn_max)
	{
		j = 0;
		while (j < nb_gp)
		{
			if (infos->nb_f_left + 1 <= tgt[j][i])
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_create_ants(t_infos *i, int nb_ants_to_create)
{
	int j;

	j = -1;
	while (++j < nb_ants_to_create)
	{
		printf("%d - %d\n", j, nb_ants_to_create);
		if (!ft_lstadd_end(&i->first_ant, i->nb_of_fourmis - i->nb_f_left,
					i->t_p_c[nb_ants_to_create - 1][j], 0))
			return (0);
		i->nb_f_left--;
	}
	return (1);
}

/*
**		t_p = tab_path, contient tous les paths
**				possibles par ordre de taille croissantes
**		nb_gp = nombre de groupes qu'on a pu former
**				de 0 a n chemins possibles
**		num_g = numero du groupe a utiliser
**		tgt = tab groupe/tour, tableau qui contient le nb de fourmis
**				arrivées en fonction du groupe de path et du tour
*/

int		ft_resolve2(t_infos *inf, t_r *res, int **tgt, int nb_gp)
{
	ft_putendl("LAAAAAAAAAAA");
	int i;

	i = -1;
	while (++i < nb_gp)
		ft_fill_tab_path_turn_i(inf, i, tgt, res->nb_turn_max);
	ft_putendl("LAAAAAAAAAAA2");
	res->num_g = ft_find_group(inf, tgt, nb_gp, res->nb_turn_max);
	ft_printf("\n\n\n\n\n\n\nnb de ch a empreinter = %d et nb_gp = %d \n\n\n\n\n\n", res->num_g, nb_gp);
	if (res->num_g < 0)
		return (-1);
	ft_putendl("LAAAAAAAAAAA3");
	if (!ft_create_ants(inf, res->num_g + 1))
		return (-1);
	ft_putendl("LAAAAAAAAAAA3");
	ft_put_list(inf->file);
	while (ft_move_ants(inf))
	{
		if (inf->nb_f_left >= 0)
		{
			res->num_g = ft_find_group(inf, tgt, \
					nb_gp, res->nb_turn_max);
			if (res->num_g < 0)
				return (-1);
			if (!ft_create_ants(inf, res->num_g + 1))
				return (-1);
		}
	}
	ft_free_tab_int(tgt, nb_gp);
	return (0);
}

int		ft_resolve(t_infos *inf, int nb_gp)
{
	int **tgt;
	int i;
	t_r res;

	res.nb_turn_max = ft_length_path(inf->t_p[1], inf->nb_of_box)
					- 2 + inf->nb_of_fourmis;
	i = -1;
	inf->nb_f_left = inf->nb_of_fourmis - 1;
	if (!(tgt = (int **)malloc(sizeof(int*) * nb_gp)))
		return (0);
	while (++i < nb_gp)
		if (!(tgt[i] = (int*)malloc(sizeof(int) * res.nb_turn_max)))
		{
			ft_free_tab_int(tgt, i);
			return (0);
		}
	if (ft_resolve2(inf, &res, tgt, nb_gp) < 0)
	{
		ft_free_tab_int(tgt, nb_gp);
		return (-1);
	}
	return (1);
}
