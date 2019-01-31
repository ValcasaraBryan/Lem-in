
#include "lem-in.h"

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

//init un tab de int qui a a 0 la salle start, 1 l'index 1ere salle 
int *ft_init(int n, int val_initial)
{
	int *tab;
	int i = 0;

	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n)
	{
		tab[i] = val_initial;
		i++;
	}
	return (tab);
}

int ft_check_precedents(t_infos *infos, int* tab_path_n_piece, int n)
{
	int i  = 0;

	while (i < infos->nb_of_box)
	{
		if (tab_path_n_piece[i] == n)
			return(0);
		i++;
	}
	return(0);
}

int ft_length_path(int *tab, int nbr_init)
{
	int i = 0;

	while (tab[i] >= 0)
		i++;
	if (!i)
		return(nbr_init + 1);
	else
		return(i);
	return (0);
}

int ft_replace_path_i(int **path, int *tab, int i)
{
	int n;

	n = ft_length_path(tab, 0);
	free(path[i]);
	if (!(path[i] = (int *)malloc(sizeof(int) * n)))
		return (0);
	while (n-- > 0)
		path[i][n] = tab[n];
	return (1);
}

void ft_put_path_to_tab(int *tab, int **path)
{
	int n;
	int i = 0;

	n = ft_length_path(tab, 0);
	while (path[i] && n > ft_length_path(path[i], n))
		i++;
	if (path[i])
		ft_replace_path_i(path, tab, i);
}


int		ft_search_path(t_infos *infos, int **path, int start)
{
	int i = start;
	int j = 1;

	int *tab_path_n_piece;
	int *tab_index_pipe_to_try;

	tab_path_n_piece = ft_init(infos->nb_of_box, -1);
	tab_index_pipe_to_try = ft_init(infos->nb_of_box, 0);

	tab_path_n_piece[0] = start;
	while (infos->data[i].commands != 2)
	{
//		tab_index_pipe_to_try[i] = 0;
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
		if (infos->data[i].commands != 2)
		{
			ft_put_path_to_tab(tab_path_n_piece, path);
			j--;
			tab_path_n_piece[j] = -1;
		}
///			enregfistre et continue;
		else if (tab_index_pipe_to_try[i] >= infos->data[i].nb_of_link)
		{
			tab_index_pipe_to_try[i] = 0;
			tab_path_n_piece[j - 1] = -1;
			j--;
			i = tab_path_n_piece[j - 1];
		}
//			on met a 0 tabintpipetotry[i], tabpathnpiece[j - 1] == -1 ,on va a la salle d'avant (i prend tabpathnpiece[j - 1])

//		tab_path_n_piece[i] = t_info->data[start]->n_piece;
	}
	return (1);
}

int		ft_init_path(t_infos *infos, int nb_path_max)
{
	int **path;
	int i = 0;
	int j;

	path = (int **)malloc(sizeof(int *) * (nb_path_max + 1));
	while (i < nb_path_max)
	{
		j = 0;
		if (!(path[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box + 1))))
//			freeeeeee
			return(0);
		while (j < infos->nb_of_box + 1)
			path[i][j++] = -1;
		i++;
	}
	path[i] = NULL;
	i = 0;
	while (infos->data[i].commands != 1)
		i++;
	ft_search_path(infos, path, i);
	return (1);
}

int		ft_algo(t_infos *infos)
{
	int i = 0;
	int nb_path_max = 0;

	while (i < infos->nb_of_box)
	{
		if (infos->data[i].commands != 0)
			nb_path_max = (nb_path_max == 0) ? infos->data[i].nb_of_link : ft_min_int(nb_path_max, infos->data[i].nb_of_link);
		i++;
	}
	if (!ft_init_path(infos, nb_path_max))
		return (0);
	return (1);
}