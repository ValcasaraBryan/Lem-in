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

int			check_next(t_data_p *p, t_graphe *graphe)
{
	int		i;

	if (!graphe)
		return (-1);
	while (graphe->lem)
	{
		i = -1;
		if (p->graphe->lem->data->commands == 0
			&& p->graphe->lem->lem == graphe->lem->lem)
			while (++i < p->graphe->lem->data->nb_of_link)
				if (p->graphe->lem->data->pipe[i]->n_piece
					== graphe->lem->data->n_piece)
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

void		reset_graphe_lem(t_data_p *env)
{
	while (env->graphe->lem->prev)
		env->graphe->lem = env->graphe->lem->prev;
	while (env->graphe->prev)
	{
		if (env->graphe->nb_of_graphe == env->nb_graphe)
			break ;
		env->graphe = env->graphe->prev;
	}
}

void		print_no_start(t_data_p *env)
{
	int		i;

	i = -1;
	if (env->nb_graphe == -1)
		return ;
	while (1)
	{
		i = check_next(env, env->graphe->next);
		if (i >= 0)
			print(env, i);
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	reset_graphe_lem(env);
}

int			check_start(t_data_p *p)
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

void		print_start(t_data_p *env)
{
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
			print(env, i);
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	reset_graphe_lem(env);
}
