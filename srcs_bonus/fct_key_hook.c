/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:59:56 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:59:57 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		erase_all(data_t *p, int val)
{
	free(p->grille_x);
	free(p->grille_y);
	erase_graphe(p);
	erase_infos(p->infos);
	erase_data(p->infos);
	if (val == 1)
		exit(0);
	else
		return (0);
}

int		send_usage(void)
{
	printf("%s%s%s", "Usage : You need to put\n",
		"\t'N'\t--> next\n\t'SPACE'\t--> start\n", "\t'ESC'\t--> exit\n");
	return (0);
}

int		key_hook(int keycode, data_t *p)
{
	if (keycode == 53)
		return (erase_all(p, 1));
	else if (keycode == 45 && p->graphe->next)
	{
		p->nb_graphe++;
		while (p->graphe->lem->prev)
			p->graphe->lem = p->graphe->lem->prev;
		if (p->graphe->next && p->nb_graphe > 0)
			p->graphe = p->graphe->next;
		mlx_clear_window(p->mlx_ptr, p->mlx_win);
	}
	else if (keycode == 49)
	{
		p->nb_graphe = -1;
		while (p->graphe->lem->prev)
			p->graphe->lem = p->graphe->lem->prev;
		while (p->graphe->prev)
			p->graphe = p->graphe->prev;
		p->n_lem = 0;
		mlx_clear_window(p->mlx_ptr, p->mlx_win);
	}
	else if (keycode != 0)
		return (send_usage());
	return (fct_main(p));
}
