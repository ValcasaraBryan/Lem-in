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

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_init_tab_path(t_infos *infos)
{
	if (!(infos->t_p = (int **)malloc(sizeof(int*))))
		return (0);
	if (!(infos->t_p[0] = (int *)malloc(sizeof(int))))
	{
		free(infos->t_p);
		return (0);
	}
	infos->t_p[0][0] = 0;
	// infos->nb_path_max = -1;
	return (1);
}

int		ft_update_nb_path_max(t_infos *inf)
{
	int i;
	int ret;

	ret = 0;
	i = -1;
	while (++i < inf->data[inf->ind_start].nb_of_link)
		if (inf->data[inf->ind_start].pipe[i]->W == 1)
			ret++;
	return (ret);
}

int ft_alloue_p_states(t_infos *inf)
{
	int i = 0;

	while (i < inf->nb_of_box)
	{
		if (!(inf->data[i].p_state = ft_memalloc(sizeof(int) * inf->data[i].nb_of_link)))
		{
			while (--i >= 0)
				free(inf->data[i].p_state);
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_init_path(t_infos *infos)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < infos->nb_of_box)
	{
		if (infos->data[i].commands == 1)
			infos->ind_start = i;
		if (infos->data[i].commands == 2)
			infos->ind_end = i;
	}
	ft_putendl("ici0");
	if (!(ft_alloue_p_states(infos)))
		return (0);
	ft_putendl("ici1");
	if (!ft_put_weights(infos))
		return (0);
	ft_putendl("ici2");
	if (!(infos->nb_path_max = ft_update_nb_path_max(infos)))
		return (0);
	ft_putendl("ici3");
	while ((ret = ft_ed(infos)) > 0)
	{
		if (ret == 2)
			return (1);
		if (!ft_put_weights(infos))
			return (0);
	}
//	if (!ft_save_paths(infos))
//		return (0);
	return (0);
}

int		*ft_alloc_tab_int(int n, int val_initial)
{
	int *tab;
	int i;

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

int		ft_length_path(int *tab, int n)
{
	int i;

	i = 0;
	if (!tab || n <= 0)
		return (0);
	while (i < n && i >= 0 && tab[i] >= 0)
		i++;
	return (i);
}
