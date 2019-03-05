#include "lem-in.h"
// #include "/usr/X11/include/mlx.h"
#include <mlx.h>

typedef struct		s_lem
{
	t_data			*data;
	int				color_ants;
	int				lem;
	struct s_lem	*next;
}					t_lem;

typedef struct		s_graphe
{
	t_lem			*lem;
	struct s_graphe	*next;
	struct s_graphe	*prev;
}					t_graphe;

typedef struct		data_s
{
	int				index_of_box;
	int				index_of_box_dest;
	int				nb_of_box;
	int				*grille_x;
	int				*grille_y;
	void			*mlx_ptr;
	void			*mlx_win;
	int				longueur_win;
	int				largeur_win;
	int				color;
	int				color_start;
	int				color_box_used;
	int				color_end;
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
	int				index_box_map;
	int				index_box_map_link;
	int				****mappage_pipe;
	struct s_ligne	*trait;
	t_infos			*infos;
	t_graphe		*graphe;
}					data_t;

typedef struct		s_ligne
{
	struct data_s	*p;
	int				z;
	int				j;
	int				start_x;
	int				start_y;
	int				finish_x;
	int				finish_y;
	char			c;
	int				color;
	int				n_piece;
}					t_ligne;

int			init_grille_x_y(data_t *p)
{
	int		i;
	int		j;
	int		divi;
	int		res;

	i = -1;

	divi = (p->longueur_win - 2) / p->medium;
	divi = (!(divi % divi)) ? divi : divi + (10 - divi);
	while (++i < p->medium)
	{
		j = -1;
		res = divi;
		while (++j < i)
			res += divi;
		p->grille_x[i] = res;
		p->grille_y[i] = res;
	}
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

int			init_tab_x_y(data_t *p)
{
	int		i;

	i = -1;
	if (!(p->grille_x = (int *)malloc(sizeof(int) * p->medium)))
		return (0);
	if (!(p->grille_y = (int *)malloc(sizeof(int) * p->medium)))
		return (0);
	while (++i < p->medium)
	{
		p->grille_x[i] = 0;
		p->grille_y[i] = 0;
	}
	return (1);
}

void		swap(int *val_1, int *val_2)
{
	int		one;
	int		two;
	int		tmp;

	one = *val_1;
	two = *val_2;
	tmp = one;
	one = two;
	two = tmp;
	*val_1 = one;
	*val_2 = two;
}

int			trait_line(data_t *p, t_ligne *trait, int val_x, int val_y)
{
	int		x;
	int		y;
	int		finish_x;
	int		finish_y;

	x = p->grille_x[trait->start_x];
	y = p->grille_y[trait->start_y];
	finish_x = p->grille_x[trait->start_x + val_x];
	finish_y = p->grille_y[trait->start_y + val_y];
	if (x > finish_x && val_x == -1)
		swap(&x, &finish_x);
	if (y > finish_y && val_y == -1)
		swap(&y, &finish_y);
	while (x <= finish_x && y <= finish_y)
	{
		mlx_pixel_put(p->mlx_ptr, p->mlx_win, x, y, trait->color);
		x = (trait->c == 'x') ? x + 1 : x;
		y = (trait->c == 'y') ? y + 1 : y;
	}
	return (1);
}

int			check_line(data_t *p, t_ligne *trait, int x, int y)
{
	if (trait->start_x + x < p->medium && trait->start_x + x >= 0 && trait->start_y + y < p->medium && trait->start_y + y >= 0)
	{
		trait->c = (y == 0) ? 'x' : 'y';
		if (p->mappage_pipe[trait->z][trait->j][trait->start_x + x][trait->start_y + y] > 0)
			trait_line(p, trait, x, y);
		return (1);
	}
	return (0);
}

int			chemin_point(data_t *p, t_ligne *trait)
{
	int		max;
	int		z;
	int		j;
	int		x;
	int		y;

	max = (trait->n_piece > 0) ? trait->n_piece : p->nb_of_box;
	max = (max > p->nb_of_box) ? p->nb_of_box : max;
	z = (trait->n_piece > 0) ? trait->n_piece - 2 : -1;
	while (++z < max)
	{
		j = -1;
		while (++j < p->infos->data[z].nb_of_link)
		{
			x = -1;
			while (++x < p->medium)
			{
				y = -1;
				while (++y < p->medium)
				{
					if (p->mappage_pipe[z][j][x][y] == 1)
					{
						if (x < p->medium && x >= 0 && y < p->medium && y >= 0)
						{
							trait->z = z;
							trait->j = j;
							trait->start_x = x;
							trait->start_y = y;
							check_line(p, trait, 1, 0);
							check_line(p, trait, -1, 0);
							check_line(p, trait, 0, 1);
							check_line(p, trait, 0, -1);
						}
					}
				}
			}
		}
	}
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
	if (x + i < p->medium && x + i >= 0 && y >= 0 && y < p->medium) // gauche
	{
		if (p->mappage_box[x + i][y] == 0)
			p->mappage_box[x + i][y] = val;
		i++;
	}
	if (x + j >= 0 && x + j < p->medium && y >= 0 && y < p->medium) // droite
	{
		if (p->mappage_box[x + j][y] == 0)
			p->mappage_box[x + j][y] = val;
		j--;
	}
	if (y + k < p->medium && y + k >= 0 && x >= 0 && x < p->medium) // bas
	{
		if (p->mappage_box[x][y + k] == 0)
			p->mappage_box[x][y + k] = val;
		k++;
	}
	if (y + l >= 0 && y + l < p->medium && x >= 0 && x < p->medium) // haut
	{
		if (p->mappage_box[x][y + l] == 0)
			p->mappage_box[x][y + l] = val;
		l--;
	}
	return (1);
}

int			val_link(data_t *p, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->nb_of_box)
	{
		j = -1;
		while (++j < p->infos->data[i].nb_of_link)
			if (p->mappage_pipe[i][j][x][y] > 0)
				return (p->mappage_pipe[i][j][x][y]);
	}
	return (0);
}

