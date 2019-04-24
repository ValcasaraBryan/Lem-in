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

int		ft_fill_tab_path_turn_i(t_infos *t, int n, int **t_p_t,
			int nb_turn_max)
{
	int		i;
	int		j;
	int		to_add;

	i = -1;
	j = 0;
	to_add = 0;
	while (++i < nb_turn_max)
	{
		j = 0;
		while (j < n + 1)
		{
			ft_printf("n = %d, j = %d, %-14p = %3d\n", n, j, t->t_p_c[n], t->t_p_c[n] ? t->t_p_c[n][j] : -2);
			if (ft_length_path(t->tp_final[t->t_p_c[n][j]],
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
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nb_gp == 1)
		return (0);
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

int		ft_nb_ants_per_path_in_group_path(t_infos *inf, int *t_p, int nbr_p)
{
	int i;
	int turn;
	int nb_ants_arrived;

	i = -1;
	turn = 1;
	nb_ants_arrived = 0;
	if (!(inf->tfp = ft_alloc_tab_int(nbr_p, 0)))
		return (0);
	while (nb_ants_arrived < inf->nb_of_fourmis)
	{
		i = -1;
		while (nb_ants_arrived < inf->nb_of_fourmis && ++i < nbr_p)
		{
			if (ft_length_path(inf->tp_final[t_p[i]], inf->nb_of_box) - 1
				<= turn)
			{
				inf->tfp[i]++;
				nb_ants_arrived++;
			}
		}
		turn++;
	}
	return (1);
}
