/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:01:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 15:01:24 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		erase_infos(t_infos *infos)
{
	t_file	*head;

	if (infos->file)
		while (infos->file)
		{
			head = infos->file->next;
			free(infos->file->line);
			infos->file->line = NULL;
			free(infos->file);
			infos->file = NULL;
			infos->file = head;
		}
}

void		erase_data(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	if (infos->data)
	{
		while (i <= infos->nb_of_box)
		{
			j = 0;
			if (infos->data[i].name_box)
			{
				free(infos->data[i].name_box);
				infos->data[i].name_box = NULL;
			}
			if (infos->data[i].pipe)
			{
				free(infos->data[i].pipe);
				infos->data[i].pipe = NULL;
			}
			i++;
		}
		free(infos->data);
		infos->data = NULL;
	}
}
