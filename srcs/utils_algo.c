/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:25:13 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:01 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int			ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_init_tab_path(t_infos *infos)
{
	if (!(infos->t_p = (int **)malloc(sizeof(int*))))
		return (0);
	if (!(infos->t_p[0] = (int *)malloc(sizeof(int))))
	{
		free(infos->t_p);
		return (0);
	}
	infos->t_p[0][0] = 0;
	return (1);
}

int			ft_update_nb_path_max(t_infos *inf)
{
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	while (++i < inf->data[inf->ind_start].nb_of_link)
		if (inf->data[inf->ind_start].pipe[i]->W == 1)
			ret++;
	return (ret);
}

int			ft_alloue_p_states(t_infos *inf)
{
	int		i;

	i = 0;
	while (i < inf->nb_of_box)
	{
		if (!(inf->data[i].p_state = ft_memalloc(sizeof(int)
			* inf->data[i].nb_of_link)))
		{
			while (--i >= 0)
				free(inf->data[i].p_state);
			return (0);
		}
		i++;
	}
	return (1);
}

void		ft_free_utils_init_path(t_infos *inf)
{
	int i;

	i = 0;
	while (++i < inf->nb_of_box)
		free(inf->data[i].p_state);
	ft_free_tab_int(inf->tp_final, inf->tp_final_capacity);
	ft_free_tab_int(inf->t_p_c, inf->nb_group_path);
}

int			ft_find_paths(t_infos *infos)
{
	int		ret;

	ret = 0;
	if (!ft_put_weights(infos))
		return (0);
	if (!(infos->nb_path_max = ft_update_nb_path_max(infos)))
		return (0);
	ft_printf("nb_path_max = %d\n", infos->nb_path_max);
	if (!(ft_alloue_p_states(infos)))
		return (0);
	if (!(infos->t_p_c = (int**)ft_memalloc(sizeof(int*) * infos->nb_path_max)))
		return (0);
	while ((ret = ft_ed(infos)) > 0)
	{
		if (ret == 2)
			return (1);
		ft_put_weights(infos);
	}
	ft_free_utils_init_path(infos);
	return (0);
}

int			*ft_alloc_tab_int(int n, int val_initial)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n)
	{
		tab[i] = val_initial;
		i++;
	}
	return (tab);
}

int			ft_length_path(int *tab, int n)
{
	int		i;

	i = 0;
	if (!tab || n <= 0)
		return (0);
	while (i < n && i >= 0 && tab[i] >= 0)
		i++;
	return (i);
}
