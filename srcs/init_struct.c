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

void	ft_init_c(t_infos *inf, t_c *c, int n)
{
	c->k = -1;
	c->index_to_up = 0;
	c->nb_path_compatible = 1;
	c->lpm = ft_length_path(inf->t_p[n], inf->nb_of_box);
	c->t = time(NULL);
}

int		ft_init_w(t_infos *inf, t_w *w)
{
	w->j = 0;
	w->k = -1;
	w->k2 = 0;
	if (!(w->tab = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (0);
	if (!(w->tab2 = ft_alloc_tab_int(inf->nb_of_box, -1)))
	{
		free(w->tab);
		return (0);
	}
	return (1);
}
