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

int ft_lstdel_last(t_list *start)
{
	t_ants *tmp;
	t_ants *prev;

	if(start->first_ant->next == NULL)
	{
		free(start->first_ant)
		return(0);
	}
	tmp = start->first_ant;
	prev = start->first_ant;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->num_ant != ant_to_del)
			prev = prev->next;
	}
	prev->next = NULL;
	free(tmp);
	return(1);
}

void ft_lstdel_list(t_list *start)
{
	while (start->first_ant)
		ft_lstdel_last(start);
	free(start);
}


int ft_lstadd_start(t_list *start, int num_ant, int path, int room)
{
	t_ants *new_ant;
	t_ants *tmp;

	if (!(new_ant = ft_memalloc(sizeof(t_ants*))))
		return (NULL);
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->n_room = room;
	new_ant->next = start->first_ant;
	start->first_ant = new_ant;
}

int ft_lstadd_end(t_list *start, int num_ant, int path, int room)
{
	t_ants *new_ant;
	t_ants *tmp;

	if (!(new_ant = ft_memalloc(sizeof(t_ants*))))
		return (NULL);
	new_ant->num_ant = num_ant;
	new_ant->path_used = path;
	new_ant->n_room = room;
	new_ant->next = NULL;
	tmp = start->first_ant;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new_ant;
}