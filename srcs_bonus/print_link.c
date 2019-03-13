/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:52:59 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:53:01 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			check_next(data_t *p, t_graphe *graphe)
{
	int		i;

	if (!graphe)
		return (-1);
	while (graphe->lem)
	{
		i = -1;
		if (p->graphe->lem->data->commands == 0)
			while (++i < p->graphe->lem->data->nb_of_link)
				if (p->graphe->lem->data->pipe[i]->n_piece == graphe->lem->data->n_piece)
				{
					while (graphe->lem->prev)
						graphe->lem = graphe->lem->prev;
					return (i);
				}
		if (graphe->lem->next)
			graphe->lem = graphe->lem->next;
		else
			break ;
	}
	while (graphe->lem->prev)
		graphe->lem = graphe->lem->prev;
	return (-1);
}

void		print_no_start(data_t *env)
{
	t_pos	a;
	t_pos	b;
	int		i;

	i = -1;
	if (env->nb_graphe == -1)
		return ;
	while (1)
	{
		i = check_next(env, env->graphe->next);
		if (i >= 0)
		{
			a.x = env->grille_x[env->graphe->lem->data->pipe[i]->coor_x];
			a.y = env->grille_y[env->graphe->lem->data->pipe[i]->coor_y];
			b.x = env->grille_x[env->graphe->lem->data->coor_x];
			b.y = env->grille_y[env->graphe->lem->data->coor_y];
			draw_line(a, b, env, env->graphe->lem->color_ants);
		}
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	while (env->graphe->lem->prev)
		env->graphe->lem = env->graphe->lem->prev;
	while (env->graphe->prev)
	{
		if (env->graphe->nb_of_graphe == env->nb_graphe)
			break ;
		env->graphe = env->graphe->prev;
	}
}

int			check_start(data_t *p)
{
	int		i;

	i = -1;
	if (!p->graphe->lem)
		return (-1);
	if (p->graphe->lem->lem < p->n_lem)
		return (-1);
	p->n_lem++;
	while (++i < p->graphe->lem->data->nb_of_link)
		if (p->graphe->lem->data->pipe[i]->commands == 1)
			return (i);
	return (-1);
}

void		print_start(data_t *env)
{
	t_pos	a;
	t_pos	b;
	int		i;

	if (!env->graphe->next)
		return ;
	while (env->graphe->next)
	{
		if (env->graphe->nb_of_graphe - 1 == env->nb_graphe)
			break ;
		env->graphe = env->graphe->next;
	}
	while (1)
	{
		i = check_start(env);
		if (i >= 0)
		{
			a.x = env->grille_x[env->graphe->lem->data->pipe[i]->coor_x];
			a.y = env->grille_y[env->graphe->lem->data->pipe[i]->coor_y];
			b.x = env->grille_x[env->graphe->lem->data->coor_x];
			b.y = env->grille_y[env->graphe->lem->data->coor_y];
			draw_line(a, b, env, env->graphe->lem->color_ants);
		}
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	while (env->graphe->lem->prev)
		env->graphe->lem = env->graphe->lem->prev;
	while (env->graphe->prev)
	{
		if (env->graphe->nb_of_graphe == env->nb_graphe)
			break ;
		env->graphe = env->graphe->prev;
	}
}
