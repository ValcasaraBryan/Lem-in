/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:44:13 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:44:16 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_infos	init_val(void)
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
	infos.tp_final = NULL;
	infos.tp_final_capacity = 0;
	infos.t_p_c = NULL;
	infos.first_ant = NULL;
	infos.l = NULL;
	infos.ind_start = -1;
	infos.ind_end = -1;
	infos.r = 0;
	infos.nb_group_path = 0;
	infos.tfp = NULL;
	infos.altab_adress = NULL;
	infos.alnb = 0;
	infos.alp2use = 0;
	return (infos);
}

static t_infos	returne(t_infos *infos, char **line)
{
	free_line(line);
	get_next_line(0, NULL);
	erase_infos(infos);
	return (*infos);
}

t_infos			get_file(void)
{
	t_infos	infos;
	char	*line;
	int		etapes;

	line = NULL;
	etapes = 0;
	infos = init_val();
	while (get_next_line(0, &line) > 0)
	{
		if (!(parsing_line(&infos, line, etapes)))
			return (returne(&infos, &line));
		if (etapes == 0 && line[0] != '#')
		{
			infos.nb_of_fourmis = ft_atoi(line);
			if (infos.nb_of_fourmis <= 0)
				return (returne(&infos, &line));
			etapes++;
		}
		infos.file = add_file(infos.file, line);
	}
	return (infos);
}
