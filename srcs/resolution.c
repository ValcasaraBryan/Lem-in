
#include "lem-in.h"

int ft_fill_tab_path_turn_i(t_infos *infos, int n, int **tab_paths_turn, int nb_turn_max)
{
	ft_putendl("ft_fill_tab_path_turn_i");
	int i = -1;
	int j = 0;
	int to_add = 0;

ft_putnbr(nb_turn_max);
	while (++i < nb_turn_max)
	{
			ft_putendl("tato");
		j = 0;
		// ft_putchar('n');
		// ft_putnbr(n+1);
		// ft_putchar('j');
		// ft_putnbr(j);
		// ft_putchar('l');
		// ft_putnbr(ft_length_path(infos->tab_path[infos->tab_paths_compatibles[n][j]], infos->nb_of_box) - 1);
		// ft_putchar('i');
		// ft_putnbr(i+1);
		while (j < n + 1)
		{
			if (ft_length_path(infos->tab_path[infos->tab_paths_compatibles[n][j]], infos->nb_of_box) - 1 == i + 1)
			{
				ft_putendl("toto");
				to_add++;
			}
			j++;
		}

		// ft_putchar('a');
		// ft_putnbr(to_add);
		tab_paths_turn[n][i] = (i > 0) ? tab_paths_turn[n][i - 1] + to_add : to_add; 
//		tab_paths_turn[n][i] += to_add;
	}
	ft_putendl("ft_fill_tab_path_turn_i fin");
	return(1);
}

int ft_next_room_is_free(t_infos *infos, int index_path, int index_room)
{
	if (infos->data[infos->tab_path[index_path][index_room]].commands == 2)
		return(2);
	if (infos->data[infos->tab_path[index_path][index_room]].full == 0)
		return(1);
	return(0);
}

int ft_move_ants(t_infos *i)
{
	ft_putendl("ft_move ants");
	t_ants *tmp = i->first_ant;
	int room_free = 0;

	if(!tmp)
		return(1);
	while (tmp->next)
	{
		ft_putendl("tata");
		if ((room_free = ft_next_room_is_free(i, tmp->path_used, tmp->index_room_path + 1)) > 0)
		{
			i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].full = 0;
			tmp->index_room_path++;
			if (room_free != 2)
				i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].full = 1;
			ft_printf("L%d-%s", tmp->num_ant, i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].name_box);
		}
		if (tmp->next)
			ft_putchar(' ');
		if (room_free == 2)
			tmp = ft_lstdel_num_ant(&i->first_ant, tmp->num_ant);
		tmp = tmp->next;
	}
	ft_putendl("ft_move ants fin");
	return(1);
}

int ft_find_group_path_to_use(t_infos *infos, int **tab_paths_turn, int nbr_group_paths, int nb_turn_max)
{

	ft_putendl("ft_find_group_path_to_use");
	int i = 0;
	int j = 0;

	while (i < nb_turn_max)
	{
		j = 0;
		while (j < nbr_group_paths)
		{
			ft_putnbr(infos->nb_of_fourmis);
			ft_putnbr(tab_paths_turn[j][i]);
			if (infos->nb_of_fourmis <= tab_paths_turn[j][i])
			{
				infos->nb_of_fourmis -= j + 1;
				ft_putendl("ft_find_group_path_to_use fin trouvé");
				return(j);
			}
			j++;
		}
		i++;
	}
	ft_putendl("ft_find_group_path_to_use fin");
	return(-1);
}

int ft_create_ants(t_infos *infos, int nb_ants_to_create)
{
	ft_putendl("ft_create ants");
	int i = -1;

	while (++i < nb_ants_to_create)
	{
		ft_putendl("yo");
		ft_putnbr(infos->tab_path[infos->tab_paths_compatibles[nb_ants_to_create - 1][i]][1]);
		ft_lstadd_end(&infos->first_ant, infos->nb_of_fourmis, infos->tab_path[infos->tab_paths_compatibles[nb_ants_to_create - 1][i]][1], 1);
		infos->nb_of_fourmis--;
		ft_putendl("lo");
	}
	ft_putendl("ft_create ants fin");
	return(1);
}

void ft_print_tab_path_turn_i(int **tab, int x, int y)
{
	int i = 0;
	int j = 0;

	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int		ft_resolve(t_infos *infos, int nbr_group_paths)
{
	ft_putendl("ft_resolve");
	int **tab_paths_turn;
	int nb_turn_max = ft_length_path(infos->tab_path[1], infos->nb_of_box) - 2 + infos->nb_of_fourmis;
	int i = -1;
	int num_group_path_to_use;

	ft_putstr("\nnb_turnmax :");
	ft_putnbr(nb_turn_max);
	ft_new_lst(&infos->first_ant);
	tab_paths_turn = (int **)malloc(sizeof(int*) * nbr_group_paths);
	while (++i < nbr_group_paths)
		tab_paths_turn[i] = (int*)malloc(sizeof(int) * nb_turn_max);
	i = -1;
	while (++i < nbr_group_paths)
		ft_fill_tab_path_turn_i(infos, i, tab_paths_turn, nb_turn_max);
	ft_print_tab_path_turn_i(tab_paths_turn, nb_turn_max, nbr_group_paths);
	while (infos->nb_of_fourmis > 0 && ft_move_ants(infos))
	{
		num_group_path_to_use = ft_find_group_path_to_use(infos, tab_paths_turn, nbr_group_paths, nb_turn_max);
		ft_putstr("group path to use : ");
		ft_putnbr(num_group_path_to_use);
		ft_putchar('\n');
		if (num_group_path_to_use < 0)
			return(-1);
		ft_create_ants(infos, num_group_path_to_use + 1);
//		infos->nb_of_fourmis -= num_group_path_to_use + 1;
		sleep(1);
	}

	ft_putendl("ft_resolve fin");
	return(1);
}


