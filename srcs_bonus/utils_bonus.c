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

int			check_end(data_t *p)
{
	int		i;

	if (!p->graphe->lem)
		return (-1);
	while (p->graphe->lem)
	{
		i = -1;
		if (p->graphe->lem->data->commands == 2)
			while (++i < p->graphe->lem->data->nb_of_link)
				if (p->graphe->lem->data->pipe[i]->commands == 1)
				{
					while (p->graphe->lem->prev)
						p->graphe->lem = p->graphe->lem->prev;
					return (i);
				}
		if (p->graphe->lem->next)
			p->graphe->lem = p->graphe->lem->next;
		else
			break ;
	}
	while (p->graphe->lem->prev)
		p->graphe->lem = p->graphe->lem->prev;
	return (-1);
}

void		print_start_to_end(data_t *p)
{
	int		i;

	if (p->graphe->next || p->nb_graphe >= 0)
		return ;
	while (1)
	{
		i = check_end(p);
		if (i >= 0)
			print(p, i);
		if (p->graphe->lem->next)
			p->graphe->lem = p->graphe->lem->next;
		else
			break ;
	}
	reset_graphe_lem(p);
}

void		ft_put_graphe(t_lem *lem, int val)
{
	if (val == -1)
		return ;
	while (lem)
	{
		ft_putstr_fd("L", 2);
		ft_putnbr_fd(lem->lem, 2);
		ft_putstr_fd("-", 2);
		ft_putstr_fd(lem->data->name_box, 2);
		ft_putstr_fd(" ", 2);
		lem = lem->next;
	}
	ft_putstr_fd("\n", 2);
}

int			fct_main(data_t *p)
{
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 0;
	p->longueur = p->longueur_win / (p->medium * 1.2);
	p->largeur = p->largeur_win / (p->medium * 1.2);
	ft_put_graphe(p->graphe->lem, p->nb_graphe);
	print_all_link(p);
	print_start(p);
	print_no_start(p);
	print_start_to_end(p);
	fct_put_pixel(p);
	p->index_of_box = 0;
	return (0);
}

int			norm_free_tab(char ***tab, int retourn)
{
	free_tab_str(tab);
	return (retourn);
}
