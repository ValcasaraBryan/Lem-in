/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:09:13 by glebouch          #+#    #+#             */
/*   Updated: 2019/03/01 17:28:47 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_next_room_is_free(t_infos *infos, int index_path, int index_room)
{
	if (infos->data[infos->tp_final[index_path][index_room]].commands == 2)
		return (2);
	if (infos->data[infos->tp_final[index_path][index_room]].full == 0)
		return (1);
	//ft_printf("\n\nblock: room used\n\n");
	return (0);
}

t_ants	*ft_move_ants2(t_infos *i, int room_free, t_ants *tmp)
{
	if ((room_free = ft_next_room_is_free(i, tmp->path_u, tmp->indx + 1)) > 0)
	{
		i->data[i->tp_final[tmp->path_u][tmp->indx]].full = 0;
		tmp->indx++;
		if (room_free != 2)
			i->data[i->tp_final[tmp->path_u][tmp->indx]].full = 1;
		ft_printf("L%d-%s", tmp->num_a,
				i->data[i->tp_final[tmp->path_u][tmp->indx]].name_box);
	}
	if (room_free == 2)
		tmp = ft_lstdel_num_ant(&i->first_ant, tmp->num_a);
	else
		tmp = tmp->next;
	if (tmp)
		ft_putchar(' ');
	return (tmp);
}

int		ft_move_ants(t_infos *i)
{
	t_ants	*tmp;
	int		room_free;

	tmp = i->first_ant;
	room_free = 0;
	if (!tmp)
		return (0);
	while (tmp)
		tmp = ft_move_ants2(i, room_free, tmp);
	ft_putchar('\n');
	i->count++;
	free(tmp);
	return (1);
}
