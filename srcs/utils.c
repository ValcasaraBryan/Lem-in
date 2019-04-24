/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:25:13 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:26:01 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int			ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_path		*new_path(t_path *prev, t_path *next, int len, int *tab)
{
	t_path	*tmp;

	if (!(tmp = malloc(sizeof(t_path))))
		return (NULL);
	tmp->len = len;
	tmp->tab = tab;
	tmp->prev = prev;
	tmp->next = next;
	return (tmp);
}

t_path		*ft_init_lst_path(t_path *old, int len, int *tab)
{
	t_path	*tmp;
	t_path	*swap;

	if (old && len <= old->len)
	{
		tmp = new_path(NULL, old, len, tab);
		old->prev = tmp;
		return (tmp);
	}
	else if (old)
	{
		tmp = old;
		while (tmp->next && len >= tmp->next->len)
			tmp = tmp->next;
		swap = new_path(tmp, tmp->next, len, tab);
		if (tmp->next)
			tmp->next->prev = swap;
		tmp->next = swap;
		return (old);
	}
	else
		return (new_path(NULL, NULL, len, tab));
}

int			ft_init_tab_path(t_infos *infos)
{
	// if (!(infos->t_p = (int **)malloc(sizeof(int*) * )))
		// return (0);
	// if (!(infos->t_p[0] = (int *)malloc(sizeof(int))))
	// {
		// free(infos->t_p);
		// return (0);
	// }
	infos->tp_capacity = 0;
	// infos->t_p[0][0] = 0;
	return (1);
}

int			*ft_alloc_tab_int(int n, int val_initial)
{
	int		*tab;
	int		i;

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

int			ft_length_path(int *tab, int n)
{
	int		i;

	i = 0;
	if (!tab || n <= 0)
		return (0);
	while (i < n && i >= 0 && tab[i] >= 0)
		i++;
	return (i);
}
