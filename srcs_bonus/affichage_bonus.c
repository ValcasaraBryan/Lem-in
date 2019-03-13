/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:47:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:47:09 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			print_all_link(data_t *env)
{
	t_pos		a;
	t_pos		b;
	int			i;
	int			j;

	i = -1;
	while (++i < env->infos->nb_of_box)
	{
		j = -1;
		while (++j < env->infos->data[i].nb_of_link)
		{
			a.x = env->grille_x[env->infos->data[i].pipe[j]->coor_x];
			a.y = env->grille_y[env->infos->data[i].pipe[j]->coor_y];
			b.x = env->grille_x[env->infos->data[i].coor_x];
			b.y = env->grille_y[env->infos->data[i].coor_y];
			draw_line(a, b, env, 0xfffffff);
		}
	}
}
