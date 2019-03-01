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

int			init_command(t_infos *infos, int commande)
{
	commande = (ft_strcmp(infos->file->line, "##start")) == 0 ? 1 : 0;
	commande = (ft_strcmp(infos->file->line, "##end")) == 0 ? 2 : commande;
	return (commande);
}

int			norm_check_file(t_infos *infos, t_file *head, int returne)
{
	infos->file = head;
	return (returne);
}
