
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
//			ft_putnbr_fd(infos->tab_path[tab[i]][4], 2);
//			ft_putnbr_fd(infos->tab_path[tab[i]][5], 2);
//			ft_putnbr_fd(infos->tab_path[tab[i]][6], 2);
//			ft_putnbr_fd(infos->tab_path[tab[i]][7], 2);

			ft_putchar(' ');

			ft_putnbr_fd(infos->tab_path[tab[j]][0], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][1], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][2], 2);
			ft_putnbr_fd(infos->tab_path[tab[j]][3], 2);
//			ft_putnbr_fd(infos->tab_path[tab[j]][4], 2);
//			ft_putnbr_fd(infos->tab_path[tab[j]][5], 2);
//			ft_putnbr_fd(infos->tab_path[tab[j]][6], 2);
//			ft_putnbr_fd(infos->tab_path[tab[j]][7], 2);

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
//	ft_putendl("ft_tmp_name");
	int tmp;
	int i = 1;

//	ft_putnbr(index_to_up);
//	ft_putendl(" est l'index to up");
	while (index_to_up >= 0 && tab_indexs_path_compatibles[index_to_up] == infos->tab_path[0][0] - n + index_to_up)
		index_to_up--;
//	ft_putnbr(index_to_up);
//	ft_putendl(" est l'index to up apres verif");
	if (index_to_up < 0)
		return (-1);
	tab_indexs_path_compatibles[index_to_up]++;
//	ft_putnbr(tab_indexs_path_compatibles[index_to_up]);
//	ft_putendl(" = index du premier tab a tester");
	tmp = tab_indexs_path_compatibles[index_to_up];
	while (++index_to_up < n)
	{
		tab_indexs_path_compatibles[index_to_up] = tmp + i;
//	ft_putnbr(tab_indexs_path_compatibles[index_to_up]);
//	ft_putendl(" = index du deuxieme tab a tester");
		i++;
	}
	return (0);
}

int 	ft_choose_path_i(t_infos *infos, int *tab_indexs_path_compatibles, int n)
{
	ft_putendl("ft_choose_paths_i");
	int k;
	int index_to_up;
	int nb_path_compatible;
	int length_path_max;

	index_to_up = 0;
	nb_path_compatible = 1;
	length_path_max = ft_length_path(infos->tab_path[n], infos->nb_of_box);
	while (nb_path_compatible < n)
	{
		ft_putnbr(length_path_max);
		ft_putendl(" = length path_max");
		ft_putendl("dans le while");
		k = -1;
		while (++k < n && k < infos->tab_path[0][0])
			tab_indexs_path_compatibles[k] = k + 1;
		// ft_putendl("dans le while x ");
		// ft_putnbr(nb_path_compatible);
		// ft_putnbr(n);

		// ft_putnbr(tab_indexs_path_compatibles[0]);
		// ft_putnbr(tab_indexs_path_compatibles[1]);
		// ft_putnbr(tab_indexs_path_compatibles[2]);
		// ft_putnbr(tab_indexs_path_compatibles[3]);
		// ft_putnbr(n - 1);
		while (nb_path_compatible < n && ft_length_path(infos->tab_path[tab_indexs_path_compatibles[n - 1]], infos->nb_of_box) <= length_path_max)
		{
			ft_putendl("dans le while 2 ");
			if (!(index_to_up = ft_compare_tab(infos, tab_indexs_path_compatibles, n)))
			{
				ft_putendl("on sort car on a trouvé n chemins compatibles");
				return(1);
			}
			else if (ft_tmp_name(infos, tab_indexs_path_compatibles, index_to_up, n) == -1)
				return (-1);
		}
		ft_putendl("toto");
		if (nb_path_compatible != n && tab_indexs_path_compatibles[0] < infos->tab_path[0][0] - (n - 1))
			length_path_max = ft_length_path(infos->tab_path[tab_indexs_path_compatibles[n - 1]], infos->nb_of_box);
	}
	ft_putendl("pas trouvé de path_i indep");
	return(0);
}

int ft_choose_paths(t_infos *infos)
{
	ft_putendl("ft_choose_paths");
	int i = 0;

	infos->tab_paths_compatibles = (int**)malloc(sizeof(int*) * infos->nb_path_max);
	while (i < ft_min_int(infos->nb_path_max, infos->tab_path[0][0]))
	{
//		ft_putnbr(infos->tab_path[0][0]);
//		ft_putendl(" = nb_de chemins qui existent");
//		ft_putnbr(i+1);
//		ft_putendl(" = nb chemins comp a trouver");
//		ft_putnbr(infos->nb_path_max);
//		ft_putendl(" = nb_path_max");
		infos->tab_paths_compatibles[i] = (int*)malloc(sizeof(int) * (i + 1));
		if (i == 0)
		{
			infos->tab_paths_compatibles[i][0] = 1;
			ft_putendl("premier path");
		}
//		while (++j < i + 1)
//			tab_path_compatibles[i][j] = -1;
		else if (i > 0 && ft_choose_path_i(infos, infos->tab_paths_compatibles[i], i + 1) <= 0)
		{
			ft_free_tab_int(infos->tab_paths_compatibles, i + 1);
			return (-1);
		}
//		ft_putendl("ola");
		i++;
	}
	return(i);
}