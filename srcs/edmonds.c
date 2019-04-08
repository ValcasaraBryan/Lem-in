#include "lem_in.h"




void	ft_new_pc(t_path_comp **fpc)
{
	t_path_comp *new_pc;

	if (!(new_pc = ft_memalloc(sizeof(t_path_comp))))
		return ;
	fpc = &new_pc;
}
/*
int		ft_add_pc_end(t_infos *inf, t_path_comp **fpc, int count)
{
	t_path_comp *new_pc;

	if (!(new_pc = malloc(sizeof(t_path_comp))))
		return (0);
	new_pc-> = ft_updated_path(inf, old_p, room);
	new_pc->npc = count;
	new_pc->next = NULL;
	while (*fg)
		fg = &((*fg)->next);
	*fg = new_p;
	return (1);
}*/

t_path_comp	*ft_lst_replace_count(t_path_comp **fpc, t_infos *inf, int count_to_del)
{
	ft_putendl("replace");
	// t_path_comp *tmp;
// 
	while ((*fpc)->npc != count_to_del)
		fpc = &(*fpc)->next;
//	tmp = *fpc;
	(*fpc)->tpc = inf->t_p;
	// free(tmp);
	return (*fpc);
}

int		ft_put_pc_middle(t_path_comp **fg, t_infos *inf, int count)
{
	ft_putendl("put mid");
	t_path_comp *new;

	if (!(new = malloc(sizeof(t_path_comp))))
		return (0);
	new->tpc = inf->t_p;
	new->npc = count;
	new->next = NULL;
	while ((*fg)->npc > count)
		fg = &((*fg)->next);
	new->next = *fg;
	*fg = new;
	return (1);
}

int		ft_put_pc_end(t_path_comp **fg, t_infos *inf, int count)
{
	ft_putendl("put end");
	t_path_comp *new;

	if (!(new = malloc(sizeof(t_path_comp))))
		return (0);
	new->tpc = inf->t_p;
	new->npc = count;
	new->next = NULL;
	while (*fg)
		fg = &((*fg)->next);
	*fg = new;
	return (1);
}

int		ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	ft_printf("etat entre %d et %d: %d\n", r1, r2, inf->data[r1].p_state[i]);
	
	return (inf->data[r1].p_state[i]);
}

void	ft_put_pipes_to_zero(t_infos *inf, int r1, int r2)
{
	ft_putendl("zero");
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
	ft_printf("etat entre %d et %d: %d\n", r2, r1, inf->data[r2].p_state[i]);
}

void	ft_put_pipe_to_one(t_infos *inf, int r1, int r2)
{
	ft_putendl("fpipe 1");
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
}

int		ft_find_nbr_pc(t_infos *inf)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < inf->data[inf->ind_start].nb_of_link)
		if (inf->data[inf->ind_start].p_state[i] == 1)
			count++;
	return (count);
}

int		ft_put_t_p_to_list_pc(t_infos *inf, int count)
{
	ft_putendl("ft_put_t_p_to_list_pc");
	t_path_comp *tmp;

	tmp = inf->pc;
	if (!tmp)
		ft_put_pc_end(&inf->pc, inf, count);
	else
	{
		ft_putendl("ft_put_t_p_to_list_pc3");
		ft_putnbr(tmp->npc);
		ft_putendl("");
		ft_putnbr(count);
		ft_putendl("");
		while (tmp->npc <= count && tmp->next)
		{
			ft_putendl("ft_put_t_p_to_list_pc4");
			tmp = tmp->next;
		}
		ft_putendl("ft_put_t_p_to_list_pc2");
		if (tmp->npc == count)
		{
			if (ft_length_path(inf->t_p[count], inf->nb_of_box) < ft_length_path(tmp->tpc[count], inf->nb_of_box))
				ft_lst_replace_count(&inf->pc, inf, count);
		}
		if (tmp)
			ft_put_pc_middle(&inf->pc, inf, count);
		else
			ft_put_pc_end(&inf->pc, inf, count);
	}
	return (count);
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
	// ft_putnbr(cr);
	while (k < inf->data[inf->ind_start].nb_of_link)
	{
		while (k < inf->data[inf->ind_start].nb_of_link && inf->data[inf->ind_start].p_state[k] != 1)
			k++;
		if (k == inf->data[inf->ind_start].nb_of_link)
			return (nb_path_found);
		if (!(pathtmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
			return (-1);
		pathtmp[0] = inf->ind_start;
		cr = inf->data[inf->ind_start].pipe[k]->NP;
		j = 1;
		while (inf->data[cr].C != 2)
		{
			i = 0;
			// ft_printf("i = %d\n", i);
			while (i < inf->data[cr].nb_of_link && inf->data[cr].p_state[i] != 1)
				i++;
			if (i < inf->data[cr].nb_of_link)
			{
				pathtmp[j] = inf->data[cr].pipe[i]->NP;
				cr = pathtmp[j];
				ft_printf("%4d ", cr);
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
	ft_putendl("ft_save_p_states end");
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
			return (ft_put_t_p_to_list_pc(inf, ft_save_path(inf)));
		}
		else
			ft_add_graph_end(inf, &inf->l, inf->l->path,
					inf->data[inf->data[inf->l->c_r].pipe[i]->n_piece].n_piece);
	}
	return (0);
}

int ft_ed(t_infos *inf)
{
	int i;
	int *tmp;


	ft_new_pc(&inf->pc);
	i = 0;
	if (!(tmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
		return (-1);
	ft_add_graph_end(inf, &inf->l, tmp, inf->ind_start);
	free(tmp);
	while (*(&inf->l))
	{
		i = -1;
		inf->data[inf->l->c_r].weight = 0;
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
		ft_graph_del_start(&inf->l);
		if (!inf->l)
		{
			ft_putendl("liste finie");
			return (2);
		}
	}
	return (2);
}
