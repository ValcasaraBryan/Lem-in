void ft_new_lst(void)
{
	t_ants *ants;
	t_list *start;

	if (!(start = ft_memalloc(sizeof(t_list*))))
		return (NULL);
	if (!(ants = ft_memalloc(sizeof(t_ants*))))
		return (NULL);

	ants->num_ants = -1;
	ants->path_used = -1;
	ants->n_room = -1;
	ants->next = NULL;
	start->first_ant = ants;
	return(start);
}

int ft_lstadd_start(t_ants **fa, int num_ant, int path, int room)
{
	t_ants *new_ant;

	if (!(new_ant = ft_memalloc(sizeof(t_ants*))))
		return (NULL);
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->n_room = room;
	new_ant->next = *fa;
	*fa = new_ant;
}

int ft_lstadd_end(t_ants **fa, int num_ant, int path, int room)
{
	t_ants *new_ant;
	t_ants **tmp;

	if (!(new_ant = ft_memalloc(sizeof(t_ants*))))
		return (NULL);
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->n_room = room;
	new_ant->next = NULL;
	tmp = &(infos->first_ant);
	while(*tmp)
		tmp = &(*tmp)->next;
	*tmp = new_ant;
}

void	ft_lstdel_start(t_ants **fa)
{
	t_ants *tmp;

	tmp = *fa;
	*fa = tmp->next;
	free(tmp);
}

void ft_lstdel(t_ants **fa)
{
	while(*fa)
		ft_lstdel_start(fa);
}


















