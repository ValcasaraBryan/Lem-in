/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commandes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:55:37 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:55:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			check_commandes(t_infos *infos)
{
	int		res;
	int		res_2;
	int		i;

	if (!infos || !infos->data)
		return (0);
	res = 0;
	res_2 = 0;
	i = -1;
	while (infos->data[++i].name_box)
		if (infos->data[i].commands == 1)
			res++;
		else if (infos->data[i].commands == 2)
			res_2++;
	if (res == 1 && res_2 == 1)
		return (1);
	return (0);
}
