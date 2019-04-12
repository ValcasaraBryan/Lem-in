/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_edmonds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:25:01 by glebouch          #+#    #+#             */
/*   Updated: 2019/04/12 17:25:02 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	return (inf->data[r1].p_state[i]);
}

void	ft_put_pipes_to_zero(t_infos *inf, int r1, int r2)
{
	int i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
}

void	ft_put_pipe_to_one(t_infos *inf, int r1, int r2)
{
	int i;

	i = 0;
	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
}
