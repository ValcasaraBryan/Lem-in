/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:44:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:44:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			free_tab_norm(char ***tab_1, char ***tab_2, int retourn)
{
	if (tab_1)
		free_tab_str(tab_1);
	if (tab_2)
		free_tab_str(tab_2);
	return (retourn);
}

int			ants_move(char **tab)
{
	int		i;
	char	**tmp;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
	{
		if (tab[i][0] != 'L')
			return (free_tab_norm(&tab, NULL, 0));
		if (!(tmp = ft_strsplit(tab[i], '-')))
			return (free_tab_norm(&tab, NULL, 0));
		if (!tmp[0] || !tmp[1] || tmp[2])
			return (free_tab_norm(&tab, &tmp, 0));
		free_tab_str(&tmp);
	}
	return (free_tab_norm(&tab, NULL, i));
}
