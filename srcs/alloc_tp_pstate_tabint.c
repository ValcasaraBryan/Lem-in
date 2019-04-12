/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tp_pstate_tabint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:25:49 by glebouch          #+#    #+#             */
/*   Updated: 2019/04/12 17:25:52 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_init_tab_path(t_infos *infos)
{
	if (!(infos->t_p = (int **)malloc(sizeof(int*))))
		return (0);
	if (!(infos->t_p[0] = (int *)malloc(sizeof(int))))
	{
		free(infos->t_p);
		return (0);
	}
	infos->t_p[0][0] = 0;
	return (1);
}

int	ft_alloue_p_states(t_infos *inf)
{
	int i;

	i = 0;
	while (i < inf->nb_of_box)
	{
		if (!(inf->data[i].p_state = ft_memalloc(sizeof(int)
			* inf->data[i].nb_of_link)))
		{
			while (--i >= 0)
				free(inf->data[i].p_state);
			return (0);
		}
		i++;
	}
	return (1);
}

int	*ft_alloc_tab_int(int n, int val_initial)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n)
	{
		tab[i] = val_initial;
		i++;
	}
	return (tab);
}
