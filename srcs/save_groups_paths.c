/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_group_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:59:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/15 17:59:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			**alloc_init_tmp(t_infos *inf, int **tmp, int size)
{
	if (!(tmp[size] = (int *)malloc(sizeof(int) * inf->nb_of_box)))
	{
		ft_free_tab_int(tmp, size);
		return (NULL);
	}
	return (tmp);
}

int			**ft_init_tmp(t_infos *inf, int **tmp, int n)
{
	int		j;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (!(tmp = alloc_init_tmp(inf, tmp, i)))
			return (NULL);
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i][j] = inf->tp_final[i][j];
	}
	i = 0;
	while (inf->t_p)
	{
		if (!(tmp = alloc_init_tmp(inf, tmp, i + n)))
			return (NULL);
		j = -1;
		while (++j < inf->nb_of_box)
			tmp[i + n][j] = inf->t_p->tab[j];
		if (!inf->t_p->next)
			break ;
		inf->t_p = inf->t_p->next;
		i++;
	}
	return (tmp);
}

void		free_lst_tp(t_infos *infos)
{
	t_path	*tmp;

	if (!infos->t_p)
		return ;
	while (infos->t_p)
	{
		tmp = infos->t_p;
		free(infos->t_p->tab);
		infos->t_p = infos->t_p->next;
		free(tmp);
	}
}

int			**ft_put_t_p_to_tpfinal(t_infos *inf, int i, int n)
{
	int		**tmp;

	inf->tp_final_capacity += inf->tp_capacity;
	if (!(tmp = (int **)malloc(sizeof(int*) * (n + inf->tp_capacity))))
		return (NULL);
	ft_printf("inf->tp_final_capacity = %d\n", inf->tp_final_capacity);
	if (!(tmp = ft_init_tmp(inf, tmp, n)))
		return (NULL);
	ft_printf("inf->tp_capacity = %d\n", inf->tp_capacity);
	if (!(inf->t_p_c[inf->tp_capacity - 1] = (int*)malloc(sizeof(int)
		* inf->tp_capacity)))
	{
		ft_free_tab_int(tmp, inf->tp_final_capacity);
		ft_free_tab_int(inf->t_p_c, inf->tp_capacity - 1);
		return (NULL);
	}
	while (++i < inf->tp_capacity)
	{
		ft_printf("inf->t_p_c[%d][%d] = %d\n", inf->tp_capacity - 1, i,  n + i);
		inf->t_p_c[inf->tp_capacity - 1][i] = n + i;
	}
	free_lst_tp(inf);
	ft_free_tab_int(inf->tp_final, n);
	return (tmp);
}

void		ft_norm_save_path(t_infos *inf, int *pathtmp, int *cr)
{
	int		i;
	int		j;

	j = 1;
	while (inf->data[*cr].C != 2)
	{
		i = 0;
		while (i < inf->data[*cr].nb_of_link
			&& inf->data[*cr].p_state[i] != 1)
			i++;
		if (i < inf->data[*cr].nb_of_link)
		{
			pathtmp[j] = *cr;
			*cr = inf->data[*cr].pipe[i]->NP;
			j++;
		}
	}
	pathtmp[j] = inf->ind_end;
}

void		print_tab(int	*tab, int len)
{
	int		i;

	i = 0;
	while (i < len)
		ft_printf("%-3d ", tab[i++]);
}

int			ft_save_path(t_infos *inf, int k, int nb_path_found, int cr)
{
	int		*pathtmp;

	// if (!(ft_init_tab_path(inf)))
		// return (0);
	inf->tp_capacity = 0;  // remplace "infos->t_p[0][0] = 0;" dans init_tab_path
	ft_printf("entree save_path\n");
	while (k < inf->data[inf->ind_start].nb_of_link)
	{
		while (k < inf->data[inf->ind_start].nb_of_link
			&& inf->data[inf->ind_start].p_state[k] != 1)
			k++;
		if (k == inf->data[inf->ind_start].nb_of_link)
		{
			ft_printf("sortie save_path %d\n", nb_path_found);
			return (nb_path_found);
		}
		if (!(pathtmp = ft_alloc_tab_int(inf->nb_of_box, -1)))
			return (-1);
		pathtmp[0] = inf->ind_start;
		cr = inf->data[inf->ind_start].pipe[k]->NP;
		ft_norm_save_path(inf, pathtmp, &cr);
		inf->t_p = ft_init_lst_path(inf->t_p, ft_length_path(pathtmp, inf->nb_of_box), pathtmp);
		nb_path_found++;
		k++;
	}
	ft_printf("sortie save_path %d\n", nb_path_found);
	return (nb_path_found);
}
