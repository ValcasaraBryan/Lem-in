/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:45:54 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:45:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			init_data(t_infos *infos)
{
	int		i;

	if (infos->nb_of_box < 0)
		return (0);
	if (!(infos->data = malloc(sizeof(t_data) * (infos->nb_of_box + 1))))
		return (0);
	i = -1;
	while (++i <= infos->nb_of_box)
	{
		infos->data[i].name_box = NULL;
		infos->nb_path_max = 0;
		infos->data[i].n_piece = 0;
		infos->data[i].nb_of_link = 0;
		infos->data[i].commands = 0;
		infos->data[i].coor_x = 0;
		infos->data[i].coor_y = 0;
		infos->data[i].full = 0;
		infos->data[i].pipe = NULL;
		infos->data[i].weight = 0;
		////a free
		infos->data[i].p_state = NULL;
	}
	return (1);
}
