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

#include "lem-in.h"

int			check_pipe_double(t_infos *infos, char ***tab)
{
	char	**cmp;
	char	**tmp;
	t_file	*head;

	head = infos->file;
	tmp = *tab;
	if (!head)
		return (0);
	while (head->next)
	{
		if (head && head->line[0] == '#')
			while (head && head->line[0] == '#')
				head = head->next;
		if (head->next && head->next->line[0] != '#')
		{
			if (!(cmp = ft_strsplit(head->next->line, '-')))
				return (0);
			if (!cmp || !cmp[0] || !cmp[1] || !tmp[0] || !tmp[1])
			{
				free_tab_str(&cmp);
				return (0);
			}
			if (!(ft_strcmp(cmp[0], tmp[0])) && !(ft_strcmp(cmp[1], tmp[1])))
			{
				free_tab_str(&cmp);
				return (0);
			}
			free_tab_str(&cmp);
		}
		head = head->next;
	}
	return (1);
}

void		add_link(t_infos *infos, int index_data, int index_pipe)
{
	int		i;

	i = 0;
	while (infos->data[index_data].pipe[i])
		i++;
	infos->data[index_data].pipe[i] = &infos->data[index_pipe];
	i = 0;
	while (infos->data[index_pipe].pipe[i])
		i++;
	infos->data[index_pipe].pipe[i] = &infos->data[index_data];
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
	if (!tab || !tab[0] || !tab[1] || ft_strcmp(tab[0], tab[1]) == 0
	|| !(check_pipe_double(infos, &tab)))
	{
		free_tab_str(&tab);
		return (0);
	}
	while (infos->data[++index_data].name_box)
		if (!ft_strcmp(infos->data[index_data].name_box, tab[0]))
			break ;
	while (infos->data[++index_pipe].name_box)
		if (!ft_strcmp(infos->data[index_pipe].name_box, tab[1]))
			break ;
	free_tab_str(&tab);
	if (!infos->data[index_data].name_box || !infos->data[index_pipe].name_box)
		return (0);
	add_link(infos, index_data, index_pipe);
	return (1);
}
