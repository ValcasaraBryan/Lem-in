/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:00:40 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 16:00:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			fct_main(data_t *p)
{
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 0;
	p->longueur = p->longueur_win / (p->medium * 1.2);
	p->largeur = p->largeur_win / (p->medium * 1.2);
	print_all_link(p);
	print_start(p);
	print_no_start(p);
	fct_put_pixel(p);
	p->index_of_box = 0;
	return (0);
}

int			norm_free_tab(char ***tab, int retourn)
{
	free_tab_str(tab);
	return (retourn);
}
