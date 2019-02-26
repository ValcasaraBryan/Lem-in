/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:30 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/29 14:53:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_put_list(t_file *file)
{
	while (file)
	{
		ft_putendl_fd(file->line, 1);
		file = file->next;
	}
	ft_putchar('\n');
}

void		ft_put_data(t_infos *infos)
{
	int		i;

	i = 0;
	if (infos)
	{
		if (infos->data)
		{
			while (i < infos->nb_of_box && infos->data[i].name_box)
			{
				ft_printf("nom        = %s\n", infos->data[i].name_box);
				ft_printf("n_piece    = %d\n", infos->data[i].n_piece);
				ft_printf("nb_of_link = %d\n", infos->data[i].nb_of_link);
				ft_printf("commands   = %d\n", infos->data[i].commands);
				ft_printf("x          = %d\n", infos->data[i].coor_x);
				ft_printf("y          = %d\n\n", infos->data[i].coor_y);
				i++;
			}
			ft_printf("\n");
		}
	}
}
