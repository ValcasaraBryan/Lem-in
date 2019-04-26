/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valeur_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:54:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:54:24 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			norm_valeur_pipe(char ***tmp, int returne)
{
	free_tab_str(tmp);
	return (returne);
}

int			ft_find_str_in_tab(t_infos *infos, char *str)
{
	int		i;

	i = -1;
	while (infos->data[++i].name_box)
		if (!(ft_strcmp(infos->data[i].name_box, str)))
			break ;
	return (i);
}

int			add_link(t_infos *infos, int index_data, int index_pipe)
{
	int		i;

	if (index_data < 0 || index_pipe < 0)
		return (0);
	i = 0;
	while (infos->data[index_data].pipe[i])
		i++;
	infos->data[index_data].pipe[i] = &infos->data[index_pipe];
	i = 0;
	while (infos->data[index_pipe].pipe[i])
		i++;
	infos->data[index_pipe].pipe[i] = &infos->data[index_data];
	return (1);
}

static int	free_rest_line(t_infos *infos)
{
	t_file	*tmp;

	tmp = infos->file;
	if (tmp)
		while (tmp)
		{
			free(tmp->line);
			tmp->line = NULL;
			tmp = tmp->next;
		}
	return (1);
}

int			valeur_pipe(t_infos *infos)
{
	int		index_data;
	int		index_pipe;
	char	**tab;

	index_data = -1;
	index_pipe = -1;
	tab = NULL;
	if (!infos->file && !infos->data && !infos->data->pipe)
		return (0);
	if (!(tab = ft_strsplit(infos->file->line, '-')))
		return (0);
	if (len_tab_str(tab) != 2 || ft_strcmp(tab[0], tab[1]) == 0)
		return (norm_valeur_pipe(&tab, 0));
	index_data = ft_find_str_in_tab(infos, tab[0]);
	index_pipe = ft_find_str_in_tab(infos, tab[1]);
	free_tab_str(&tab);
	if (index_data < 0 || index_pipe < 0)
		return (0);
	if (!infos->data[index_data].name_box
		|| !infos->data[index_pipe].name_box)
		return (free_rest_line(infos));
	infos->data[index_pipe].nb_of_link++;
	infos->data[index_data].nb_of_link++;
	return (1);
}
