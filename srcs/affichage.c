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

void        ft_put_list(t_file *file)
{
    while (file)
    {
        ft_putendl_fd(file->line, 1);
        file = file->next;
    }
}

void        ft_put_data(t_infos *infos)
{
    int     i;
    
    i = 0;
    if (infos)
    {
        if (infos->data)
        {
            while (i < infos->nb_of_box && infos->data[i].name_box)
            {
                ft_fprintf("nom        = %s\n", 2, infos->data[i].name_box);
                ft_fprintf("n_piece    = %d\n", 2, infos->data[i].n_piece);
                ft_fprintf("nb_of_link = %d\n", 2, infos->data[i].nb_of_link);
                ft_fprintf("commands   = %d\n", 2, infos->data[i].commands);
                ft_fprintf("x          = %d\n", 2, infos->data[i].coor_x);
                ft_fprintf("y          = %d\n\n", 2, infos->data[i].coor_y);
                i++;
            }
            ft_fprintf("\n", 2);
        }
    }
}
