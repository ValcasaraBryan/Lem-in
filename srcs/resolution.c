/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:41:17 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/15 17:41:30 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
 ** t_p_t = tab_path_turn, t = infos
 */
int		ft_fill_tab_path_turn_i(t_infos *t, int n, int **t_p_t, int nb_turn_max)
{
	int i;
	int j;
	int to_add;

	i = -1;
	j = 0;
	to_add = 0;
	while (++i < nb_turn_max)
	{
		j = 0;
		while (j < n + 1)
		{
			if (ft_length_path(t->tab_path[t->t_p_c[n][j]], \
						t->nb_of_box) - 1 == i + 1)
				to_add++;
			j++;
		}
		t_p_t[n][i] = (i > 0) ? t_p_t[n][i - 1] + to_add : to_add;
	}
	return (1);
}

int		ft_next_room_is_free(t_infos *infos, int index_path, int index_room)
{
	if (infos->data[infos->tab_path[index_path][index_room]].commands == 2)
		return (2);
	if (infos->data[infos->tab_path[index_path][index_room]].full == 0)
		return (1);
	return (0);
}

int		ft_move_ants(t_infos *i)
{
	t_ants	*tmp;
	int		room_free;

	tmp = i->first_ant;
	room_free = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if ((room_free = ft_next_room_is_free(i, tmp->path_u, tmp->indx + 1)) > 0)
		{
			i->data[i->tab_path[tmp->path_u][tmp->indx]].full = 0;
			tmp->indx++;
			if (room_free != 2)
				i->data[i->tab_path[tmp->path_u][tmp->indx]].full = 1;
			ft_printf("L%d-%s", tmp->num_a, i->data[i->tab_path[tmp->path_u][tmp->indx]].name_box);
		}
		if (room_free == 2)
			tmp = ft_lstdel_num_ant(&i->first_ant, tmp->num_a);
		else
			tmp = tmp->next;
		if (tmp)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
/*
**	nb_gp = nombre de groupes qu'on a pu former de 0 a n chemins possibles
**	tgt = tableau qui contient le nb de fourmis arrivées en fonction du groupe de path et du tour
*/
int		ft_find_group_path_to_use(t_infos *infos, int **tgt, int nb_gp, int nb_turn_max)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
		if (!ft_lstadd_end(&i->first_ant, i->nb_of_fourmis - i->nb_f_left, \
			i->t_p_c[nb_ants_to_create - 1][j], 0))
			return (0);
		i->nb_f_left--;
	}
	return (1);
}

void	ft_print_tab_path_turn_i(int **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
/*
**	nb_gp = nombre de groupes qu'on a pu former de 0 a n chemins possibles
**	num_g = numero du groupe a utiliser 
**	tgt = tableau qui contient le nb de fourmis arrivées en fonction du groupe de path et du tour
*/
int		ft_resolve(t_infos *inf, int nb_gp)
{
	int **tgt;
	int nb_turn_max;
	int i;
	int num_g;

	nb_turn_max = ft_length_path(inf->tab_path[1], inf->nb_of_box) - 2 + inf->nb_of_fourmis;
	i = -1;
	inf->nb_f_left = inf->nb_of_fourmis - 1;
	if (!(tgt = (int **)malloc(sizeof(int*) * nb_gp)))
		return (0);
	while (++i < nb_gp)
		if (!(tgt[i] = (int*)malloc(sizeof(int) * nb_turn_max)))
		{
			ft_free_tab_int(tgt, i);
			return (0);
		}
	ft_new_lst(&inf->first_ant);
	i = -1;
	while (++i < nb_gp)
		ft_fill_tab_path_turn_i(inf, i, tgt, nb_turn_max);
	ft_print_tab_path_turn_i(tgt, nb_turn_max, nb_gp);
	//
	num_g = ft_find_group_path_to_use(inf, tgt, nb_gp, nb_turn_max);
	if (num_g < 0)
		return (-1);
	if (!ft_create_ants(inf, num_g + 1))
		return (-1);
	while (ft_move_ants(inf))
	{
		if (inf->nb_f_left >= 0)
		{
			num_g = ft_find_group_path_to_use(inf, tgt, nb_gp, nb_turn_max);
			if (num_g < 0)
				return (-1);
			if (!ft_create_ants(inf, num_g + 1))
				return (-1);
		}
	}
	ft_free_tab_int(tgt, nb_gp);
	return (1);
}
