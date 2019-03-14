/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ants_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:35:49 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:35:54 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			fcnt_rand(int *color, int nb)
{
	int			i;

	i = -1;
	srand(time(NULL));
	while (++i < nb)
		color[i] = rand() % 16000000;
}

int				num_data(t_infos *infos, char *str)
{
	int			i;

	i = -1;
	while (infos->data[++i].name_box)
		if (ft_strcmp(infos->data[i].name_box, str) == 0)
			break ;
	return (i);
}

t_lem			*split_step(t_infos *infos, char **tab, int *color)
{
	t_lem		*lem;
	int			n_lem;
	char		**box;
	int			i;

	i = -1;
	lem = NULL;
	while (tab[++i])
	{
		if (!(box = ft_strsplit(tab[i], '-')))
			return (NULL);
		if (!box[0] || !box[1])
			return (NULL);
		n_lem = ft_atoi(box[0] + 1);
		lem = add_lem(lem, &infos->data[num_data(infos, box[1])],
			n_lem, color[n_lem - 1]);
		free_tab_str(&box);
	}
	return (lem);
}

t_graphe		*parsing_ants_file(t_file *file, t_infos *infos)
{
	t_graphe	*step;
	int			color[infos->nb_of_fourmis + 1];
	char		**tab;
	int			n_graphe;

	step = NULL;
	n_graphe = 0;
	fcnt_rand(color, infos->nb_of_fourmis);
	while (file)
	{
		if (file->line && file->line[0] == 'L')
		{
			if (!(tab = ft_strsplit(file->line, ' ')))
				return (NULL);
			step = add_graphe(step, split_step(infos, tab, color), n_graphe++);
			free_tab_str(&tab);
		}
		file = file->next;
	}
	return (step);
}
