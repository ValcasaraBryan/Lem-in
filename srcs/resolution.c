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

int		ft_create_ants(t_infos *i, int nbr_p)
{
	int		j;

	j = -1;
	while (++j < nbr_p && i->tfp[j] > 0)
	{
		if (!ft_lstadd_end(&i->first_ant, i->nb_of_fourmis - i->nb_f_left,
					i->t_p_c[nbr_p - 1][j], 0))
			return (0);
		i->tfp[j]--;
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
	int		i;

	i = -1;
	while (++i < nb_gp)
		ft_fill_tab_path_turn_i(inf, i, tgt, res->nb_turn_max);
	res->num_g = ft_find_group(inf, tgt, nb_gp, res->nb_turn_max);
	ft_free_tab_int(tgt, nb_gp);
	if (res->num_g < 0)
		return (-1);
	if (!ft_nb_ants_per_path_in_group_path(inf, inf->t_p_c[res->num_g],
		res->num_g + 1))
		return (-1);
	if (!ft_create_ants(inf, res->num_g + 1))
		return (0);
	ft_put_list(inf->file);
	while (ft_move_ants(inf))
	{
		if (inf->nb_f_left >= 0)
			if (!ft_create_ants(inf, res->num_g + 1))
				return (0);
	}
	return (1);
}

int		ft_resolve(t_infos *inf, int nb_gp)
{
	int		**tgt;
	int		i;
	t_r		res;

	res.nb_turn_max = ft_length_path(inf->tp_final[0], inf->nb_of_box)
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
	if ((inf->r = ft_resolve2(inf, &res, tgt, nb_gp)) <= 0)
	{
		if (inf->r == 0)
			free(inf->tfp);
		return (0);
	}
	free(inf->tfp);
	return (1);
}
