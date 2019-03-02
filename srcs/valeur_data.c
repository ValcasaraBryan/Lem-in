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

#include "lem-in.h"

int			nb_of_link(t_infos *infos, char *str)
{
	t_file	*head;
	char	**tmp;
	int		i;

	head = infos->file;
	tmp = NULL;
	i = 0;
	while (head)
	{
		if (!(tmp = ft_strsplit(head->line, '-')))
			return (0);
		if (!tmp[0] || !tmp[1] || (tmp[0] && *tmp[0] == 'L'))
			free_tab_str(&tmp);
		if (tmp && (ft_strcmp(str, tmp[0]) == 0 || ft_strcmp(str, tmp[1]) == 0))
			i++;
		free_tab_str(&tmp);
		head = head->next;
	}
	return (i);
}

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
	int		len;

	tmp = NULL;
	i = 0;
	len = 0;
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
	infos->data[i].nb_of_link = nb_of_link(infos, infos->data[i].name_box);
	infos->data[i].commands = commande;
	infos->data[i].coor_x = ft_atoi(tmp[1]);
	infos->data[i].coor_y = ft_atoi(tmp[2]);
	if (!(malloc_pipe(infos, i, len)))
		return (0);
	free_tab_str(&tmp);
	return (1);
}
