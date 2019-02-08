
#include "lem-in.h"

void	ft_free_tab_int(int **tab, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(tab[i++]);
	free(tab);
}

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void ft_put_tab_int(int *tab)
{
	int i = 0;

	while(i < 8)
	{
		ft_putnbr_fd(tab[i], 2);
		ft_putchar_fd(' ', 2);
	}
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
	return(1);
}

int ft_length_path(int *tab, int n)
{
	// ft_putendl("ft_length_path");
	int i = 0;

	while (i < n && tab[i] >= 0)
		i++;
	// ft_putendl("ft_length_path fin ");
	return (i);
}

int		**ft_init_tab_path(t_infos *infos, int *tab)
{
	ft_putendl_fd("init_tab_path", 2);
	int n;
	int **tmp;
	int i = 0;
	int j = 1;
	int k;
	int r = 1;

	n = infos->tab_path[0][0] + 1;
	ft_putnbr(n + 2);
	if (!(tmp = (int **)malloc(sizeof(int*) * (n + 2))))
		return (NULL);
	if (!(tmp[i] = (int *)malloc(sizeof(int) * 1)))
		return (NULL);

	while (++i <= n)
	{
		k = -1;
		if (!(tmp[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
			return (NULL);
		if (r == 1 && (i == n || ft_length_path(tab, infos->nb_of_box) < ft_length_path(infos->tab_path[j], infos->nb_of_box)))
		{
			while (++k < infos->nb_of_box)
				tmp[i][k] = tab[k];
			i++;
			if (i <= n)
				if (!(tmp[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
					return (NULL);
			k = -1;
			r = 0;
		}
		if (i <= n)
			while (++k < infos->nb_of_box)
				tmp[i][k] = infos->tab_path[j][k];
		j++;
	}
	tmp[0][0] = n;
	ft_free_tab_int(infos->tab_path, n - 1);
	return (tmp);
}

int		ft_search_path(t_infos *infos, int start)
{
	ft_putendl_fd("search_path", 2);
	ft_putnbr_fd(start, 2);
	int i = start;
	int j = 1;

	int *tab_path_n_piece;
	int *tab_index_pipe_to_try;

	tab_path_n_piece = ft_init(infos->nb_of_box, -1);
	tab_index_pipe_to_try = ft_init(infos->nb_of_box, 0);

	tab_path_n_piece[0] = start;
	while (i != start || tab_index_pipe_to_try[start] < infos->data[start].nb_of_link)
	{
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
		if (infos->data[i].commands == 2)
		{
			ft_putstr_fd("le paaaaaaaaaaaaaaaaaaaaaaaaaaaaaaath: ", 2);
			ft_putnbr_fd(tab_path_n_piece[0], 2);
			ft_putnbr_fd(tab_path_n_piece[1], 2);
			ft_putnbr_fd(tab_path_n_piece[2], 2);
			ft_putnbr_fd(tab_path_n_piece[3], 2);
			ft_putnbr_fd(tab_path_n_piece[4], 2);
			ft_putnbr_fd(tab_path_n_piece[5], 2);
			ft_putnbr_fd(tab_path_n_piece[6], 2);
			ft_putnbr_fd(tab_path_n_piece[7], 2);
			ft_putchar_fd('\n', 2);

			infos->tab_path = ft_init_tab_path(infos, tab_path_n_piece);
			j--;
			tab_path_n_piece[j] = -1;
			i = tab_path_n_piece[j - 1];
		}
		else if (tab_index_pipe_to_try[i] >= infos->data[i].nb_of_link)
		{
			tab_index_pipe_to_try[i] = 0;
			tab_path_n_piece[j - 1] = -1;
			j--;
			i = tab_path_n_piece[j - 1];
		}
	}
	ft_putendl_fd("search_path fin", 2);
	free(tab_path_n_piece);
	free(tab_index_pipe_to_try);
	return (infos->tab_path[0][0]);
}

int		ft_init_path(t_infos *infos)
{
	ft_putendl_fd("ft_init_path", 2);
	int i = 0;

	while (infos->data[i].commands != 1)
		i++;
	if (!ft_search_path(infos, i))
		return(0);
	return (1);
}

int		ft_algo(t_infos *infos)
{
	ft_putendl_fd("algo", 1);
	int i = -1;

	infos->tab_path = (int **)malloc(sizeof(int*));
	infos->tab_path[0] = (int *)malloc(sizeof(int));
	infos->tab_path[0][0] = 0;
	infos->nb_path_max = -1;
	while (++i < infos->nb_of_box)
		if (infos->data[i].commands != 0)
			infos->nb_path_max = (infos->nb_path_max == -1) ? infos->data[i].nb_of_link : ft_min_int(infos->nb_path_max, infos->data[i].nb_of_link);
	if (!infos->nb_path_max || !ft_init_path(infos))
	{
		free(infos->tab_path[0]);
		free(infos->tab_path);
		return (0);
	}
	if (ft_choose_paths(infos) <= 0)
		return (0);
	ft_putendl_fd("algo fin", 2);
	return (1);
}