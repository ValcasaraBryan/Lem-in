
#include "lem-in.h"

int ft_fill_tab_path_turn_i(t_infos *infos, int n, int **tab_paths_turn, int nb_turn_max)
{
	int i;
	int j;
	int to_add;

	i = -1;
	j = 0;
	to_add = 0;
	while (++i < nb_turn_max)
	{
		j = 0;
		while (j < n + 1)
		{
			if (ft_length_path(infos->tab_path[infos->tab_paths_compatibles[n][j]], infos->nb_of_box) - 1 == i + 1)
				to_add++;
			j++;
		}
		tab_paths_turn[n][i] = (i > 0) ? tab_paths_turn[n][i - 1] + to_add : to_add; 
	}
	return (1);
}

int ft_next_room_is_free(t_infos *infos, int index_path, int index_room)
{
//	ft_putendl("ft_room_free");
//	ft_putnbr(index_path);
//	ft_putnbr(index_room);
//	ft_putnbr(infos->data[infos->tab_path[index_path][index_room]].commands);
	if (infos->data[infos->tab_path[index_path][index_room]].commands == 2)
//	{ft_putendl("ft_room_free 2");
		return(2);
//	}
	if (infos->data[infos->tab_path[index_path][index_room]].full == 0)
//	{ft_putendl("ft_room_free 0 ");
		return(1);
//	}
	return(0);
}

int ft_move_ants(t_infos *i)
{
//	ft_putendl("ft_move ants");
	t_ants *tmp = i->first_ant;
	int room_free = 0;

	if(!tmp)
	{
//		ft_putendl("ft_move ants sortie error");
		return(0);
	}
	while (tmp)
	{
//		ft_putendl("tata");
//		ft_putnbr(tmp->path_used);
		if ((room_free = ft_next_room_is_free(i, tmp->path_used, tmp->index_room_path + 1)) > 0)
		{
//			ft_putendl("tato");
			i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].full = 0;
			tmp->index_room_path++;
//			ft_putnbr(room_free);
			if (room_free != 2)
				i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].full = 1;
			ft_printf("L%d-%s", tmp->num_ant, i->data[i->tab_path[tmp->path_used][tmp->index_room_path]].name_box);
		}
//		ft_putendl("titi");
//		if (tmp->next)
//			ft_putendl("laaaaaaaaaaaaaaaaaaaaaaa");

		if (room_free == 2)
			tmp = ft_lstdel_num_ant(&i->first_ant, tmp->num_ant);
		else
			tmp = tmp->next;
		if (tmp)
			ft_putchar(' ');
	}
//	ft_putendl("ft_move ants fin");
	ft_putchar('\n');
	return(1);
}

int ft_find_group_path_to_use(t_infos *infos, int **tab_paths_turn, int nbr_group_paths, int nb_turn_max)
{

//	ft_putendl("ft_find_group_path_to_use");
	int i = 0;
	int j = 0;

	while (i < nb_turn_max)
	{
		j = 0;
		while (j < nbr_group_paths)
		{
//			ft_putnbr(infos->nb_f_left);
//			ft_putnbr(tab_paths_turn[j][i]);
//			ft_putchar('\n');
			if (infos->nb_f_left + 1 <= tab_paths_turn[j][i])
			{
//				infos->nb_of_fourmis -= j + 1;
//				ft_putendl("ft_find_group_path_to_use fin trouvé");
				return(j);
			}
			j++;
		}
		i++;
	}
//	ft_putendl("ft_find_group_path_to_use fin");
	return(-1);
}

int ft_create_ants(t_infos *i, int nb_ants_to_create)
{
//	ft_putendl("ft_create ants");
	int j = -1;

	while (++j < nb_ants_to_create)
	{
//		ft_putendl("yo");
//		ft_putnbr(i->tab_path[i->tab_paths_compatibles[nb_ants_to_create - 1][j]][1]);
//		ft_putnbr(j);
//		ft_putnbr(nb_ants_to_create);
//		ft_putnbr(i->nb_of_fourmis - i->nb_f_left);
//		ft_putnbr(i->nb_f_left);
//		ft_putnbr(i->nb_of_fourmis);
//		if (i->data[i->tab_path[i->tab_paths_compatibles[nb_ants_to_create - 1][j]][1]].commands == 2)
//			ft_printf("prem salle = fin L%d-%s\n", i->nb_of_fourmis - i->nb_f_left, i->data[i->tab_path[i->tab_paths_compatibles[nb_ants_to_create - 1][j]][0]].name_box);
//		else
//		ft_putendl("samere");
//		ft_putnbr(i->tab_paths_compatibles[nb_ants_to_create - 1][j]);
//		ft_putnbr(i->tab_path[i->tab_paths_compatibles[nb_ants_to_create - 1][j]][0]);
		if (!ft_lstadd_end(&i->first_ant, i->nb_of_fourmis - i->nb_f_left, i->tab_paths_compatibles[nb_ants_to_create - 1][j], 0))
			return(0);
		i->nb_f_left--;
//		ft_putendl("lo");
	}
//	ft_putendl("ft_create ants fin");
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
	int **tab_paths_turn;
	int nb_turn_max = ft_length_path(infos->tab_path[1], infos->nb_of_box) - 2 + infos->nb_of_fourmis;
	int i = -1;
	int num_group_path_to_use;

//	ft_putstr("\nnb_turnmax :");
	infos->nb_f_left = infos->nb_of_fourmis - 1;
//	ft_putnbr(nb_turn_max);
	if(!(tab_paths_turn = (int **)malloc(sizeof(int*) * nbr_group_paths)))
		return(0);
	while (++i < nbr_group_paths)
		if(!(tab_paths_turn[i] = (int*)malloc(sizeof(int) * nb_turn_max)))
		{
			ft_free_tab_int(tab_paths_turn, i);
			return(0);
		}
	ft_new_lst(&infos->first_ant);
	i = -1;
	while (++i < nbr_group_paths)
		ft_fill_tab_path_turn_i(infos, i, tab_paths_turn, nb_turn_max);
	ft_print_tab_path_turn_i(tab_paths_turn, nb_turn_max, nbr_group_paths);
	//
	num_group_path_to_use = ft_find_group_path_to_use(infos, tab_paths_turn, nbr_group_paths, nb_turn_max);
	if (num_group_path_to_use < 0)
		return(-1);
	if (!ft_create_ants(infos, num_group_path_to_use + 1))
		return(-1);
	while(ft_move_ants(infos))
	{
		if (infos->nb_f_left >= 0)
		{
			num_group_path_to_use = ft_find_group_path_to_use(infos, tab_paths_turn, nbr_group_paths, nb_turn_max);
			if (num_group_path_to_use < 0)
				return(-1);
			if (!ft_create_ants(infos, num_group_path_to_use + 1))
				return(-1);
		}
	}
	ft_free_tab_int(tab_paths_turn, nbr_group_paths);
//	ft_putendl("ft_resolve fin");
	return(1);
}
