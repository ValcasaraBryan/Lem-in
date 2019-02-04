
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
	ft_putendl_fd("length_path", 2);
	int i = 0;

	while (i < n && tab[i] >= 0)
		i++;
	ft_putendl_fd("length_path fin", 2);
	return (i);
}
/*
int ft_replace_path_i(t_infos *infos, int **path, int *tab, int i)
{
	int n;
	int j = -1;

	n = ft_length_path(tab);
	free(path[i]);
	if (!(path[i] = (int *)malloc(sizeof(int) * infos->nb_of_box)))
		return (0);
	while (++j < infos->nb_of_box)
		path[i][j] = tab[j];
	return (1);
}

int		ft_find_index_path_max(t_infos *infos, int **path)
{
	int i = 0;
	int index = 0;
	int length_max = 0;

	while (i < infos->nb_path_max)
	{
		if (ft_length_path(path[i]) > length_max)
		{
			length_max = ft_length_path(path[i]);
			index = i;
		}
		i++;
	}
	return (index);
}
*/
int		**ft_init_tab_path(t_infos *infos, int *tab)
{
	ft_putendl_fd("init_path", 2);
	int n;
	int **tmp;
	int i = 0;
	int j = 1;
	int k;
	int r = 1;

	n = infos->tab_path[0][0] + 1;
	if (!(tmp = (int **)malloc(sizeof(int*) * (n + 1))))
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
			if (i < n)
				if (!(tmp[i] = (int *)malloc(sizeof(int) * (infos->nb_of_box))))
					return (NULL);
			k = -1;
			r = 0;
		}
		while (i <= n && ++k < infos->nb_of_box)
			tmp[i][k] = infos->tab_path[j][k];
		j++;
	}
	tmp[0][0] = n;
	ft_free_tab_int(infos->tab_path, n - 1);
	return (tmp);
}
/*
void	ft_put_path_to_tab(t_infos *infos, int *tab, int **path)
{
	ft_putendl_fd("put_path_to_tab", 2);
//	int n;
//	int i = 0;
//	int index_path_max = 0;

	infos->tab_path = ft_init_tab_path(infos, tab);
//	n = ft_length_path(tab);
//	while (i < infos->nb_path_max)
//	{
//		if (ft_length_path(path[i]) == 0)
//		{
//			ft_replace_path_i(infos, path, tab, i);
//			return;
//		}
//		i++;
//	}
//	index_path_max = ft_find_index_path_max(infos, path);
//	if (ft_length_path(path[index_path_max]) > n)
//		ft_replace_path_i(infos, path, tab, index_path_max);
//	ft_putendl_fd("put_path_to_tab fin ", 2);
}
*/

int		ft_search_path(t_infos *infos, int **path, int start)
{
	ft_putendl_fd("search_path", 2);
	ft_putnbr_fd(start, 2);
	int i = start;
	int j = 1;
	(void)path;

	int *tab_path_n_piece;
	int *tab_index_pipe_to_try;

	tab_path_n_piece = ft_init(infos->nb_of_box, -1);
	tab_index_pipe_to_try = ft_init(infos->nb_of_box, 0);

	tab_path_n_piece[0] = start;
	while (tab_index_pipe_to_try[start] < infos->data[start].nb_of_link) //infos->data[i].commands != 2 && 
	{
		// ft_putendl_fd("laaaaab", 2);
		// ft_putnbr_fd(tab_index_pipe_to_try[i], 2);
		// ft_putnbr_fd(i, 2);
		// ft_putnbr_fd(infos->data[i].nb_of_link, 2);

//		tab_index_pipe_to_try[i] = 0;
		while (tab_index_pipe_to_try[i] < infos->data[i].nb_of_link && infos->data[i].commands != 2)
		{
			// ft_putendl_fd("iciiii", 2);
			if (ft_check_precedents(infos, tab_path_n_piece, infos->data[infos->data[i].pipe[tab_index_pipe_to_try[i]]->n_piece].n_piece))
			{
				// ft_putnbr_fd(i, 2);
				// ft_putendl_fd("ft_check_precedents", 2);
				tab_index_pipe_to_try[i]++;
				i = infos->data[infos->data[i].pipe[tab_index_pipe_to_try[i] - 1]->n_piece].n_piece;
				tab_path_n_piece[j] = i;
				// ft_putnbr_fd(i, 2);
				j++;
			}
			else
				tab_index_pipe_to_try[i]++;
		}
		// ft_putendl_fd("apres le while", 2);
		if (infos->data[i].commands == 2)
		{
//			ft_put_tab_int(tab_path_n_piece);
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
//			ft_put_path_to_tab(infos, tab_path_n_piece, path);
			j--;
			tab_path_n_piece[j] = -1;
			i = tab_path_n_piece[j - 1];
		}
		///			enregfistre et continue;
		else if (tab_index_pipe_to_try[i] >= infos->data[i].nb_of_link)
		{
			tab_index_pipe_to_try[i] = 0;
			tab_path_n_piece[j - 1] = -1;
			j--;
			i = tab_path_n_piece[j - 1];
		}
		// ft_putendl_fd("ta mere", 2);
		// ft_putnbr_fd(i, 2);
		// ft_putchar_fd(' ', 2);
		// ft_putnbr_fd(k, 2);
		// ft_putchar_fd('\n', 2);
//			on met a 0 tabintpipetotry[i], tabpathnpiece[j - 1] == -1 ,on va a la salle d'avant (i prend tabpathnpiece[j - 1])

//		tab_path_n_piece[i] = t_info->data[start]->n_piece;
	}
		ft_putendl_fd("search_path fin", 2);
	return (1);
}

int		ft_init_path(t_infos *infos)
{
	ft_putendl_fd("init_path", 2);
	int **path;
	int i = 0;
	int j;

	path = (int **)malloc(sizeof(int *) * (infos->nb_path_max + 1));
	while (i < infos->nb_path_max)
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

	ft_putnbr(path[0][0]);
	ft_putnbr(path[0][1]);
	ft_putnbr(path[0][2]);
	ft_putnbr(path[0][3]);
	ft_putnbr(path[0][4]);
	ft_putnbr(path[0][5]);
	ft_putnbr(path[0][6]);
	ft_putnbr(path[0][7]);

	ft_putchar(' ');
	ft_putnbr(path[1][0]);
	ft_putnbr(path[1][1]);
	ft_putnbr(path[1][2]);
	ft_putnbr(path[1][3]);
	ft_putnbr(path[1][4]);
	ft_putnbr(path[1][5]);
	ft_putnbr(path[1][6]);
	ft_putnbr(path[1][7]);

	ft_putendl_fd("init_path fin", 2);
	return (1);
}

int		ft_algo(t_infos *infos)
{
	ft_putendl_fd("algo", 2);
	int i = 0;

	infos->tab_path = (int **)malloc(sizeof(int*));
	infos->tab_path[0] = (int *)malloc(sizeof(int));
	infos->tab_path[0][0] = 0;
	infos->nb_path_max = -1;
	while (i < infos->nb_of_box)
	{
		if (infos->data[i].commands != 0)
			infos->nb_path_max = (infos->nb_path_max == -1) ? infos->data[i].nb_of_link : ft_min_int(infos->nb_path_max, infos->data[i].nb_of_link);
		i++;
	}
	if (!infos->nb_path_max || !ft_init_path(infos))
		return (0);
	ft_choose_paths(infos);
	ft_putendl_fd("algo fin", 2);
	ft_putendl_fd("algo fin", 2);
	return (1);
}