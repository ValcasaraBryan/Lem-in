/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_infos_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:56:20 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:56:22 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			logical_infos_pipe(t_data data)
{
	int		i;
	int		j;
	char	*tmp;

	if (!data.name_box)
		return (0);
	i = -1;
	while (data.pipe[++i])
	{
		j = i;
		tmp = data.pipe[i]->name_box;
		while (data.pipe[++j])
			if (!ft_strcmp(tmp, data.pipe[j]->name_box))
				return (0);
	}
	return (1);
}

int			logical_infos_box(t_infos *infos)
{
	char	*str;
	int		x;
	int		y;
	int		i;
	int		j;

	i = -1;
	if (!infos || !infos->data)
		return (0);
	while (infos->data[++i + 1].name_box)
	{
		j = i;
		str = infos->data[i].name_box;
		x = infos->data[i].coor_x;
		y = infos->data[i].coor_y;
		if (!(logical_infos_pipe(infos->data[i + 1])))
			return (0);
		while (infos->data[++j].name_box)
			if (!(ft_strcmp(str, infos->data[j].name_box))
			|| (x == infos->data[j].coor_x && y == infos->data[j].coor_y))
				return (0);
	}
	return (1);
}
