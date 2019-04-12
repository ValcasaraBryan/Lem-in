/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:08:53 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:27:54 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_tab_int(int **tab, int height)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab && i < height)
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_all(t_infos *infos)
{
	int i;

	i = -1;
	while (++i < infos->nb_of_box)
		free(infos->data[i].p_state);
	ft_lstdel_all(&infos->first_ant);
	ft_lstdel_all_graph(&infos->l);
	ft_free_tab_int(infos->tp_final, infos->tp_final_capacity);
	ft_free_tab_int(infos->t_p_c, infos->nb_path_max);
	erase_data(infos);
}

void	ft_lstdel_all(t_ants **fa)
{
	while (*fa)
		ft_lstdel_start(fa);
}
