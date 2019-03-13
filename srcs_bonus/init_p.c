/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:38:41 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:38:42 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			val_max_coor(t_data *data, char c)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	while (data[i].name_box)
	{
		if (c == 'x')
			if (data[i].coor_x > val)
				val = data[i].coor_x;
		if (c == 'y')
			if (data[i].coor_y > val)
				val = data[i].coor_y;
		i++;
	}
	return (val);
}

data_t		init_p(t_infos *infos, t_graphe *graphe)
{
	data_t	p;

	p.mlx_ptr = mlx_init();
	p.infos = infos;
	p.graphe = graphe;
	p.index_of_box = 0;
	p.nb_graphe = -1;
	p.n_lem = 0;
	p.color = 5000000;
	p.color_start = 120 * 256 * 256;
	p.color_end = 60 * 120 * 120;
	p.color_box_used = 60 * 70 * 60;
	p.nb_of_box = infos->nb_of_box;
	p.maximum_x = val_max_coor(infos->data, 'x');
	p.maximum_y = val_max_coor(infos->data, 'y');
	p.maximum_x = (!(p.maximum_x % p.maximum_x)) ? p.maximum_x : p.maximum_x - 1;
	p.maximum_y = (!(p.maximum_y % p.maximum_y)) ? p.maximum_y : p.maximum_y - 1;
	p.medium = (p.maximum_x > p.maximum_y) ? p.maximum_x + 2 : p.maximum_y + 2;
	if (p.medium > 100)
	{
		perror("Coordinated Too High ");
		exit(0);
	}
	p.longueur_win = ((p.medium - 2) >= 25) ? 1024 : 512;
	p.largeur_win = ((p.medium - 2) >= 25) ? 1024 : 512;
	init_tab_x_y(&p);
	init_grille_x_y(&p);
	p.mlx_win = mlx_new_window(p.mlx_ptr, p.longueur_win, p.largeur_win, "mlx 42");
	return (p);
}
