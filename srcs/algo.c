/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:39:42 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/05 15:16:28 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_init_ind_start_end_and_npm(t_infos *inf)
{
	int i;

	i = -1;
	while (++i < inf->nb_of_box)
	{
		if (inf->data[i].commands == 1)
			inf->ind_start = i;
		if (inf->data[i].commands == 2)
			inf->ind_end = i;
	}
	i = -1;
	inf->nb_path_max = -1;
	while (++i < inf->nb_of_box)
	{
		if (inf->data[i].commands != 0)
		{
			if (inf->nb_path_max == -1)
				inf->nb_path_max = inf->data[i].nb_of_link;
			else
				inf->nb_path_max = ft_min_int(inf->nb_path_max,
						inf->data[i].nb_of_link);
		}
	}
	return (inf->nb_path_max);
}

int		ft_algo(t_infos *inf)
{
	if (!ft_init_ind_start_end_and_npm(inf))
	{
		erase_data(inf);
		return (0);
	}
	if (!ft_find_paths(inf))
	{
		erase_data(inf);
		return (0);
	}
	if (!ft_resolve(inf, inf->nb_group_path))
	{
		ft_free_all(inf);
		return (0);
	}
	ft_free_all(inf);
	return (1);
}
