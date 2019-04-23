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

int		ft_init_w(t_infos *inf, t_w *w)
{
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
