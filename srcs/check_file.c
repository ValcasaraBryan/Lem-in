/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:49:19 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:49:21 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			retour_check_file(t_infos *infos, t_file *head, int retour)
{
	if (retour == 0)
		perror("ERROR ");
	infos->file = head;
	return (retour);
}

int			skip_commentaire(t_infos *infos, t_file *head)
{
	if (!infos->file->next)
		return (retour_check_file(infos, head, 1));
	while (infos->file->next && infos->file->line[0] == '#'
			&& infos->file->line[1] != '#')
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
		return (retour_check_file(infos, head, 0));
	if (check_order == 1)
		return (valeur_data(infos, commande) ? 1 : 0);
	if (check_order == 2)
	{
		if (check_nb_char(infos->file->line, 2, ' '))
			return (retour_check_file(infos, head, 0));
		if (!(valeur_pipe(infos)))
			return (norm_check_file(infos, head, 0));
		return (2);
	}
	return (norm_check_file(infos, head, 0));
}

int			check_file(t_infos *infos, int commande, int check_order)
{
	t_file	*head;

	head = infos->file;
	if (!(skip_line_fourmi(infos)))
		return (0);
	while (infos->file)
	{
		printf("%s\n", infos->file->line);
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
		if (!(check_order = step_check(infos, head, check_order, commande)))
			return (0);
		infos->file = infos->file->next;
	}
	return (retour_check_file(infos, head, 1));
}
