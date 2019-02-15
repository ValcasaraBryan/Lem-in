/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:39:42 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/15 17:40:01 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_free_tab_int(int **tab, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(tab[i++]);
	free(tab);
}

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_put_tab_int(int *tab)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putnbr_fd(tab[i], 2);
		ft_putchar_fd(' ', 2);
	}
}

int		*ft_alloc_tab_int(int n, int val_initial)
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

int		ft_check_precedents(t_infos *infos, int *tab_path_n_piece, int n)
{
	int i;

	i = 0;
	while (i < infos->nb_of_box)
	{
		if (tab_path_n_piece[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int		ft_length_path(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n && tab[i] >= 0)
		i++;
	return (i);
}

int		ft_update_tab_path_2(t_infos *infos, int **tmp, int *tab, t_t *t)
{
	int k;

	k = -1;
	if (!(tmp[t->i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
		return (0);
	if (t->r == 1 && (t->i == t->n || ft_length_path(tab, infos->nb_of_box) < \
				ft_length_path(infos->tab_path[t->j], infos->nb_of_box)))
	{
		while (++k < infos->nb_of_box)
			tmp[t->i][k] = tab[k];
		t->i++;
		if (t->i <= t->n)
			if (!(tmp[t->i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
				return (0);
		k = -1;
		t->r = 0;
	}
	if (t->i <= t->n)
		while (++k < infos->nb_of_box)
			tmp[t->i][k] = infos->tab_path[t->j][k];
	t->j++;
	return (1);
}

int		**ft_update_tab_path(t_infos *infos, int *tab)
{
	t_t t;
	int **tmp;

	t.i = 0;
	t.j = 1;
	t.r = 1;
	t.n = infos->tab_path[0][0] + 1;
	if (!(tmp = (int **)malloc(sizeof(int*) * (t.n + 2))))
		return (NULL);
	if (!(tmp[0] = (int *)malloc(sizeof(int) * 1)))
		return (NULL);
	while (++t.i <= t.n)
	{
		if (!(ft_update_tab_path_2(infos, tmp, tab, &t)))
		{
			ft_free_tab_int(tmp, t.i);
			return (NULL);
		}
	}
	tmp[0][0] = t.n;
	ft_free_tab_int(infos->tab_path, t.n - 1);
	return (tmp);
}

/*int		**ft_update_tab_path(t_infos *infos, int *tab)
  {
  int n;
  int **tmp;
  int i = 0;
  int j = 1;
  int k;
  int r = 1;

  n = infos->tab_path[0][0] + 1;
  if (!(tmp = (int **)malloc(sizeof(int*) * (n + 2))))
  return (NULL);
  if (!(tmp[i] = (int *)malloc(sizeof(int) * 1)))
  return (NULL);
  while (++i <= n)
  {
  k = -1;
  if (!(tmp[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
  return (NULL);
  if (r == 1 && (i == n || ft_length_path(tab, infos->nb_of_box) < ft_length_path(infos->tab_path[j], infos->nb_of_box)))
  {
  while (++k < infos->nb_of_box)
  tmp[i][k] = tab[k];
  i++;
  if (i <= n)
  if (!(tmp[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
  return (NULL);
  k = -1;
  r = 0;
  }
  if (i <= n)
  while (++k < infos->nb_of_box)
  tmp[i][k] = infos->tab_path[j][k];
  j++;
  }
  tmp[0][0] = n;
  ft_free_tab_int(infos->tab_path, n - 1);
  return (tmp);
  }*/

int		ft_search_path(t_infos *infos, int start)
{
	int i;
	int j;
	int *tab_path_n_piece;
	int *tab_index_pipe_to_try;

	i = start;
	j = 1;
	if (!(tab_path_n_piece = ft_alloc_tab_int(infos->nb_of_box, -1)))
		return (0);
	if (!(tab_index_pipe_to_try = ft_alloc_tab_int(infos->nb_of_box, 0)))
	{
		free(tab_path_n_piece);
		return (0);
	}
	tab_path_n_piece[0] = start;
	while (i != start || tab_index_pipe_to_try[start] < infos->data[start].nb_of_link)
	{
		while (tab_index_pipe_to_try[i] < infos->data[i].nb_of_link && infos->data[i].commands != 2)
		{
			if (ft_check_precedents(infos, tab_path_n_piece, infos->data[infos->data[i].pipe[tab_index_pipe_to_try[i]]->n_piece].n_piece))
			{
				tab_index_pipe_to_try[i]++;
				i = infos->data[infos->data[i].pipe[tab_index_pipe_to_try[i] - 1]->n_piece].n_piece;
				tab_path_n_piece[j] = i;
				j++;
			}
			else
				tab_index_pipe_to_try[i]++;
		}
		if (infos->data[i].commands == 2)
		{
			infos->tab_path = ft_update_tab_path(infos, tab_path_n_piece);
			j--;
			tab_path_n_piece[j] = -1;
			i = tab_path_n_piece[j - 1];
		}
		else if (tab_index_pipe_to_try[i] >= infos->data[i].nb_of_link)
		{
			tab_index_pipe_to_try[i] = 0;
			tab_path_n_piece[j - 1] = -1;
			j--;
			i = tab_path_n_piece[j - 1];
		}
	}
	free(tab_path_n_piece);
	free(tab_index_pipe_to_try);
	return (infos->tab_path[0][0]);
}

int		ft_init_path(t_infos *infos)
{
	int i;

	i = 0;
	while (infos->data[i].commands != 1)
		i++;
	if (!ft_search_path(infos, i))
		return (0);
	return (1);
}

void	ft_free_all(t_infos *infos)
{
	ft_lstdel_all(&infos->first_ant);
	ft_free_tab_int(infos->t_p_c, \
			ft_min_int(infos->nb_path_max, infos->tab_path[0][0]));
	ft_free_tab_int(infos->tab_path, infos->tab_path[0][0] + 1);
}

int		ft_init_tab_path(t_infos *infos)
{
	if (!(infos->tab_path = (int **)malloc(sizeof(int*))) ||
			!(infos->tab_path[0] = (int *)malloc(sizeof(int))))
		return (0);
	infos->tab_path[0][0] = 0;
	infos->nb_path_max = -1;
	return (1);
}

int		ft_algo_2(t_infos *infos)
{
	int nbr_group_path;

	nbr_group_path = 0;
	if (!infos->nb_path_max || !ft_init_path(infos))
	{
		ft_free_tab_int(infos->tab_path, infos->tab_path[0][0] + 1);
		return (0);
	}
	if (!(nbr_group_path = ft_choose_paths(infos)))
	{
		ft_free_tab_int(infos->tab_path, infos->tab_path[0][0] + 1);
		return (0);
	}
	if (ft_resolve(infos, nbr_group_path) <= 0)
	{
		ft_free_all(infos);
		return (0);
	}
	ft_free_all(infos);
	return (1);
}

int		ft_algo(t_infos *infos)
{
	int i;

	i = -1;
	if (!(ft_init_tab_path(infos)))
		return (0);
	while (++i < infos->nb_of_box)
		if (infos->data[i].commands != 0)
			infos->nb_path_max = (infos->nb_path_max == -1) ? \
								 infos->data[i].nb_of_link : \
								 ft_min_int(infos->nb_path_max, infos->data[i].nb_of_link);
	if (!(ft_algo_2(infos)))
		return (0);
	return (1);
}
