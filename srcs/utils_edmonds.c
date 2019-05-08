/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_edmonds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/15 17:59:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	return (inf->data[r1].p_state[i]);
}

void		ft_put_pipes_to_zero(t_infos *inf, int r1, int r2)
{
	int		i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
}

void		ft_put_pipe_to_one(t_infos *inf, int r1, int r2)
{
	int		i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
}

int			ft_is_room_on_a_path(t_infos *inf, int cr)
{
	int		i;
	int		prev;
	int		j;

	prev = -1;
	i = 0;
	while (i < inf->data[cr].nb_of_link && !inf->data[cr].p_state[i])
		i++;
	if (i < inf->data[cr].nb_of_link)
	{
		i = -1;
		while (++i < inf->data[cr].nb_of_link)
		{
			j = -1;
			prev = inf->data[cr].pipe[i]->NP;
			while (++j < inf->data[prev].nb_of_link)
			{
				if (inf->data[prev].pipe[j]->NP == cr
					&& inf->data[prev].p_state[j] == 1)
					return (prev);
			}
		}
	}
	return (-1);
}
