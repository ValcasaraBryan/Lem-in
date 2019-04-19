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

int			ft_fill_tab_path_turn_i(t_infos *t, int n, int **t_p_t,
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

int			ft_find_group(t_infos *infos, int **tgt, int nb_gp, int nb_turn_max)
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
			{
//				ft_printf("nb tour pour arriver avec %d chemins comp = %d\n", j + 1, i);
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_nb_ants_per_path_in_group_path(t_infos *inf, int *t_p, int nbr_p)
{
	int i = -1;
	int turn = 1;
	int nb_ants_arrived = 0;
	//tab_nb_ants to send en fonction de sa longueure

	if (!(inf->tfp = ft_alloc_tab_int(nbr_p, 0)))
		return (0);
//	ft_printf("nbr_p = %d nb_f = %d\n", nbr_p, inf->nb_of_fourmis);
	while (nb_ants_arrived < inf->nb_of_fourmis)
	{
		i = -1;
//		ft_printf("nb_ants_arr = %d i = %d\n", nb_ants_arrived, i);
		while (nb_ants_arrived < inf->nb_of_fourmis && ++i < nbr_p)
		{
			if (ft_length_path(inf->tp_final[t_p[i]], inf->nb_of_box) - 1 <= turn)
			{
				inf->tfp[i]++;
				nb_ants_arrived++;
			}
		}
		turn++;
	}
//	i = -1;
//	while (++i < nbr_p)
//		ft_printf("%d ", inf->tfp[i]);
//	ft_putendl("");
	return (1);
}

int			ft_create_ants(t_infos *i, int nbr_p)
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
//	ft_printf("nb_de f crees = %d\n", j);
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

int			ft_resolve2(t_infos *inf, t_r *res, int **tgt, int nb_gp)
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

void		ft_put_tab_path_final(t_infos *inf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < inf->tp_final_capacity)
	{
		j = -1;
		while (inf->tp_final[i][++j] > -1)
			ft_printf("%4d ", inf->tp_final[i][j] + 1);
		ft_putendl("");
	}
}
void ft_put_tab_pipes(t_infos *inf)
{
	int i = -1;
	int j;
	while (++i < inf->nb_of_box)
	{
		j = -1;
		while (++j < inf->data[i].nb_of_link)
			ft_printf("\tlien %d - %d vaut %d ", i + 1, inf->data[i].pipe[j]->NP + 1, inf->data[i].p_state[j]);
		ft_putendl("");
	}
}
int			ft_resolve(t_infos *inf, int nb_gp)
{
	int		**tgt;
	int		i;
	t_r		res;

	// ft_put_tab_path_final(inf);
	// ft_put_tab_pipes(inf);
	res.nb_turn_max = ft_length_path(inf->tp_final[0], inf->nb_of_box)
					- 2 + inf->nb_of_fourmis;
	i = -1;
	inf->nb_f_left = inf->nb_of_fourmis - 1;
	if (!(tgt = (int **)malloc(sizeof(int*) * nb_gp)))
		return (0);
	while (++i < nb_gp)
	{
		if (!(tgt[i] = (int*)malloc(sizeof(int) * res.nb_turn_max)))
		{
			ft_free_tab_int(tgt, i);
			return (0);
		}
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
