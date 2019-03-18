/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:40:44 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:28:33 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants	*ft_lstdel_num_ant(t_ants **fa, int ant_to_del)
{
	t_ants *tmp;

	while ((*fa)->num_a != ant_to_del)
		fa = &(*fa)->next;
	tmp = *fa;
	*fa = (*fa)->next;
	free(tmp);
	return (*fa);
}

void	ft_new_lst(t_ants **fa)
{
	t_ants *new_list;

	if (!(new_list = ft_memalloc(sizeof(t_ants))))
		return ;
	fa = &new_list;
}

void	ft_lstadd_start(t_ants **fa, int num_a, int path, int room)
{
	t_ants *new_ant;

	if (!(new_ant = ft_memalloc(sizeof(t_ants))))
		return ;
	new_ant->num_a = num_a;
	new_ant->path_u = path;
	new_ant->indx = room;
	new_ant->next = *fa;
	*fa = new_ant;
}

int		ft_lstadd_end(t_ants **fa, int num_a, int path, int room)
{
	t_ants *new_ant;

	if (!(new_ant = ft_memalloc(sizeof(t_ants))))
		return (0);
	new_ant->num_a = num_a;
	new_ant->path_u = path;
	new_ant->indx = room;
	new_ant->next = NULL;
	while (*fa)
		fa = &((*fa)->next);
	*fa = new_ant;
	return (1);
}

void	ft_lstdel_start(t_ants **fa)
{
	t_ants *tmp;

	tmp = *fa;
	*fa = tmp->next;
	free(tmp);
}
