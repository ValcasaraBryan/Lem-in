/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:10:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:36:39 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <mlx.h>

typedef struct		data_s
{
	int				index_of_box;
	int				nb_of_box;
	int				*grille_x;
	int				*grille_y;
	void			*mlx_ptr;
	void			*mlx_win;
	int				longueur_win;
	int				largeur_win;
	int				color;
	int				color_carre_x;
	int				color_carre_y;
	int				color_interieur;
	int				centre_x;
	int				centre_y;
	int				longueur;
	int				largeur;
	int				medium;
	int				maximum_x;
	int				maximum_y;
	int				coef;
	int				**mappage_box;
	int				**mappage_pipe;
	t_infos			*infos;
}					data_t;

int			init_grille_x(data_t *p, char c)
{
	int		i;
	int		j;
	int		divi;
	int		nb_of_line;
	int		res;

	i = 0;
	nb_of_line = p->medium + 1;
	i = 0;
	if (c == 'x' || c == 'y')
	{
		divi = p->longueur_win / nb_of_line;
		while (i < nb_of_line)
		{
			j = 0;
			res = divi;
			while (j < i)
			{
				res += divi;
				j++;
			}
			p->grille_x[i] = res;
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int			init_grille_y(data_t *p, char c)
{
	int		i;
	int		j;
	int		divi;
	int		nb_of_line;
	int		res;

	i = 0;
	nb_of_line = p->medium + 1;
	i = 0;
	if (c == 'x' || c == 'y')
	{
		divi = p->largeur_win / nb_of_line;
		while (i < nb_of_line)
		{
			j = 0;
			res = divi;
			while (j < i)
			{
				res += divi;
				j++;
			}
			p->grille_y[i] = res;
			i++;
		}
	}
	else
		return (0);
	return (1);
}

int			val_max_coor(t_data *data, char c)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	while (data[i].name_box)
	{
		if (c == 'x')
			if (data[i].coor_x > val)
				val = data[i].coor_x;
		if (c == 'y')
			if (data[i].coor_y > val)
				val = data[i].coor_y;
		i++;
	}
	return (val);
}

int			init_tab_x(data_t *p, int nb_of_line)
{
	int		i;

	i = 0;
	if (!(p->grille_x = (int *)malloc(sizeof(int) * nb_of_line)))
		return (0);
	while (i < nb_of_line)
		p->grille_x[i++] = 0;
	return (1);
}

int			init_tab_y(data_t *p, int nb_of_line)
{
	int		i;

	i = 0;
	if (!(p->grille_y = (int *)malloc(sizeof(int) * nb_of_line)))
		return (0);
	while (i < nb_of_line)
		p->grille_y[i++] = 0;
	return (1);
}

int			nb_of_tab(t_data *data)
{
	int		i;

	i = 0;
	if (!data)
		return (-1);
	while (data[i].name_box)
		i++;
	return (i);
}

int			check_coordonnee(data_t *p, int x, int y)
{
	int		i;

	i = 0;
	while (i < p->medium)
	{
		if (x == p->grille_x[i] || y == p->grille_y[i])
			return (1);
		i++;
	}
	return (0);
}

int			check_coordonnee_data(data_t *p, int x, int y)
{
	int		i;

	i = 0;
	while (p->infos->data[i].name_box)
	{
		if (p->infos->data[i].coor_x == x && p->infos->data[i].coor_y == y)
			return (1);
		i++;
	}
	return (0);
}

int			chemin(data_t *p, t_data *start, t_data *finish)
{
	(void)p;
	(void)start;
	printf("\033[34;05mx = %d - y = %d\n\033[00m", finish->coor_x, finish->coor_y);
	return (0);
}

int			set_distance(data_t *p, int val, int x, int y)
{
	int		tmp;

	tmp = 0;
	if (y - 1 >= 0)
	{
		tmp = p->mappage_box[x][y - 1];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (y + 1 < p->medium)
	{
		tmp = p->mappage_box[x][y + 1];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (x - 1 >= 0)
	{
		tmp = p->mappage_box[x - 1][y];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (x + 1 < p->medium)
	{
		tmp = p->mappage_box[x + 1][y];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	return (val);
}

int			check_position_around(data_t *p, int x, int y)
{
	int		x_val;
	int		y_val;
	int		y_init;
	int		x_init;
	int		val;

	x_val = (x == 0) ? -1 : 1;
	y_val = (y == 0) ? -1 : 1;
	x_init = (x == 0) ? p->medium - 1 : 0;
	while (x_init >= 0 && x_init < p->medium)
	{
		y_init = (y == 0) ? p->medium - 1 : 0;
		while (y_init >= 0 && y_init < p->medium)
		{
			val = p->medium * p->medium;
			if (p->mappage_box[x_init][y_init] == 0 || p->mappage_box[x_init][y_init] > 1)
			{
				val = set_distance(p, val, x_init, y_init);
				if (val > 0 && val < p->medium * p->medium)
					p->mappage_box[x_init][y_init] = val + 1;
			}
			y_init = (y_val == -1) ? y_init + y_val : y_init + y_val;
		}
		x_init = (x_val == -1) ?  x_init + x_val : x_init + x_val;
	}
	return (1);
}

int			mappage(data_t *p, int x, int y, int val)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 1;
	j = -1;
	k = 1;
	l = -1;
	if (x + i < p->medium && x + i >= 0) // gauche
	{
		if (p->mappage_box[x + i][y] != 2)
			p->mappage_box[x + i][y] = val;
		i++;
	}
	if (x + j >= 0 && x + j < p->medium) // droite
	{
		if (p->mappage_box[x + j][y] != 2)
			p->mappage_box[x + j][y] = val;
		j--;
	}
	if (y + k < p->medium && y + k >= 0) // bas
	{
		if (p->mappage_box[x][y + k] != 2)
			p->mappage_box[x][y + k] = val;
		k++;
	}
	if (y + l >= 0 && y + l < p->medium) // haut
	{
		if (p->mappage_box[x][y + l] != 2)
			p->mappage_box[x][y + l] = val;
		l--;
	}
	return (1);
}

int			set_pos_around(data_t *p, int n_box, int n_pipe)
{
	int		x;
	int		y;
	int		val_x;
	int		val_y;

	x = p->infos->data[n_box].coor_x;
	y = p->infos->data[n_box].coor_y;
	val = p->medium * p->medium;
	tmp = 0;
	if (y - 1 >= 0)
	{
		tmp = p->mappage_box[x][y - 1];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (y + 1 < map->y_map)
	{
		tmp = p->mappage_box[x][y + 1];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (x - 1 >= 0)
	{
		tmp = p->mappage_box[x - 1][y];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	if (x + 1 < map->x_map)
	{
		tmp = p->mappage_box[x + 1][y];
		val = (tmp > 0 && tmp <= val) ? tmp : val;
	}
	return (val);
}

int			key_hook(int keycode, data_t *p)
{
	int i;
	int j;

	i = 0;
	p->color = 5000000;
	if (keycode == 36)
		printf("ENTREE\n");
	else if (keycode == 53)
		printf("ESC\n");
	else if (keycode == 126)
	{
		p->color++;
		printf("HAUT %d\n", p->color);
	}
	else if (keycode == 125)
	{
		p->color--;
		printf("BAS %d\n", p->color);
	}
	else if (keycode == 123)
	{
		p->color -= 15;
		printf("GAUCHE %d\n", p->color);
	}
	else if (keycode == 124)
	{
		p->color += 15;
		printf("DROIT b%d\n", p->color);
	}
	else if (keycode == 67)
	{
		p->color *= 10;
		printf("* %d\n", p->color);
	}
	else if (keycode == 69)
	{
		p->color += 100;
		printf("+ %d\n", p->color);
	}
	else if (keycode == 78)
	{
		p->color -= 100;
		printf("- %d\n", p->color);
	}
	else if (keycode == 75)
	{
		p->color /= 10;
		printf("/ %d\n", p->color);
	}
	else
		printf("%d\n", keycode);
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 54461616;
	p->longueur = p->longueur_win * 0.03;
	p->largeur = p->largeur_win * 0.03;
	while (i < p->longueur_win)
	{
		j = 0;
		while (j < p->largeur_win)
		{
			mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color);	
			if (check_coordonnee(p, i, j))
				mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, 26459932); // affiche les grilles
			j++;
		}
		i++;
	}
	int nb;
	int nb_2;

	i = -1;
	while (i++ < p->medium)
	{
		j = -1;
		while (j++ < p->medium)
		{
			if (check_coordonnee_data(p, j, i))
				printf("\033[34;01m%3d-%-2d\033[00m", j, i);
			else
				printf("%3d-%-2d", j, i);
		}
		printf("\n");
	}
	i = 0;
	if (!(p->mappage_box = (int **)malloc(sizeof(int *) * p->medium)))
		return (0);
	while (i < p->medium)
	{
		if (!(p->mappage_box[i] = (int *)malloc(sizeof(int) * p->medium)))
			return (0);
		j = 0;
		while (j < p->medium)
			p->mappage_box[i][j++] = 0;
		i++;
	}
	if (!(p->mappage_pipe = (int **)malloc(sizeof(int *) * p->medium)))
		return (0);
	i = 0;
	while (i < p->medium)
	{
		if (!(p->mappage_pipe[i] = (int *)malloc(sizeof(int) * p->medium)))
			return (0);
		j = 0;
		while (j < p->medium)
			p->mappage_pipe[i][j++] = 0;
		i++;
	}
	printf("\n");
	nb = 0;
	while (nb < p->infos->nb_of_box)
	{
		p->mappage_box[p->infos->data[nb].coor_x - 1][p->infos->data[nb].coor_y - 1] = -2;
		nb++;
	}
	nb = 0;
	while (nb < p->infos->nb_of_box)
	{
		nb_2 = 1;
		while (nb_2 < p->infos->data[nb].nb_of_link)
		{
			i = 0;
			while (i <= p->medium)
			{
				j = 0;
				while (j <= p->medium)
				{
					if (p->infos->data[nb].pipe[nb_2]->coor_x == j && p->infos->data[nb].pipe[nb_2]->coor_y == i)
					{
						mappage(p, j - 1, i - 1, 1);
						check_position_around(p, 0, 0); // haut gauche
						check_position_around(p, 0, p->medium); // bas gauche
						check_position_around(p, p->medium, 0); // haut droit
						check_position_around(p, p->medium, p->medium); //bas droit
						set_pos_around(p, nb, nb_2);
					}
					j++;
				}
				i++;
			}
			nb_2++;
			break ;
		}
		nb++;
		break ;
	}
	i = -1;
	while (++i < p->medium)
	{
		j = -1;
		while (++j < p->medium)
		{
			printf("%2d", p->mappage_box[j][i]);
		}
		printf("\n");
	}
	i = 0;
	while (p->infos->data[i].name_box)
	{
		j = 0;
		printf("\033[34;01mx = %d - y = %d\n\033[00m", p->infos->data[i].coor_x,  p->infos->data[i].coor_y);
		while (j < p->infos->data[i].nb_of_link)
		{
			chemin(p, &p->infos->data[i], p->infos->data[i].pipe[j]);
			j++;
		}
		i++;
	}
	
	while (p->infos->data[p->index_of_box].name_box)
	{
		p->centre_y = p->grille_y[p->infos->data[p->index_of_box].coor_y - 1] - (p->largeur / 2); // centre du carre + sur une des grille de la fenetre
		p->centre_x = p->grille_x[p->infos->data[p->index_of_box].coor_x - 1] - (p->longueur / 2); // centre du carre + sur une des grille de la fenetre
		i = p->centre_x;
		while (i < p->centre_x + p->longueur)
		{
			j = p->centre_y;
			while (j < p->centre_y + p->largeur)
			{
				if (i != p->centre_x && i != p->centre_x + p->longueur - 1
					&& j != p->centre_y && j != p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_interieur);
				if (i == p->centre_x || i == p->centre_x + p->longueur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_x);			
				if (j == p->centre_y || j == p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_y);
				j++;
			}
			i++;
		}
		printf("x = %d - y = %d ----\n", p->infos->data[p->index_of_box].coor_x, p->infos->data[p->index_of_box].coor_y);
		nb = -1;
		while (++nb < p->infos->data[p->index_of_box].nb_of_link)
			printf("x = %d, y = %d\n", p->infos->data[p->index_of_box].pipe[nb]->coor_x, p->infos->data[p->index_of_box].pipe[nb]->coor_y);
		printf("\n");
		p->index_of_box++;
	}
	p->index_of_box = 0;
	return (0);
}

int			main(int argc, char **argv)
{
	data_t	p;
	t_infos	infos;

	(void)argc;
	(void)argv;
	(void)p;
	p.mlx_ptr = mlx_init();
	ft_fprintf("/-------------------------------------------\\\n", 2);
	infos = get_file();
	
	if (!infos.file)
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		return (0);
	}
	if (!(init_data(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(check_file(&infos, 0, 0)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(check_commandes(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(logical_infos_box(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}

	// ft_algo(&infos);
	ft_put_data(&infos);
	ft_put_list(infos.file);
	ft_fprintf("OK\n", 1);
	ft_fprintf("\\-------------------------------------------/\n\n\n", 2);
	p.infos = &infos;
	p.color = 0;
	p.index_of_box = 0;
	p.nb_of_box = nb_of_tab(infos.data);
	p.maximum_x = val_max_coor(infos.data, 'x');
	p.maximum_y = val_max_coor(infos.data, 'y');
	p.medium = (p.maximum_x > p.maximum_y) ? p.maximum_x : p.maximum_y;
	p.coef = p.medium * 1.8;
	printf("%d medium\n", p.medium);
	printf("%d, %d- maximum\n", p.maximum_x, p.maximum_y);
	p.longueur_win = p.medium * p.coef;
	p.largeur_win = p.medium * p.coef;
	init_tab_x(&p, p.medium + 1);
	init_tab_y(&p, p.medium + 1);
	init_grille_x(&p, 'x');
	init_grille_y(&p, 'x');
	printf("%d - %d\n", p.longueur_win, p.largeur_win);
	p.mlx_win = mlx_new_window(p.mlx_ptr, p.longueur_win, p.largeur_win, "mlx 42");
	mlx_key_hook(p.mlx_win, key_hook, &p);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
