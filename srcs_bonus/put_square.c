/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:58:46 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:58:48 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int				check_box(data_t *p, int val)
{
	t_lem		*tmp;
	int			i;

	i = -1;
	tmp = p->graphe->lem;
	while (tmp)
	{
		if (tmp->data->n_piece == p->infos->data[val].n_piece)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				check_box_color(data_t *p, int val)
{
	t_lem		*tmp;
	int			i;

	i = -1;
	tmp = p->graphe->lem;
	if (p->nb_graphe < 0)
		return (0);
	while (tmp)
	{
		if (tmp->data->n_piece == p->infos->data[val].n_piece)
			return (tmp->color_ants);
		tmp = tmp->next;
	}
	return (0);
}

int				fct_put_pixel(data_t *p)
{
	int			i;
	int			j;

	while (p->graphe->lem)
	{
		if (!p->graphe->lem->next)
			break ;
		p->graphe->lem = p->graphe->lem->next;
	}
	while (p->graphe->lem->prev)
		p->graphe->lem = p->graphe->lem->prev;
	while (p->infos->data[p->index_of_box].name_box)
	{
		p->centre_y = p->grille_y[p->infos->data[p->index_of_box].coor_y] - (p->largeur / 2);
		p->centre_x = p->grille_x[p->infos->data[p->index_of_box].coor_x] - (p->longueur / 2);
		i = p->centre_x;
		while (i < p->centre_x + p->longueur)
		{
			j = p->centre_y;
			while (j < p->centre_y + p->largeur)
			{
				if (i != p->centre_x && i != p->centre_x + p->longueur - 1
					&& j != p->centre_y && j != p->centre_y + p->largeur - 1)
				{
					if (p->infos->data[p->index_of_box].commands == 1 || p->infos->data[p->index_of_box].commands == 2)
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, (p->infos->data[p->index_of_box].commands == 1) ? p->color_start : p->color_end);
					else if (check_box(p, p->index_of_box))
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, check_box_color(p, p->index_of_box));
					else
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_interieur);
				}
				if (i == p->centre_x || i == p->centre_x + p->longueur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_x);
				if (j == p->centre_y || j == p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_y);
				j++;
			}
			i++;
		}
		p->index_of_box++;
	}
	return (1);
}
