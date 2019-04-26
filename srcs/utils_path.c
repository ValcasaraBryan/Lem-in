/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:46:50 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/26 18:46:52 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_lst_tp(t_infos *infos)
{
	t_path	*tmp;

	if (!infos->t_p)
		return ;
	while (infos->t_p->prev)
		infos->t_p = infos->t_p->prev;
	while (infos->t_p)
	{
		tmp = infos->t_p;
		free(infos->t_p->tab);
		infos->t_p = infos->t_p->next;
		free(tmp);
	}
}

static t_path	*new_path(t_path *prev, t_path *next, int len, int *tab)
{
	t_path	*tmp;

	if (!(tmp = malloc(sizeof(t_path))))
		return (NULL);
	tmp->len = len;
	tmp->tab = tab;
	tmp->prev = prev;
	tmp->next = next;
	return (tmp);
}

t_path			*ft_init_lst_path(t_path *old, int len, int *tab)
{
	t_path	*tmp;
	t_path	*swap;

	if (old && len <= old->len)
	{
		tmp = new_path(NULL, old, len, tab);
		old->prev = tmp;
		return (tmp);
	}
	else if (old)
	{
		tmp = old;
		while (tmp->next && len >= tmp->next->len)
			tmp = tmp->next;
		swap = new_path(tmp, tmp->next, len, tab);
		if (tmp->next)
			tmp->next->prev = swap;
		tmp->next = swap;
		return (old);
	}
	else
		return (new_path(NULL, NULL, len, tab));
}
