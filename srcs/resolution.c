
#include "lem-in.h"

typedef struct	s_list
{
	t_ants *first_ant;
}				t_list;	

typedef struct s_ants
{
	int num_ants;
	int path_used;
	int n_room;
	struct s_list *next;
}				t_ants;

int ft_lstdel_num_ant(t_list *start, int ant_to_del)
{
	t_ants *tmp;
	t_ants *prev;

	tmp = start->first_ant;
	prev = start->first_ant;
	while (tmp->num_ant != ant_to_del)
	{
		tmp = tmp->next;
		if (tmp->num_ant != ant_to_del)
			prev = prev->next;
	}
	prev->next = tmp->next;
	free(tmp);
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

int ft_suite(t_infos *infos, int num_group_path_to_use)
{
	t_list start;
	start->first_ant = ft_new_lst(void);
	ft_lstadd_end(start, num_ant, path, n_room);


	return(1);
}

int ft_find_group_path_to_use(t_infos *infos, int **tab_paths_turn, int nbr_group_paths, int nb_turn_max)
{
	int i = 0;
	int j = 0;

	while (i < nb_turn_max)
	{
		j = 0;
		while (j < nbr_group_paths)
		{
			if (infos->nb_of_fourmis <= tab_paths_turn[j][i])
			{
				infos->nb_of_fourmis -= j + 1;
				return(j);
			}
			j++;
		}
		i++;
	}
	return(-1);
}

int ft_create_ants(t_infos *infos, t_list *start, nb_ants_to_create)
{
	int i = 0;

	while (i < nb_ants_to_create)
	{
		ft_lstadd_end(start, infos->num_of_fourmis, tab_path_compatible[nb_ants_to_create - 1][i], -1)

	}
}

int		resolve(t_infos *infos)
{
	int **tab_paths_turn;
	int nb_turn_max = ft_length_path(infos->tab_path[tab_path_compatible[0][0]], nb_of_box) - 2 + infos->nb_of_fourmis;
	int i = -1;
	int num_group_path_to_use;

	tab_paths_turn = (int **)malloc(sizeof(int*) * nbr_group_paths);
	while (++i < nbr_group_paths)
		tab_paths_turn[i] = (int*)malloc(sizeof(int) * nb_turn_max);
	i = -1
	while (++i < nb_compatibles)
		ft_fill_tab_path_turn_i(infos, i, tab_paths_turn, nb_turn_max);

	while (infos->nb_of_fourmis > 0 && ft_move_ants(infos))
	{
		num_group_path_to_use = ft_find_group_path_to_use(infos, tab_paths_turn, nbr_group_paths, nb_turn_max);
		ft_create_ants(infos, num_group_path_to_use + 1);
	}
		ft_suite(infos, num_group_path_to_use);

}