int			set_pos_around(data_t *p, int x, int y, int val)
{
	int		val_x;
	int		val_y;
	int		tmp;

	val_y = -1;
	val_x = -1;
	tmp = 0;
	if (y - 1 < p->medium && y - 1 >= 0 && x < p->medium && x >= 0)
	{
		tmp = p->mappage_box[x][y - 1];
		if (tmp <= val && (tmp > 0 || tmp == -p->infos->data[p->index_box_map].pipe[p->index_box_map_link]->n_piece - 1))
		{
			val_x = x;
			val_y = y - 1;
			val = tmp;
		}
	}
	if (y + 1 < p->medium && y + 1 >= 0 && x < p->medium && x >= 0)
	{
		tmp = p->mappage_box[x][y + 1];
		if (tmp <= val && (tmp > 0 || tmp == -p->infos->data[p->index_box_map].pipe[p->index_box_map_link]->n_piece - 1))
		{
			val_x = x;
			val_y = y + 1;
			val = tmp;
		}
	}
	if (y < p->medium && y >= 0 && x - 1 < p->medium && x - 1 >= 0)
	{
		tmp = p->mappage_box[x - 1][y];
		if (tmp <= val && (tmp > 0 || tmp == -p->infos->data[p->index_box_map].pipe[p->index_box_map_link]->n_piece - 1))
		{
			val_x = x - 1;
			val_y = y;
			val = tmp;
		}
	}
	if (y < p->medium && y >= 0 && x + 1 < p->medium && x + 1 >= 0)
	{
		tmp = p->mappage_box[x + 1][y];
		if (tmp <= val && (tmp > 0 || tmp == -p->infos->data[p->index_box_map].pipe[p->index_box_map_link]->n_piece - 1))
		{
			val_x = x + 1;
			val_y = y;
			val = tmp;
		}
	}
	if (val_x >= 0 && val_y >= 0 && val_x < p->medium && val_y < p->medium)
		p->mappage_pipe[p->index_box_map][p->index_box_map_link][val_x][val_y] = 1;
	if (val_x >= 0 && val_y >= 0 && val_x < p->medium && val_y < p->medium)
			return (set_pos_around(p, val_x, val_y, val));
	else
		return (val);
}

