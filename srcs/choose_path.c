
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

void 	ft_choose_path_i(t_infos *infos, int n)
{
	int *tab_index;
	int i = 0;
	int j = 0;
	int k = 0;


	if (!(tab_index = (int *)malloc(sizeof(int) * (n + 1))))
		return ;
	tab_index[n] = -1;
	if (n == 1)
		tab_index[0] = 1;
	else
		while(i < n)
		{
			ft_compare(infos->tab_path[i])
		}
}


int ft_choose_path(t_infos *infos)
{
	int i;

	while (i <= nb_path_max)
		ft_choose_path_i(infos, i);
}