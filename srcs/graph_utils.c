/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:25:31 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:28:18 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_init_monmalloc(t_infos *inf)
{
	int i;

	i = -1;
	if (!(inf->altab_adress = malloc(sizeof(int *) * PTOUSEMAX)))
		return (0);
	while (++i < PTOUSEMAX)
		if (!(inf->altab_adress[i] = ft_alloc_tab_int(BUFFSIZE, -1)))
		{
			ft_free_tab_int(inf->altab_adress, i);
			return (0);
		}
	inf->alp2use = 0;
	inf->alnb = 0;
	return (1);
}


int		*monalloc(t_infos *inf, int lenp)
{
	if (inf->alnb + lenp >= BUFFSIZE && inf->alp2use < PTOUSEMAX)
	{
		inf->alp2use++;
		inf->alnb = 0;
	}
	if (inf->alp2use >= PTOUSEMAX)
		return (NULL);
	inf->alnb += lenp;
	return (inf->altab_adress[inf->alp2use] + inf->alnb - lenp);
}

int		*ft_updated_path(t_infos *inf, int *old_p, int room, int lenp)
{
	int *new_p;
	int i;

	i = 0;
	if (!(new_p = monalloc(inf, lenp)))
		return (NULL);
	while (i < lenp - 1)
	{
		new_p[i] = old_p[i];
		i++;
	}
	new_p[i] = room;
	return (new_p);
}

int		ft_add_graph_end(t_infos *inf, t_graph **fg, int *old_p, int room)
{
	t_graph *new_p;

	if (!(new_p = malloc(sizeof(t_graph))))
		return (0);
	inf->count++;
	if (room == inf->ind_start)
		new_p->lenp = 1;
	else
		new_p->lenp = inf->l->lenp + 1;
	if (!(new_p->path = ft_updated_path(inf, old_p, room, new_p->lenp)))
	{
		free (new_p);
		return (0);
	}
	new_p->c_r = room;
	new_p->climbe = 1;
	new_p->next = NULL;
	while (*fg)
		fg = &((*fg)->next);
	*fg = new_p;
	return (1);
}

void	ft_new_graph(t_graph **fg)
{
	t_graph *new_g;

	if (!(new_g = ft_memalloc(sizeof(t_graph))))
		return ;
	fg = &new_g;
}

void	ft_graph_del_start(t_graph **fa)
{
	t_graph *tmp;

	tmp = *fa;
	*fa = tmp->next;
	free(tmp);
	tmp = NULL;
}

void	ft_lstdel_all_graph(t_graph **fa)
{
	while (*fa)
		ft_graph_del_start(fa);
}
