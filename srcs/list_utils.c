
#include <lem-in.h>

t_ants		*ft_lstdel_num_ant(t_ants **fa, int ant_to_del)
{
	t_ants *tmp;

	while ((*fa)->num_ant != ant_to_del)
		fa = &(*fa)->next;
	tmp = *fa;
	*fa = (*fa)->next;
	free(tmp);
	return (*fa);
}

void ft_new_lst(t_ants **fa)
{
	t_ants *new_list;

	if (!(new_list = ft_memalloc(sizeof(t_ants))))
		return ;
	fa = &new_list;
}

void ft_lstadd_start(t_ants **fa, int num_ant, int path, int room)
{
	t_ants *new_ant;

	if (!(new_ant = ft_memalloc(sizeof(t_ants))))
		return ;
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->index_room_path = room;
	new_ant->next = *fa;
	*fa = new_ant;
}

int ft_lstadd_end(t_ants **fa, int num_ant, int path, int room)
{
	t_ants *new_ant;

	if (!(new_ant = ft_memalloc(sizeof(t_ants))))
		return (0);
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->index_room_path = room;
	new_ant->next = NULL;
	while (*fa)
		fa = &((*fa)->next);
	*fa = new_ant;
	return(1);
}

void	ft_lstdel_start(t_ants **fa)
{
	t_ants *tmp;

	tmp = *fa;
	*fa = tmp->next;
	free(tmp);
}

void ft_lstdel_all(t_ants **fa)
{
	while(*fa)
		ft_lstdel_start(fa);
}


