int			erase_chaleur_box(data_t *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p->medium)
	{
		j = 0;
		while (j < p->medium)
		{
			if (p->mappage_box[i][j] > 0)
				p->mappage_box[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int			mappage_box(data_t *p)
{
	int		i;

	i = -1;
	if (!(p->mappage_box = (int **)malloc(sizeof(int *) * p->medium)))
		return (0);
	while (++i < p->medium)
	{
		if (!(p->mappage_box[i] = (int *)ft_memalloc(sizeof(int) * p->medium)))
			return (0);
	}
	return (1);
}

int			mappage_pipe(data_t *p)
{
	int		nb_2;
	int		nb;
	int		i;

	nb = -1;
	if (!(p->mappage_pipe = (int ****)malloc(sizeof(int **) * p->nb_of_box)))
		return (0);
	while (++nb < p->nb_of_box)
	{
		if (!(p->mappage_pipe[nb] = (int ***)ft_memalloc(sizeof(int *) * p->infos->data[nb].nb_of_link)))
			return (0);
		nb_2 = -1;
		while (++nb_2 < p->infos->data[nb].nb_of_link)
		{
			if (!(p->mappage_pipe[nb][nb_2] = (int **)ft_memalloc(sizeof(int *) * p->medium)))
				return (0);
			i = -1;
			while (++i < p->medium)
			{
				if (!(p->mappage_pipe[nb][nb_2][i] = (int *)ft_memalloc(sizeof(int) * p->medium)))
					return (0);
			}
		}
	}
	return (0);
}

int			fct_mappage_pipe(data_t *p)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	while (++i < p->infos->nb_of_box)
	{
		j = -1;
		while (++j < p->infos->data[i].nb_of_link)
		{
			k = -1;
			while (++k <= p->medium)
			{
				l = -1;
				while (++l <= p->medium)
				{
					if (p->infos->data[i].n_piece < p->infos->data[i].pipe[j]->n_piece)
						if (p->infos->data[i].pipe[j]->coor_x == l && p->infos->data[i].pipe[j]->coor_y == k)
						{
							p->index_of_box_dest = p->mappage_box[l][k];
							mappage(p, l, k, 1);
							check_position_around(p, 0, 0); // haut gauche
							check_position_around(p, 0, p->medium); // bas gauche
							check_position_around(p, p->medium, 0); // haut droit
							check_position_around(p, p->medium, p->medium); //bas droit
							p->index_box_map = i;
							p->mappage_pipe[i][(p->index_box_map_link = j)][p->infos->data[i].coor_x][p->infos->data[i].coor_y] = 3;
							set_pos_around(p, p->infos->data[i].coor_x, p->infos->data[i].coor_y, p->medium * p->medium);
							erase_chaleur_box(p);
						}
				}
			}
		}
	}
	return (1);
}

int			fct_put_pixel(data_t *p, t_graphe *graphe)
{
	int		i;
	int		j;

	(void)graphe;
	while (p->infos->data[p->index_of_box].name_box)
	{
		p->centre_y = p->grille_y[p->infos->data[p->index_of_box].coor_y] - (p->largeur / 2); // centre du carre + sur une des grille de la fenetre
		p->centre_x = p->grille_x[p->infos->data[p->index_of_box].coor_x] - (p->longueur / 2); // centre du carre + sur une des grille de la fenetre
		i = p->centre_x;
		while (i < p->centre_x + p->longueur)
		{
			j = p->centre_y;
			while (j < p->centre_y + p->largeur)
			{
				if (i != p->centre_x && i != p->centre_x + p->longueur - 1
					&& j != p->centre_y && j != p->centre_y + p->largeur - 1)
				{
					if (p->infos->data[p->index_of_box].commands == 1 || p->infos->data[p->index_of_box].commands == 2)
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, (p->infos->data[p->index_of_box].commands == 1) ? p->color_start : p->color_end);
					// else if (used)
					//		mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_box_used);
					else // if (not used)
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_interieur);
				}
				if (i == p->centre_x || i == p->centre_x + p->longueur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_x);			
				if (j == p->centre_y || j == p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_y);
				j++;
			}
			i++;
		}
		p->index_of_box++;
	}
	return (1);
}

