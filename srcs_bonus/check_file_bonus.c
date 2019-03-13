/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:39:56 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:39:58 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			check_file_bonus(t_infos *infos, int commande, int check_order)
{
	t_file	*head;

	head = infos->file;
	if (!(skip_line_fourmi(infos)))
		return (0);
	while (infos->file)
	{
		if (commantaire(infos) && skip_commentaire(infos, head))
			return (1);
		check_order = (ft_strcmp(infos->file->line, "##start") == 0
		|| ft_strcmp(infos->file->line, "##end") == 0) ? 0 : check_order;
		commande = init_command(infos, commande);
		if (!check_order && commande && infos->file->next)
			infos->file = infos->file->next;
		if (infos->file->line && infos->file->line[0] == '#'
			&& infos->file->line[1] == '#' && commande == 0)
			return (norm_check_file(infos, head, 0));
		if (commantaire(infos) && skip_commentaire(infos, head))
			return (0);
		if (infos->file->line && infos->file->line[0] == 'L')
			return (norm_check_file(infos, head, 1));
		if (!(check_order = step_check(infos, head, check_order, commande)))
			return (0);
		infos->file = infos->file->next;
	}
	return (norm_check_file(infos, head, 1));
}
