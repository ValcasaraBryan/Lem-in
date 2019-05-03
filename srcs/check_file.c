/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:49:19 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/03 18:29:23 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			skip_commentaire(t_infos *infos, t_file *head)
{
	if (!infos->file->next)
		return (norm_check_file(infos, head, commantaire(infos) ? 1 : 0));
	while (infos->file->next && infos->file->line
			&& ((infos->file->line[0] == '#' && infos->file->line[1] != '#')
				|| (infos->file->line[0] == '#' && infos->file->line[1] == '#'
					&& ft_strcmp(infos->file->line, "##start") != 0
					&& ft_strcmp(infos->file->line, "##end") != 0)))
		infos->file = infos->file->next;
	return (0);
}

int			init_check_order(t_infos *infos, int check_order)
{
	check_order = (!check_order && check_nb_char(infos->file->line, 2, ' '))
		? 1 : check_order;
	check_order = (check_order == 1 && check_nb_char(infos->file->line, 1, '-'))
		? 2 : check_order;
	check_order = (check_order != 1 && check_order != 2) ? -1 : check_order;
	return (check_order);
}

int			step_check(t_infos *infos, t_file *head,
		int check_order, int commande)
{
	if ((check_order = init_check_order(infos, check_order)) == -1)
		return (norm_check_file(infos, head, 0));
	if (check_order == 1)
		return (valeur_data(infos, commande) ? 1 : 0);
	if (check_order == 2)
	{
		if (check_nb_char(infos->file->line, 2, ' '))
			return (norm_check_file(infos, head, 0));
		if (!(valeur_pipe(infos)))
			return (norm_check_file(infos, head, 0));
		return (2);
	}
	return (norm_check_file(infos, head, 0));
}

int			check_file(t_infos *inf, int commande, int c)
{
	t_file	*h;

	h = I->file;
	if (!(skip_line_fourmi(I)))
		return (0);
	while (I->file)
	{
		if (commantaire(I) && skip_commentaire(I, h))
			return (!skip_commentaire(I, h) ? norm_check_file(I, h, 1) : 0);
		c = (I->file->line
				&& ((ft_strcmp(I->file->line, "##start") == 0
						|| ft_strcmp(I->file->line, "##end") == 0))) ? 0 : c;
		commande = init_command(I, commande);
		if (!c && commande && I->file->next)
			I->file = I->file->next;
		if (commantaire(I) && skip_commentaire(I, h))
			return (!skip_commentaire(I, h) ? norm_check_file(I, h, 1) : 0);
		if (!(c = step_check(I, h, c, commande)))
			return (0);
		I->file = I->file->next;
	}
	return (norm_check_file(I, h, 1));
}