int				init_mappage_box(data_t *p)
{
	int			i;
	int			j;

	i = -1;
	j = -1;
	while (++i < p->infos->nb_of_box)
		p->mappage_box[p->infos->data[i].coor_x][p->infos->data[i].coor_y] = j--;
	return (1);
}

int				init_struct_trait(data_t *p, t_ligne *trait)
{
	trait->p = p;
	trait->color = p->color;
	trait->z = 0;
	trait->start_x = 0;
	trait->start_y = 0;
	trait->finish_x = 0;
	trait->finish_y = 0;
	return (1);
}

int				fct_main(data_t *p, t_ligne *trait)
{
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 54461616;
	p->longueur = p->longueur_win / (p->medium * 1.2);
	p->largeur = p->largeur_win / (p->medium * 1.2);
	mappage_box(p);
	mappage_pipe(p);
	init_mappage_box(p);
	fct_mappage_pipe(p);
	init_struct_trait(p, trait);
	chemin_point(p, trait);
	fct_put_pixel(p, p->graphe);
	p->index_of_box = 0;
	return (1);
}

t_graphe		*new_graphe(t_lem *lem, t_graphe *prev)
{
	t_graphe	*tmp;

	tmp = NULL;
	if (!lem)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_graphe))))
		return (NULL);
	tmp->lem = lem;
	tmp->next = NULL;
	tmp->prev = (prev) ? prev : NULL;
	return (tmp);
}

t_graphe		*add_graphe(t_graphe *old, t_lem *lem)
{
	t_graphe	*tmp;

	if (old)
	{
		tmp = old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_graphe(lem, tmp);
		return (old);
	}
	else
		return (new_graphe(lem, NULL));
}

t_lem		*new_lem(t_data *line, int nb)
{
	t_lem	*tmp;

	tmp = NULL;
	if (!line)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_lem))))
		return (NULL);
	tmp->data = line;
	tmp->lem = nb;
	tmp->color_ants = 0;
	tmp->next = NULL;
	return (tmp);
}

t_lem		*add_lem(t_lem *lem, t_data *line, int nb)
{
	t_lem	*tmp;

	if (lem)
	{
		tmp = lem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lem(line, nb);
		return (lem);
	}
	else
		return (new_lem(line, nb));
}

t_graphe		*parsing_ants_file(t_file *file, t_infos *infos)
{
	t_graphe	*step;
	t_lem		*lem;
	char		**tab;
	char		**box;
	int		i;
	int		j;

	(void)infos;
	step = NULL;
	while (file)
	{
		if (file->line && file->line[0] == 'L')
		{
			if (!(tab = ft_strsplit(file->line, ' ')))
				return (NULL);
			i = 0;
			lem = NULL;
			while (tab[i])
			{
				if (!(box = ft_strsplit(tab[i++], '-')))
					return (NULL);
				if (!box[0] || !box[1])
					return (NULL);
					j = -1;
				while (infos->data[++j].name_box)
					if (ft_strcmp(infos->data[j].name_box, box[1]) == 0)
						break ;
				lem = add_lem(lem, &infos->data[j], ft_atoi(box[0] + 1));
			}
			step = add_graphe(step, lem);
		}
		file = file->next;
	}
	return (step);
}

