/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:01:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 15:01:24 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		erase_infos(t_infos *infos)
{
	t_file	*head;

	if (infos->file)
		while (infos->file)
		{
			head = infos->file->next;
			free(infos->file->line);
			infos->file->line = NULL;
			free(infos->file);
			infos->file = NULL;
			infos->file = head;
		}
}
