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

#include "lem-in.h"

void	ft_free_tab_int(int **tab, int height)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab && i < height)
		free(tab[i++]);
	free(tab);
}

void	ft_free_all(t_infos *infos)
{
	ft_lstdel_all(&infos->first_ant);
	ft_lstdel_all_graph(&infos->l);
	ft_free_tab_int(infos->t_p_c, infos->nb_path_max);
	ft_free_tab_int(infos->t_p, infos->t_p[0][0] + 1);
	erase_data(infos);
}

void	ft_lstdel_all(t_ants **fa)
{
	while (*fa)
		ft_lstdel_start(fa);
}
