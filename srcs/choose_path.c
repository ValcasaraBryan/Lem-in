
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
			if (tab[i] == tab[j])
				return(0);
	}
	return(1);
}

int ft_path_independant(int **tab_final, int i, int **tab_path, int n)
{
	int j = 0;
	int k = 1;

	while (j <= i)
	{
		while (tab_path[n][k])
	}

}

void 	ft_choose_path(t_infos *infos)
{
	int **tab_final;
	int i = -1;
	int j = 1;
	int k = -1;


	if (!(tab_final = (int **)malloc(sizeof(int *) * infos->nb_path_max)))
		return ;
	while (++i < infos->nb_path_max)
		if (!(tab_final[i] = (int *)malloc(sizeof(int) * infos->nb_of_box)))
			return ;
	while (++k < infos->nb_of_box)
		tab_final[0][k] = infos->tab_path[0 + j][k];
	i = 0;
	while (++i < nb_path_max)
	{
		k = -1
		while (!ft_path_independant(tab_final, i, tab_path, i + j) && i + j <= tab_path[0][0])
			j++;
		if (ft_path_independant(tab_final, i, tab_path, i + j))
			while (++k < infos->nb_of_box)
				tab_final[i][k] = infos->tab_path[i + j][k];
	}
}