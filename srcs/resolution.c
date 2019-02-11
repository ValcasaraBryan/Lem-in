
#include "lem-in.h"

typedef struct s_list
{
	int num_ants;
	int path_used;
	int n_room;
	struct s_list *next;
}				t_list;

void ft_new_lst()
{
	t_list tmp;
	if (!(tmp = ft_memalloc(sizeof(t_list))))
		return (NULL);
	tmp.num_ants = n;
	tmp.path_used = path;
	tmp.n_room = index;
	tmp.next = NULL;
	return(tmp);
}

int ft_fill_tab_path_turn_i(infos_t *infos, int n, int **tab_paths_turn, int nb_turn_max)
{
	int i = 0;
	int j = 0;
	int to_add = 0;
	while (i < nb_turn_max)
	{
		j = 0;
		while (j < n + 1 && 
			ft_length_path(infos->tab_path[tab_path_compatible[n][j]], infos->nb_of_box) - 1 != i + 1)
		{
			to_add++;
			j++;
		}
		tab_paths_turn[n][i] = 0 + to_add; 
	}
}

int ft_suite(t_infos *infos)
{
	t_list liste;
	list = ft_new_lst(1, , );
	
}

int		resolve(t_infos *infos)
{
	int **tab_paths_turn;
	int nb_turn_max = ft_length_path(infos->tab_path[tab_path_compatible[0][0]], nb_of_box) - 2 + infos->nb_of_fourmis;
	int i = -1;

	tab_paths_turn = (int **)malloc(sizeof(int*) * nb_compatible);
	while (++i < nb_compatibles)
		tab_paths_turn[i] = (int*)malloc(sizeof(int) * nb_turn_max);
	i = -1
	while (++i < nb_compatibles)
		ft_fill_tab_path_turn_i(infos, i, tab_paths_turn, nb_turn_max);

	ft_suite(infos);
}


