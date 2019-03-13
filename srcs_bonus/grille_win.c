/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grille_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:49:59 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:50:00 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			init_grille_x_y(data_t *p)
{
	int		i;
	int		j;
	int		divi;
	int		res;

	i = -1;
	divi = (p->longueur_win - 2) / p->medium;
	divi = (!(divi % divi)) ? divi : divi + (10 - divi);
	while (++i < p->medium)
	{
		j = -1;
		res = divi;
		while (++j < i)
			res += divi;
		p->grille_x[i] = res;
		p->grille_y[i] = res;
	}
	return (1);
}

int			init_tab_x_y(data_t *p)
{
	int		i;

	i = -1;
	if (!(p->grille_x = (int *)malloc(sizeof(int) * p->medium)))
		return (0);
	if (!(p->grille_y = (int *)malloc(sizeof(int) * p->medium)))
		return (0);
	while (++i < p->medium)
	{
		p->grille_x[i] = 0;
		p->grille_y[i] = 0;
	}
	return (1);
}
