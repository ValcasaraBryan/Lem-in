#include "lem_in.h"

int **ft_cp(t_infos *inf, int **tab)
{
	int **tmp;
	int i = -1;
	int j = 0;

	if (!(tmp = malloc(sizeof(int *) * tab[0][0])))
		return (NULL);
	while (++i < tab[0][0])
		if (!(tmp[i] = malloc(sizeof(int) * inf->nb_of_box)))
		{
			ft_free_tab_int(tmp, i - 1);
			return(NULL);
		}
	i = -1;
	while (++i < tab[0][0])
	{
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i][j] = tab[i + 1][j];
	}
	return(tmp);
}

int		ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	// ft_printf("etat entre %d et %d: %d\n", r1, r2, inf->data[r1].p_state[i]);
	return (inf->data[r1].p_state[i]);
}

void	ft_put_pipes_to_zero(t_infos *inf, int r1, int r2)
{
	// ft_putendl("zero");
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
	// ft_printf("etat entre %d et %d: %d\n", r2, r1, inf->data[r2].p_state[i]);
}

void	ft_put_pipe_to_one(t_infos *inf, int r1, int r2)
{
	// ft_putendl("fpipe 1");
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
}

int		**ft_put_t_p_to_tpfinal(t_infos *inf)
{
	int i = -1;
	int j = 0;
	int n = inf->tp_final_capacity;
	int **tmp;
	
	inf->tp_final_capacity += inf->t_p[0][0];
	if (!(tmp = (int **)malloc(sizeof(int*) * (n + inf->t_p[0][0]))))
		return (NULL);
	while (++i < n)
	{
		if (!(tmp[i] = (int *)malloc(sizeof(int) * inf->nb_of_box)))
		{
			ft_free_tab_int(tmp, i);
			return (NULL);
		}
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i][j] = inf->tp_final[i][j];
	}
	i = -1;
	while (++i < inf->t_p[0][0])
	{
		if (!(tmp[i + n] = (int *)malloc(sizeof(int) * inf->nb_of_box)))
		{
			ft_free_tab_int(tmp, i + n);
			return (NULL);
		}
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i + n][j] = inf->t_p[i + 1][j];
	}
	i = -1;
	if (!(inf->t_p_c[inf->t_p[0][0] - 1] = (int*)malloc(sizeof(int) * inf->t_p[0][0])))
	{	
		ft_putendl("ici on free");
		ft_free_tab_int(tmp, inf->tp_final_capacity);
		ft_free_tab_int(inf->t_p_c, inf->t_p[0][0] - 1);
		return (NULL);
	}
	while (++i < inf->t_p[0][0])
	{	
//		ft_printf("tpc[%d][%d] = %d", inf->t_p[0][0] - 1, i, n + i);
		inf->t_p_c[inf->t_p[0][0] - 1][i] = n + i;
//		ft_printf(" donc %d\n", inf->t_p_c[inf->t_p[0][0] - 1][i]);
	}
	ft_free_tab_int(inf->t_p, inf->t_p[0][0] + 1);
	ft_free_tab_int(inf->tp_final, n);
	return (tmp);
}

