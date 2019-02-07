
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
		{
			ft_putnbr_fd(infos->tab_path[tab[i]][0], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][1], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][2], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][3], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][4], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][5], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][6], 2);
			ft_putnbr_fd(infos->tab_path[tab[i]][7], 2);

			ft_putchar(' ');

			ft_putnbr_fd(infos->tab_path[tab[j]][0], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][1], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][2], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][3], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][4], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][5], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][6], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][7], 2);

			ft_putendl("");
			if (!(ft_compare(infos, infos->tab_path[tab[i]], infos->tab_path[tab[j]])))
				return(j);
		}
		i++;
	}
	return (0);
}

int		ft_tmp_name(t_infos *infos, int *tab_indexs_path_compatibles, int index_to_up, int n)
{
	ft_putendl("ft_tmp_name");
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
	ft_putendl("ft_choose_paths_i");
	int k = -1;
	int index_to_up = 0;
	int nb_path_compatible = 1;
	int length_path_max = ft_length_path(infos->tab_path[n], infos->nb_of_box);

	if (n == 1)
	{
		tab_indexs_path_compatibles = infos->tab_path[1];
		ft_putendl("on sort");
		return (1);
	}
	while (nb_path_compatible < n)
	{
		ft_putendl("dans le while");
		k = -1;
		while (++k < n && k + 1 < infos->tab_path[0][0])
			tab_indexs_path_compatibles[k] = k + 1;
		while (nb_path_compatible < n && ft_length_path(infos->tab_path[tab_indexs_path_compatibles[n - 1]], infos->nb_of_box) <= length_path_max)
		{
			ft_putendl("dans le while 2 ");
			if (!(index_to_up = ft_compare_tab(infos, tab_indexs_path_compatibles, n)))
			{
				ft_putendl("on sort car on a trouvé n chemins compatibles");
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

	ft_putendl("pas trouvé de path_i indep");
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
	ft_putendl("ft_choose_paths");
	int i = 0;
	int **tab_path_compatibles;

	tab_path_compatibles = (int**)malloc(sizeof(int*) * infos->nb_path_max);
	while (i < infos->nb_path_max)
	{
		ft_putnbr(infos->tab_path[0][0]);
		ft_putnbr(i);
		ft_putendl(" est la taille de tab");
		ft_putnbr(infos->nb_path_max);
		tab_path_compatibles[i] = (int*)malloc(sizeof(int) * (i + 1));
		if (ft_choose_path_i(infos, tab_path_compatibles[i], i + 1) < 0)
		{
			ft_free_tab_path_compatible(tab_path_compatibles, i);
			return(-1);
		}
		ft_putendl("ola");
		i++;
	}
	return(0);
}