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
		{
			free_tab_str(&tab);
			return (0);
		}
		if (!(tmp = ft_strsplit(tab[i], '-')))
		{
			free_tab_str(&tab);
			return (0);
		}
		if (!tmp[0] || !tmp[1] || tmp[2])
		{
			free_tab_str(&tab);
			free_tab_str(&tmp);
			return (0);
		}
		free_tab_str(&tmp);
	}
	free_tab_str(&tab);
	return (i);
}
