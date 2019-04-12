/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:24:22 by glebouch          #+#    #+#             */
/*   Updated: 2019/04/12 17:24:24 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_find_path_fonctions(t_infos *inf)
{
	int i;

	i = -1;
	while (++i < inf->nb_of_box)
		free(inf->data[i].p_state);
	ft_free_tab_int(inf->tp_final, inf->tp_final_capacity);
	ft_free_tab_int(inf->t_p_c, inf->nb_group_path);
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

int		ft_find_paths(t_infos *infos)
{
	int ret;

	ret = 0;
	if (!ft_put_weights(infos))
		return (0);
	if (!(infos->nb_path_max = ft_update_nb_path_max(infos)))
		return (0);
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
	ft_free_find_path_fonctions(infos);
	return (0);
}
