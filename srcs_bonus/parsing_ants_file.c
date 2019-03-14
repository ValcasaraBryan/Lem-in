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

t_graphe		*parsing_ants_file(t_file *file, t_infos *infos)
{
	t_graphe	*step;
	t_lem		*lem;
	char		**tab;
	char		**box;
	int			n_lem;
	int			color[infos->nb_of_fourmis + 1];
	int			i;
	int			j;
	int			x;

	(void)infos;
	step = NULL;
	fcnt_rand(color, infos->nb_of_fourmis);
	x = 0;
	while (file)
	{
		if (file->line && file->line[0] == 'L')
		{
			if (!(tab = ft_strsplit(file->line, ' ')))
				return (NULL);
			i = -1;
			lem = NULL;
			while (tab[++i])
			{
				if (!(box = ft_strsplit(tab[i], '-')))
					return (NULL);
				if (!box[0] || !box[1])
					return (NULL);
				j = -1;
				while (infos->data[++j].name_box)
					if (ft_strcmp(infos->data[j].name_box, box[1]) == 0)
						break ;
				n_lem = ft_atoi(box[0] + 1);
				lem = add_lem(lem, &infos->data[j], n_lem, color[n_lem - 1]);
				free_tab_str(&box);
			}
			free_tab_str(&tab);
			step = add_graphe(step, lem, x++);
		}
		file = file->next;
	}
	return (step);
}
