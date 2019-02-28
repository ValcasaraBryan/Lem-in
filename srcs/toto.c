
#include "lem-in.h"


t_graph	*ft_del_graph_current_r(t_graph **g, int room)
{
//	ft_putendl("graph_current");
	t_graph *tmp;

	while ((*g)->current_r != room)
	{

//		ft_putnbr((*g)->current_r);
//		ft_putendl(" = current");
//		ft_putnbr(room);
//		ft_putendl(" = 2 find");
		g = &(*g)->next;
	}
//	ft_putendl("graph_current2");
	tmp = *g;
	*g = (*g)->next;
//	ft_putendl("graph_current f");
	free(tmp);
//	ft_putendl("graph_current f1");
	return (*g);
}

int *ft_init_g(int start, int nb_b)
{
	int *path;
	int i = 0;

	if(!(path = malloc(sizeof(int*) * nb_b)))
		return(NULL);
	path[0] = start;
	while (++i < nb_b)
		path[i] = -1;
	return(path);
}

int *ft_updated_path(t_infos *inf, int *old_p, int room)
{
	// ft_putendl("updated");
	int *new_p;
	int i = 0;

	if (!(new_p = ft_memalloc(sizeof(int *) * inf->nb_of_box)))
		return (NULL);
	while (old_p[i] != -1)
	{
		new_p[i] = old_p[i];
		i++;
	}
	new_p[i] = room;
//	ft_putnbr(inf->nb_of_box);
	while (++i < inf->nb_of_box)
	{
//		ft_putendl("toto");
		new_p[i] = -1;
	}
	// ft_putendl("updated fi4");
//	ft_putendl("updated fi5");
	return(new_p);
}

int		ft_add_graph_end(t_infos *inf, t_graph **fg, int *old_p, int room)
{
	// ft_putendl("graphem=nd");
	t_graph *new_p;

	if (!(new_p = ft_memalloc(sizeof(t_graph))))
		return (0);
	new_p->path = ft_updated_path(inf, old_p, room);
	new_p->current_r = room;
	new_p->next = NULL;
	while (*fg)
		fg = &((*fg)->next);
	*fg = new_p;
	return (1);
}

void	ft_new_graph(t_graph **fg)
{
	t_graph *new_g;

	if (!(new_g = ft_memalloc(sizeof(t_graph))))
		return ;
	fg = &new_g;
}

void	ft_graph_del_start(t_graph **fa)
{
	t_graph *tmp;

	tmp = *fa;
	free(tmp->path);
	*fa = tmp->next;
	free(tmp);
}
void	ft_lstdel_all_graph(t_graph **fa)
{
	while (*fa)
		ft_graph_del_start(fa);
}

int ft_un_el_l_commence_par_tab_i(t_infos *inf, int tabi, int nbc)
{
	t_graph *tmp;
	// ft_putendl("yo");

	tmp = inf->l;
	while (tmp)
	{
		// printf("com list %d - %d\n",tmp->path[1], tabi);
		if (tmp->path[1] == tabi)
			return (1);
		tmp = tmp->next;
	}
	int i = 0;
	// printf("ola %d - %d\n", i, nbc);
	while (i < nbc)
	{
		// printf("com t_p %d - %d\n", inf->t_p[inf->t_p_c[nbc - 1][i]][1], tabi);
		if (inf->t_p[inf->t_p_c[nbc - 1][i]][1] == tabi)
			return(1);
		i++;
	}
	return(0);
}

int ft_olalala(t_infos *inf, int start, int nbc)
{
	int i = 0;
	int *tab;

	if (!(tab = (int *)malloc(sizeof(int) * inf->data[start].nb_of_link)))
		return(-1);
	while (i < inf->data[start].nb_of_link)
	{
		tab[i] = inf->data[start].pipe[i]->n_piece;
		i++;
	}
	i = 0;
	while (i < inf->data[start].nb_of_link)
	{
		if (!ft_un_el_l_commence_par_tab_i(inf, tab[i], nbc))
			inf->nb_path_max--;
		i++;
	}
	free(tab);
	if (nbc == inf->nb_path_max)
		return(1);
	return(0);
}

int	ft_search_path(t_infos *inf, int start)
{
	int lp = 1;
	int i = -1;
	int *tmp = NULL;
	int r = 0;

	tmp = ft_alloc_tab_int(inf->nb_of_box, -1);
	ft_add_graph_end(inf, &inf->l, tmp, start);
	free(tmp);
	while (*(&inf->l))
	{
		// ft_putnbr(inf->nb_path_max);
		// ft_putendl("ici 677767");
	//	printf("inf->l = %p, g = %p, current = %d\n", inf->l, g, inf->l->current_r);
		while (ft_length_path(inf->l->path, inf->nb_of_box) == lp && lp <= inf->nb_of_box)
		{
			// printf("lp vauttttttt ; %d   ", lp);
			i = 0;
			while (i < inf->data[inf->l->current_r].nb_of_link)
			{
				 // printf("%d - %d\n", inf->l->current_r, inf->data[inf->data[inf->l->current_r].pipe[i]->n_piece].n_piece);
				if (ft_check_precedents(inf, inf->l->path, inf->data[inf->data[inf->l->current_r].pipe[i]->n_piece].n_piece))
				{
					if (inf->data[inf->data[inf->l->current_r].pipe[i]->n_piece].commands == 2)
					{
						// ft_putendl("end");
						inf->t_p = ft_update_tab_path(inf, ft_updated_path(inf, inf->l->path, inf->data[inf->data[inf->l->current_r].pipe[i]->n_piece].n_piece));
						// printf("t_p[0][0]0 %d\n", inf->t_p[0][0]);

							// ft_putendl("lane trotr1");
						if ((r = ft_choose_paths(inf)) == inf->nb_path_max)
						{
							// ft_putendl("lane trotr1");
							ft_lstdel_all_graph(&inf->l);
							// ft_putendl("lane trotr1");
							return(1);
						}
						// ft_putnbr(r);
						// ft_putnbr(inf->nb_path_max);
						r = ft_olalala(inf, start, r);
						// ft_putnbr(inf->nb_path_max);
						if (r)
							return((r < 0)? 0 : 1);
						// ft_putnbr(inf->nb_path_max);
						// ft_putendl("lane trotr1");
					}
					else
					{
//						ft_putnbr(inf->l->current_r);
						ft_add_graph_end(inf, &inf->l, inf->l->path, inf->data[inf->data[inf->l->current_r].pipe[i]->n_piece].n_piece);
					}
				}
				// else
					// ft_putendl("                                       salle deja vue");
//				ft_putendl("laaaa");
				i++;
			}
			ft_graph_del_start(&inf->l);
			if (!inf->l)
			{
				return(1);
			}
		}
		lp++;
		// printf("lp vaut ; %d\n", lp);
		// sleep(1);
	}
	// ft_putendl("fi");
	return(1);
}
