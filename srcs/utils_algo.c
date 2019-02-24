 
#include <lem-in.h>

int		ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
void	ft_put_tab_int(int *tab)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putnbr_fd(tab[i], 2);
		ft_putchar_fd(' ', 2);
	}
}*/

int		ft_init_tab_path(t_infos *infos)
{
	if (!(infos->t_p = (int **)malloc(sizeof(int*))))
		return (0);
	if (!(infos->t_p[0] = (int *)malloc(sizeof(int))))
	{
		free(infos->t_p);
		return (0);
	}
	infos->t_p[0][0] = 0;
	infos->nb_path_max = -1;
	return (1);
}

int		ft_init_path(t_infos *infos)
{
	int i;

	i = 0;
	while (infos->data[i].commands != 1)
		i++;
	if (!ft_search_path(infos, i))
		return (0);
	return (1);
}

int		*ft_alloc_tab_int(int n, int val_initial)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	while (i < n)
	{
		tab[i] = val_initial;
		i++;
	}
	return (tab);
}

int		ft_length_path(int *tab, int n)
{
	int i;

	i = 0;
	while (i < n && tab[i] >= 0)
		i++;
	return (i);
}