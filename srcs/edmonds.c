#include "lem_in.h"


int ft_pipe_state(t_infos *inf, int r1, int r2)
{
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	return (inf->data[r1].p_state[i]);
}

void	ft_put_to_zero(t_infos *inf, int r1, int r2)
{
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 0;
	i = 0;
	while (inf->data[r2].pipe[i]->NP != r1)
		i++;
	inf->data[r2].p_state[i] = 0;
}

void	ft_put_to_one(t_infos *inf, int r1, int r2)
{
	int i = 0;

	while (inf->data[r1].pipe[i]->NP != r2)
		i++;
	inf->data[r1].p_state[i] = 1;
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

	cr = inf->ind_start;
	ft_putnbr(cr);
	while (k < inf->data[inf->ind_start].nb_of_link)
	{
		cr = inf->ind_start;
		if (!(pathtmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
			return (-1);
		pathtmp[0] = cr;
		j = 1;
		while (inf->data[cr].C != 2)
		{
			if (cr == inf->ind_start)
				i = k;
			else 
				i = 0;
			// ft_printf("i = %d\n", i);
			while (i < inf->data[cr].nb_of_link && inf->data[cr].p_state[i] != 1)
				i++;
			if (cr == inf->ind_start)
				k = i;
			if (i == inf->data[cr].nb_of_link)
			{
				free(pathtmp);
				return (nb_path_found);
			}
			pathtmp[j] = inf->data[cr].pipe[i]->NP;
			cr = pathtmp[j];
			ft_printf("%4d ", cr);
			j++;
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
			ft_put_to_zero(inf, inf->l->path[i + 1], inf->l->path[i]);
		else
			ft_put_to_one(inf, inf->l->path[i], inf->l->path[i + 1]);
		i++;
	}
	ft_put_to_one(inf, inf->l->path[i], inf->ind_end);
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
			return (ft_save_path(inf));
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
	int r;
	int *tmp;

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
			r = ft_ed2(inf, i);
			if (r)
			{
				ft_lstdel_all_graph(&inf->l);
				if (r < 0)
				{
					ft_putendl("error malloc");
					return (-1);
				}
				if (r == inf->nb_path_max)
				{
					ft_putendl("yey");
					return (2);
				}
				if (r > 0)
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
