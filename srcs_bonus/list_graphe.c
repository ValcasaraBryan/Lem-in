/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_graphe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:45:39 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:45:40 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_graphe		*new_graphe(t_lem *lem, t_graphe *prev, int nb)
{
	t_graphe	*tmp;

	tmp = NULL;
	if (!lem)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_graphe))))
		return (NULL);
	tmp->lem = lem;
	tmp->nb_of_graphe = nb;
	tmp->next = NULL;
	tmp->prev = prev;
	return (tmp);
}

t_graphe		*add_graphe(t_graphe *old, t_lem *lem, int nb)
{
	t_graphe	*tmp;

	if (old)
	{
		tmp = old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_graphe(lem, tmp, nb);
		return (old);
	}
	else
		return (new_graphe(lem, NULL, nb));
}

t_lem			*new_lem(t_data *line, int nb, t_lem *prev, int color)
{
	t_lem		*tmp;

	tmp = NULL;
	if (!line)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_lem))))
		return (NULL);
	tmp->data = line;
	tmp->lem = nb;
	tmp->color_ants = color;
	tmp->next = NULL;
	tmp->prev = prev;
	return (tmp);
}

t_lem			*add_lem(t_lem *lem, t_data *line, int nb, int color)
{
	t_lem		*tmp;

	if (lem)
	{
		tmp = lem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lem(line, nb, tmp, color);
		return (lem);
	}
	else
		return (new_lem(line, nb, NULL, color));
}
