/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monalloc.c                                         :+:      :+:    :+:   */
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
