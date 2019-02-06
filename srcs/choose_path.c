
#include "lem-in.h"

int ft_compare(t_infos *infos, int *tab1, int *tab2)
{
	int i = 0;
	int j;
	int l1;
	int l2;

	l1 = ft_length_path(tab1, infos->nb_of_box);
	l2 = ft_length_path(tab2, infos->nb_of_box);
	while (++i < l1 - 1)
	{
		j = 0;
		while (++j < l2 - 1)
			if (tab1[i] == tab2[j])
				return (0);
	}
	return (1);
}

int ft_compare_tab(t_infos *infos, int *tab, int n)
{
	int i = 0;
	int j;

	while (i < n)
	{
		j = i;
		while (++j < n)
			if (!(ft_compare(infos, infos->tab_path[tab[i]], infos->tab_path[tab[j]])))
				return(j);
		i++;
	}
	return (0);
}

int		ft_tmp_name(t_infos *infos, int *tab_indexs_path_compatibles, int index_to_up, int n)
{
	int tmp;
	int i = 0;

	while (index_to_up >= 0 && tab_indexs_path_compatibles[index_to_up] == infos->tab_path[0][0] - n + 1 + index_to_up)
		index_to_up--;
	if (index_to_up < 0)
		return (-1);
	tab_indexs_path_compatibles[index_to_up]++;
	tmp = tab_indexs_path_compatibles[index_to_up];
	while (++index_to_up < n)
	{
		tab_indexs_path_compatibles[index_to_up] = tmp + i;
		i++;
	}
	return (0);
}

int 	ft_choose_path_i(t_infos *infos, int *tab_indexs_path_compatibles, int n)
{
	int k = -1;
	int index_to_up = 0;
	int nb_path_compatible = 1;
	int length_path_max = ft_length_path(infos->tab_path[n], infos->nb_of_box);

	while (nb_path_compatible < n)
	{
		k = -1;
		while (++k < n && k + 1 < infos->tab_path[0][0])
			tab_indexs_path_compatibles[k] = k + 1;
		while (nb_path_compatible < n && ft_length_path(infos->tab_path[tab_indexs_path_compatibles[n - 1]], infos->nb_of_box) <= length_path_max)
		{
			if (!(index_to_up = ft_compare_tab(infos, tab_indexs_path_compatibles, n)))
			{
				return(1);
//				nb_path_compatible = n;
			}
			else if (ft_tmp_name(infos, tab_indexs_path_compatibles, index_to_up, n) == -1)
					return (-1);
				// while (index_to_up < n && tab_indexs_path_compatibles[index_to_up] < infos->tab_path[0])
				// {
					// tab_indexs_path_compatibles[index_to_up]++;
					// index_to_up++;
				// }
			// }
		}
		if (nb_path_compatible != n && tab_indexs_path_compatibles[0] < infos->tab_path[0][0] - (n - 1))
			length_path_max = ft_length_path(infos->tab_path[tab_indexs_path_compatibles[n - 1]], infos->nb_of_box);
	}
	return(0);
}

void ft_free_tab_path_compatible(int **tab, int i)
{
	int j = -1;
	while (++j <= i)
		free(tab[j]);
	free(tab);
}

int ft_choose_paths(t_infos *infos)
{
	int i = 0;
	int **tab_path_compatibles;

	tab_path_compatibles = (int**)malloc(sizeof(int*) * infos->nb_path_max);
	while (i <= infos->nb_path_max)
	{
		tab_path_compatibles[i] = (int*)malloc(sizeof(int) * (i + 1));
		if(ft_choose_path_i(infos, tab_path_compatibles[i], i + 1) < 0)
			ft_free_tab_path_compatible(tab_path_compatibles, i);
			return(-1);
		i++;
	}
	return(0);
}