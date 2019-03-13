/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:40:27 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:40:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_infos		init_val_bonus(void)
{
	t_infos	infos;

	infos.file = NULL;
	infos.data = NULL;
	infos.nb_of_fourmis = 0;
	infos.nb_of_box = 0;
	infos.nb_of_pipe = 0;
	infos.nb_f_left = 0;
	infos.nb_path_max = 0;
	infos.t_p = NULL;
	infos.t_p_c = NULL;
	infos.first_ant = NULL;
	infos.l = NULL;
	infos.jpp = 0;
	return (infos);
}

int			parsing_ants(t_infos *infos, char **line)
{
	int		ret;

	if (*line)
		free_line(line);
	if (!(get_next_line(0, line)))
		return (0);
	if (!(ants_move((ft_strsplit(*line, ' ')))))
		return (1);
	if (!(infos->file = add_file(infos->file, *line)))
		return (0);
	while ((ret = get_next_line(0, line)) > 0)
	{
		if (!(ants_move((ft_strsplit(*line, ' ')))))
			return (0);
		if (!(infos->file = add_file(infos->file, *line)))
			return (0);
	}
	return ((ret == -1) ? 0 : 1);
}

t_infos		get_file_bonus(void)
{
	t_infos	infos;
	int		etapes;
	char	*line;
	int		ret;

	line = NULL;
	etapes = 0;
	infos = init_val_bonus();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(parsing_line(&infos, line, etapes)))
			if (!(parsing_ants(&infos, &line)))
			{
				free_line(&line);
				get_next_line(0, NULL);
				break ;
			}
		if (etapes == 0)
		{
			infos.nb_of_fourmis = ft_atoi(line);
			etapes++;
		}
		if (!(infos.file = add_file(infos.file, line)))
			return (infos);
	}
	return (infos);
}
