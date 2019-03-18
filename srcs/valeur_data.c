/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valeur_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:59:04 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:59:05 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			malloc_pipe(t_infos *infos, int i, int len)
{
	if (!(infos->data[i].pipe = (t_data **)malloc(sizeof(t_data *)
		* (infos->data[i].nb_of_link + 1))))
		return (0);
	while (len <= infos->data[i].nb_of_link)
		infos->data[i].pipe[len++] = NULL;
	return (1);
}

int			valeur_data(t_infos *infos, int commande)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (!infos->file && !infos->file->line && !infos->data)
		return (0);
	while (i <= infos->nb_of_box && infos->data[i].name_box)
		i++;
	if (!(tmp = ft_strsplit(infos->file->line, ' ')))
		return (0);
	if (!tmp[0] || !tmp[1] || !tmp[2])
		return (0);
	infos->data[i].name_box = ft_strdup(tmp[0]);
	infos->data[i].n_piece = i;
	infos->data[i].nb_of_link = 0;
	infos->data[i].commands = commande;
	infos->data[i].coor_x = ft_atoi(tmp[1]);
	infos->data[i].coor_y = ft_atoi(tmp[2]);
	free_tab_str(&tmp);
	return (1);
}
