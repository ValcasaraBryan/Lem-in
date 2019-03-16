/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:53:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 18:53:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			erase_graphe(t_data_p *p)
{
	t_graphe	*head_graphe;
	t_lem		*head_lem;

	while (p->graphe)
	{
		head_graphe = p->graphe->next;
		while (p->graphe->lem)
		{
			head_lem = p->graphe->lem->next;
			free(p->graphe->lem);
			p->graphe->lem = NULL;
			p->graphe->lem = head_lem;
		}
		free(p->graphe);
		p->graphe = NULL;
		p->graphe = head_graphe;
	}
}
