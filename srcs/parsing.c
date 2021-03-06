/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:19:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/23 17:19:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	free_tmp(char ***tmp, int retourn)
{
	free_tab_str(tmp);
	return (retourn);
}

int			parsing_line(t_infos *infos, char *line, int etapes)
{
	char	**tmp;

	tmp = NULL;
	if (!line)
		return (0);
	if (etapes == 0 && line[0] != '#')
		return (ft_str_is_digit(line) && !ft_str_max_int(line) ? 0 : 1);
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (1);
	if (line[0] == '#')
		return (1);
	if (!(tmp = ft_strsplit(line, ' ')))
		return (0);
	if (len_tab_str(tmp) == 3
	&& ft_str_is_digit(tmp[1])
	&& ft_str_is_digit(tmp[2]))
	{
		if (tmp[0][0] == 'L')
			return (free_tmp(&tmp, 0));
		infos->nb_of_box++;
		return (free_tmp(&tmp, 1));
	}
	return (parsing_pipe_line(infos, &tmp));
}

int			check_nb_char(char *str, int nb, char c)
{
	int		i;
	int		res;

	if (!str)
		return (0);
	i = -1;
	res = 0;
	while (str[++i])
		if (str[i] == c)
			res++;
	return (res == nb);
}

int			parsing_pipe_line(t_infos *infos, char ***tab)
{
	char	**tmp;
	char	**pipe;

	pipe = NULL;
	tmp = *tab;
	if (check_nb_char(tmp[0], 1, '-') && !tmp[1])
	{
		if (!(pipe = ft_strsplit(tmp[0], '-')))
		{
			free_tab_str(tab);
			return (0);
		}
		if (len_tab_str(pipe) != 3)
		{
			infos->nb_of_pipe++;
			free_tab_str(tab);
			free_tab_str(&pipe);
			return (1);
		}
		free_tab_str(&pipe);
	}
	free_tab_str(tab);
	return (0);
}

int			add_pipe(t_infos *infos, t_file *file)
{
	int		index_data;
	int		index_pipe;
	char	**tab;

	tab = NULL;
	while (file)
	{
		if (check_nb_char(file->line, 1, '-') && file->line[0] != '#')
		{
			if (file->line[0] == 'L')
				return (1);
			if (!(tab = ft_strsplit(file->line, '-')))
				return (0);
			if (len_tab_str(tab) != 2)
				return (free_tmp(&tab, 0));
			index_data = ft_find_str_in_tab(infos, tab[0]);
			index_pipe = ft_find_str_in_tab(infos, tab[1]);
			free_tab_str(&tab);
			if (!(add_link(infos, index_data, index_pipe)))
				return (0);
		}
		file = file->next;
	}
	return (1);
}