int		ft_save_path(t_infos *inf)
{
	ft_putendl("ft_save_path");
	int i;
	int j = 0;
	int nb_path_found = 0;
	int *pathtmp;
	int cr;
	int k = 0;

	if (!(ft_init_tab_path(inf)))
		return (0);
	cr = inf->ind_start;
	while (k < inf->data[inf->ind_start].nb_of_link)
	{
		while (k < inf->data[inf->ind_start].nb_of_link && inf->data[inf->ind_start].p_state[k] != 1)
			k++;
		if (k == inf->data[inf->ind_start].nb_of_link)
			return (nb_path_found);
		if (!(pathtmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
			return (-1);
		pathtmp[0] = inf->ind_start;
		ft_printf("%4d ", pathtmp[0]);
		cr = inf->data[inf->ind_start].pipe[k]->NP;
		j = 1;
		while (inf->data[cr].C != 2)
		{
			i = 0;
			while (i < inf->data[cr].nb_of_link && inf->data[cr].p_state[i] != 1)
				i++;
			if (i < inf->data[cr].nb_of_link)
			{
				// pathtmp[j] = inf->data[cr].pipe[i]->NP;
				// cr = pathtmp[j];
				pathtmp[j] = cr;
				cr = inf->data[cr].pipe[i]->NP;
				ft_printf("%4d ", pathtmp[j]);
				j++;
			}
			else
				ft_putendl("cas improbable");
		}
		pathtmp[j] = inf->ind_end;
		if (!(inf->t_p = ft_update_tab_path(inf, pathtmp)))
		{
			ft_putendl("ft_save_path didnt end well");
			free(pathtmp);
			return (-1);
		}
		nb_path_found++;
		k++;
		ft_putendl("");
	}
	ft_putendl("ft_save_path end well");
	return (nb_path_found);
}

void	ft_save_p_states(t_infos *inf)
{
	ft_putendl("ft_save_p_states");
	int i = 0;

	while (i < inf->nb_of_box && inf->l->path[i + 1] > -1)
	{
		if (ft_pipe_state(inf, inf->l->path[i + 1], inf->l->path[i]))
			ft_put_pipes_to_zero(inf, inf->l->path[i + 1], inf->l->path[i]);
		else
			ft_put_pipe_to_one(inf, inf->l->path[i], inf->l->path[i + 1]);
		i++;
	}
	ft_put_pipe_to_one(inf, inf->l->path[i], inf->ind_end);
//	ft_putendl("ft_save_p_states end");
}

int		ft_ed2(t_infos *inf, int i)
{
	if (ft_check_precedents(inf, inf->l->path,
				inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].n_piece)
			&& inf->data[inf->data[inf->l->c_r].
				pipe[i]->n_piece].W
			&& !inf->data[inf->l->c_r].p_state[i])
	{
		if (inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].commands == 2)
		{
			ft_putendl("on a trouvé un path");
			ft_save_p_states(inf);
			inf->r = ft_save_path(inf);
			inf->nb_group_path = ft_max_int(inf->r, inf->nb_group_path);
			inf->tp_final = ft_put_t_p_to_tpfinal(inf);
//			ft_printf("ret = %d\n", inf->r);
			return (inf->r);
		}
		else
			ft_add_graph_end(inf, &inf->l, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (0);
}

int		ft_is_room_on_a_path(t_infos *inf, int cr)
{
	int i = 0;
	int prev = -1;
	int j;

	while (i < inf->data[cr].nb_of_link && !inf->data[cr].p_state[i])
		i++;
	if (i < inf->data[cr].nb_of_link)
	{
		i = -1;
		while (++i < inf->data[cr].nb_of_link)
		{
			j = -1;
			prev = inf->data[cr].pipe[i]->NP;
			while (++j < inf->data[prev].nb_of_link)
			{
				if (inf->data[prev].pipe[j]->NP == cr && inf->data[prev].p_state[j] == 1)
					return (prev);
			}
		}
	}
	return (-1);
}

void		ft_ed2_special(t_infos *inf, int r_to_go)
{
	t_graph *tmp;

	tmp = inf->l;
//	ft_printf("coucou r to go = %d \n", r_to_go);
	if (ft_check_precedents(inf, inf->l->path, r_to_go)
			&& inf->data[r_to_go].W)
		ft_add_graph_end(inf, &inf->l, inf->l->path, r_to_go);
	while (tmp->next)
		tmp = tmp->next;
	tmp->climbe = 0;
}

int		ft_ed(t_infos *inf)
{
	int i;
	int *tmp;

	i = -1;
	i = 0;
	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (-1);
	ft_add_graph_end(inf, &inf->l, tmp, inf->ind_start);
	free(tmp);
	while (*(&inf->l))
	{
		i = -1;
//		ft_printf("room %d list climbe? %d\n",inf->l->c_r, inf->l->climbe);
		inf->data[inf->l->c_r].weight = 0;

		if ((inf->r = ft_is_room_on_a_path(inf, inf->l->c_r)) >= 0 && inf->l->climbe)
			ft_ed2_special(inf, inf->r);
		else
		{
			while (++i < inf->data[inf->l->c_r].nb_of_link)
			{
				inf->r = ft_ed2(inf, i);
				if (inf->r)
				{
					ft_lstdel_all_graph(&inf->l);
					if (inf->r < 0)
					{
						ft_putendl("error malloc");
						return (-1);
					}
					if (inf->r == inf->nb_path_max)
					{
						ft_putendl("yey");
						return (2);
					}
					if (inf->r > 0)
					{
						ft_putendl("continue");
						return (1);
					}
				}
			}
		}
		ft_graph_del_start(&inf->l);
		if (!inf->l)
		{
			ft_putendl("liste finie");
			return (2);
		}
	}
	return (2);
}