int			key_hook(int keycode, data_t *p)
{
	if (keycode == 36)
		printf("ENTREE\n");
	else if (keycode == 53)
	{
		printf("ESC\n");
		exit (0);
	}
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
	else if (keycode == 18)
	{
		// p->trait->n_piece += 1;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 19)
	{
		// p->trait->n_piece += 2;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 20)
	{
		// p->trait->n_piece += 3;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 21)
	{
		// p->trait->n_piece += 4;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 23)
	{
		// p->trait->n_piece += 5;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 22)
	{
		// p->trait->n_piece += 6;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 26)
	{
		// p->trait->n_piece += 7;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 28)
	{
		// p->trait->n_piece += 8;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 25)
	{
		// p->trait->n_piece += 9;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 29)
	{
		p->trait->n_piece = 0;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 27)
	{
		p->trait->n_piece = (p->trait->n_piece >= 0) ? p->trait->n_piece - 1 : 0;
		p->color = 256 * 256 * 256;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else if (keycode == 24)
	{
		p->trait->n_piece++;
		p->color = 5000000;
		printf("trait.n_piece = %d\n", p->trait->n_piece); 
	}
	else
		printf("%d\n", keycode);
	fct_main(p, p->trait);
	return (0);
}

t_infos		init_val_bonus(void)
{
	t_infos	infos;

	infos.file = NULL;
	infos.data = NULL;
	infos.nb_of_fourmis = 0;
	infos.nb_of_box = 0;
	infos.nb_of_pipe = 0;
	infos.nb_f_left = 0;
	infos.nb_path_max = 0;
	infos.t_p = NULL;
	infos.t_p_c = NULL;
	infos.first_ant = NULL;
	infos.l = NULL;
	infos.jpp = 0;
	return (infos);
}

int			ants_move(char **tab)
{
	int		i;
	char	**tmp;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
	{
		if (tab[i][0] != 'L')
		{
			free_tab_str(&tab);
			return (0);
		}
		if (!(tmp = ft_strsplit(tab[i], '-')))
		{
			free_tab_str(&tab);
			return (0);
		}
		if (!tmp[0] || !tmp[1] || tmp[2])
		{
			free_tab_str(&tab);
			free_tab_str(&tmp);
			return (0);
		}
		free_tab_str(&tmp);
	}
	free_tab_str(&tab);
	return (i);
}

int			norm_free_tab(char ***tab, int	retourn)
{
	free_tab_str(tab);
	return (retourn);
}

int			parsing_ants(t_infos *infos, char **line)
{
	int		ret;

	if (*line)
		free_line(line);
	if (!(get_next_line(0, line)))
		return (0);
	if (!(ants_move((ft_strsplit(*line, ' ')))))
		return (1);
	if (!(infos->file = add_file(infos->file, *line)))
		return (0);
	while ((ret = get_next_line(0, line)) > 0)
	{
		if (!(ants_move((ft_strsplit(*line, ' ')))))
			return (0);
		if (!(infos->file = add_file(infos->file, *line)))
			return (0);
	}
	return ((ret == -1) ? 0 : 1);
}

t_infos		get_file_bonus(void)
{
	t_infos	infos;
	int		etapes;
	char	*line;
	int		ret;

	line = NULL;
	etapes = 0;
	infos = init_val_bonus();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(parsing_line(&infos, line, etapes)))
			if (!(parsing_ants(&infos, &line)))
			{
				free_line(&line);
				get_next_line(0, NULL);
				break ;
			}
		if (etapes == 0)
		{
			infos.nb_of_fourmis = ft_atoi(line);
			etapes++;
		}
		if (!(infos.file = add_file(infos.file, line)))
			return (infos);
	}
	return (infos);
}

int			check_file_bonus(t_infos *infos, int commande, int check_order)
{
	t_file	*head;

	head = infos->file;
	if (!(skip_line_fourmi(infos)))
		return (0);
	while (infos->file)
	{
		if (commantaire(infos) && skip_commentaire(infos, head))
			return (1);
		check_order = (ft_strcmp(infos->file->line, "##start") == 0
		|| ft_strcmp(infos->file->line, "##end") == 0) ? 0 : check_order;
		commande = init_command(infos, commande);
		if (!check_order && commande && infos->file->next)
			infos->file = infos->file->next;
		if (infos->file->line && infos->file->line[0] == '#'
			&& infos->file->line[1] == '#' && commande == 0)
			return (norm_check_file(infos, head, 0));
		if (commantaire(infos) && skip_commentaire(infos, head))
			return (0);
		if (infos->file->line && infos->file->line[0] == 'L')
			return (norm_check_file(infos, head, 1));
		if (!(check_order = step_check(infos, head, check_order, commande)))
			return (0);
		infos->file = infos->file->next;
	}
	return (retour_check_file(infos, head, 1));
}


data_t		init_p(t_infos *infos, t_ligne *trait, t_graphe *graphe)
{
	data_t	p;

	p.mlx_ptr = mlx_init();
	p.infos = infos;
	p.graphe = graphe;
	p.index_of_box = 0;
	p.color = 5000000;
	p.color_start = 120 * 256 * 256;
	p.color_end = 60 * 120 * 120;
	p.color_box_used = 60 * 70 * 60;
	p.trait = trait;
	p.trait->n_piece = 0;
	p.nb_of_box = infos->nb_of_box;
	p.maximum_x = val_max_coor(infos->data, 'x');
	p.maximum_y = val_max_coor(infos->data, 'y');
	p.maximum_x = (!(p.maximum_x % p.maximum_x)) ? p.maximum_x : p.maximum_x - 1;
	p.maximum_y = (!(p.maximum_y % p.maximum_y)) ? p.maximum_y : p.maximum_y - 1;
	p.medium = (p.maximum_x > p.maximum_y) ? p.maximum_x + 2: p.maximum_y + 2;
	if (p.medium > 200)
	{
		perror("Coordinated Too High ");
		exit (0);
	}
	p.longueur_win = ((p.medium - 2) >= 25) ? 1024 : 512;
	p.largeur_win = ((p.medium - 2) >= 25) ? 1024 : 512;
	init_tab_x_y(&p);
	init_grille_x_y(&p);
	p.mlx_win = mlx_new_window(p.mlx_ptr, p.longueur_win, p.largeur_win, "mlx 42");
	return (p);
}

void		ft_put_graphe(t_graphe *graphe)
{
	if (!graphe)
		return ;
	while (graphe)
	{
		while (graphe->lem)
		{
			printf("%d-%s", graphe->lem->lem , graphe->lem->data->name_box);
			if (graphe->lem->next)
				printf("-->");
			else
				printf("\n");
			graphe->lem = graphe->lem->next;
		}
		graphe = graphe->next;
	}
}

int     main(int argc, char **argv)
{
	t_infos	infos;
	data_t	p;
	t_ligne	trait;
	t_graphe *graphe;

	(void)argc;
	(void)argv;
	infos = get_file_bonus();
	if (!infos.file)
		erase_infos(&infos);
	if (!(init_data(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(check_file_bonus(&infos, 0, 0)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(check_commandes(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(add_pipe(&infos, infos.file)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(logical_infos_box(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!infos.file || !infos.data)
	{
		perror("Wrong Data ");
		return (0);
	}
	graphe = parsing_ants_file(infos.file, &infos);
	ft_put_graphe(graphe);
	
	p = init_p(&infos, &trait, graphe);
	key_hook(0, &p);
	mlx_key_hook(p.mlx_win, key_hook, &p);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}