
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
//	ft_putendl("updated");
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
//	ft_putendl("updated fi4");
//	free(old_p);
//	ft_putendl("updated fi5");
	return(new_p);
}

int		ft_add_graph_end(t_infos *inf, t_graph **fg, int *old_p, int room)
{
	ft_putendl("graphem=nd");
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
	if (tmp->next)
	{
		*fa = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}

int	ft_search_path(t_infos *inf, int start)
{
	ft_putendl("ici");
	t_graph *g;
	int lp = 1;
	int i = -1;
	int *tmp = NULL;


	tmp = ft_alloc_tab_int(inf->nb_of_box, -1);
	ft_add_graph_end(inf, &inf->l, tmp, start);
	g = inf->l;
	while (inf->l)
	{
		printf("inf->l = %p, g = %p, current = %d\n", inf->l, g, inf->l->current_r);
		while (ft_length_path(g->path, inf->nb_of_box) == lp)
		{
			// ft_putnbr(ft_length_path(g->path, inf->nb_of_box));
			i = 0;
			while (inf->data[g->current_r].nb_of_link > 1 && i < inf->data[g->current_r].nb_of_link)
			{
//				ft_putendl("mamen");
				if (ft_check_precedents(inf, g->path, inf->data[inf->data[g->current_r].pipe[i]->n_piece].n_piece))
				{
					if (inf->data[inf->data[g->current_r].pipe[i]->n_piece].commands == 2)
					{
						ft_putendl("end");
						inf->t_p = ft_update_tab_path(inf, ft_updated_path(inf, g->path, inf->data[inf->data[g->current_r].pipe[i]->n_piece].n_piece));
					}
					else
					{
//						ft_putnbr(g->current_r);
						ft_add_graph_end(inf, &inf->l, g->path, inf->data[inf->data[g->current_r].pipe[i]->n_piece].n_piece);
					}
				}
				else
					ft_putendl("                                       salle deja vue");
//				ft_putendl("laaaa");
				i++;
			}
//			ft_putendl("apres");
			ft_putnbr(g->path[0]);
			ft_putnbr(g->path[1]);
			ft_putnbr(g->path[2]);
			ft_putnbr(g->path[3]);
			ft_putnbr(g->path[4]);
			ft_putnbr(g->path[5]);
			ft_putnbr(g->path[6]);
			ft_putnbr(g->path[7]);
//			ft_putnbr(g->path[8]);
//			ft_putnbr(g->path[9]);
//			ft_putnbr(g->path[10]);
				ft_graph_del_start(&inf->l);
		//	ft_del_graph_current_r(&inf->l, g->current_r);
			ft_putendl("apres2");
		}
		lp++;
	}
	ft_putendl("fi");
	return(0);
}