#include "lem-in.h"
// #include "/usr/X11/include/mlx.h"
#include <mlx.h>

typedef struct		s_lem
{
	t_data			*data;
	int				lem;
	int				color_ants;
	struct s_lem	*next;
	struct s_lem	*prev;
}					t_lem;

typedef struct		s_graphe
{
	t_lem			*lem;
	int				nb_of_graphe;
	struct s_graphe	*next;
	struct s_graphe	*prev;
}					t_graphe;

typedef struct	s_pos
{
	int			y;
	int			x;
	int			z;
	int			color;
}				t_pos;

typedef struct	s_line
{
	int			error;
	int			offset;
	int			sign_y;
	int			sign_x;
	int			delta_y;
	int			delta_x;
}				t_line;

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
	int				nb_graphe;
	int				n_lem;
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

void		ft_put_graphe(t_graphe *p)
{
	t_graphe *graphe;
	int		i;

	if (!p)
		return ;
	i = -1;
	graphe = p;
	while (graphe)
	{
		while (graphe->lem)
		{
			printf("L%d-%s", graphe->lem->lem , graphe->lem->data->name_box);
			if (graphe->lem->next)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
			if (!graphe->lem->next)
				break ;
			graphe->lem = graphe->lem->next;
		}
		while (graphe->lem->prev)
			graphe->lem = graphe->lem->prev;
		if (!graphe->next)
			break ;
		graphe = graphe->next;
	}
	printf("\n");
	while (graphe->prev)
		graphe = graphe->prev;
}

int				check_box(data_t *p, int val)
{
	t_lem	*tmp;
	int			i;

	i = -1;
	tmp = p->graphe->lem;
	while (tmp)
	{
			if (tmp->data->n_piece == p->infos->data[val].n_piece)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				check_box_color(data_t *p, int val)
{
	t_lem	*tmp;
	int			i;

	i = -1;
	tmp = p->graphe->lem;
	if (p->nb_graphe < 0)
		return (0);
	while (tmp)
	{
			if (tmp->data->n_piece == p->infos->data[val].n_piece)
				return (tmp->color_ants);
		tmp = tmp->next;
	}
	return (0);
}

int			fct_put_pixel(data_t *p)
{
	int		i;
	int		j;

	while (p->graphe->lem)
	{
		if (!p->graphe->lem->next)
			break ;
		p->graphe->lem = p->graphe->lem->next;
	}
	while (p->graphe->lem->prev)
		p->graphe->lem = p->graphe->lem->prev;
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
					else if (check_box(p, p->index_of_box))
						mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, check_box_color(p, p->index_of_box));
					else
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

int		absolute_value(int nb)
{
	return (nb < 0 ? -nb : nb);
}

static t_line	setup_params(t_pos a, t_pos b)
{
	t_line	params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = absolute_value(b.y - a.y);
	params.delta_x = absolute_value(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}

void			draw_line(t_pos a, t_pos b, data_t *env)
{
	t_line	params;
	t_pos	p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		mlx_pixel_put(env->mlx_ptr, env->mlx_win, p.x, p.y, env->graphe->lem->color_ants);
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	mlx_pixel_put(env->mlx_ptr, env->mlx_win, p.x, p.y, env->graphe->lem->color_ants);
}

int			no_start(data_t *p, int start)
{
	int		i;
	// printf("%d-%s before %d\n", p->graphe->lem->lem, p->graphe->lem->data->name_box, start);
	i = 0;
	while (p->graphe->lem->next)
	{
		if (p->graphe->lem->lem < start)
			return (1);
		p->graphe->lem = p->graphe->lem->next;
		i++;
	}
	return (0);
}

int			check_start(data_t *p, int start)
{
	int		j;
	int		i;

	i = -1;
	while (++i < start)
		if (p->graphe->lem->next)
			p->graphe->lem = p->graphe->lem->next;
	j = -1;
	if (p->n_lem < p->graphe->lem->lem)
		p->n_lem = p->graphe->lem->lem;
	if (i < p->n_lem)
		while (++j < p->graphe->lem->data->nb_of_link)
			if (p->graphe->lem->data->pipe[j]->commands == 1)
				return (j);
	return (-1);
}

int			check_skip_start(data_t *p)
{
	int		i;

	while (p->graphe->lem)
	{
		i = -1;
		while (++i < p->graphe->lem->data->nb_of_link)
		{
			if (p->graphe->lem->data->pipe[i]->commands == 1)
				return (0);
		}
		if (p->graphe->lem->next)
			p->graphe->lem = p->graphe->lem->next;
		else
			break ;
	}
	while (p->graphe->lem->prev)
		p->graphe->lem = p->graphe->lem->prev;
	return (1);
}

void		print_start(data_t *env)
{
	t_pos	a;
	t_pos	b;
	int		i;

	while (env->graphe->next)
	{
		if (env->graphe->nb_of_graphe - 1 == env->nb_graphe)
			break ;
		env->graphe = env->graphe->next;
	}
	i = env->n_lem;
	while (1)
	{
		i = check_start(env, i);
		if (i == -1)
			break ;
		a.x = env->grille_x[env->graphe->lem->data->pipe[i]->coor_x];
		a.y = env->grille_y[env->graphe->lem->data->pipe[i]->coor_y];
		b.x = env->grille_x[env->graphe->lem->data->coor_x];
		b.y = env->grille_y[env->graphe->lem->data->coor_y];
		draw_line(a, b, env);
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	while (env->graphe->lem->prev)
		env->graphe->lem = env->graphe->lem->prev;
	while (env->graphe->prev)
	{
		if (env->graphe->nb_of_graphe == env->nb_graphe)
			break ;
		env->graphe = env->graphe->prev;
	}
}

void		print_line(data_t *env)
{
	t_pos	a;
	t_pos	b;
	int		i;

	while (env->graphe->next)
	{
		if (env->graphe->nb_of_graphe - 1 == env->nb_graphe)
			break ;
		env->graphe = env->graphe->next;
	}
	i = -1;
	while (1)
	{
		if (!(check_skip_start(env)))
		{
			if (env->graphe->lem->next)
				env->graphe->lem = env->graphe->lem->next;
			else
				break ;
		}
		// i = check_next_step(env, env->graphe->lem);
		printf("%d-%s == %d\n", env->graphe->lem->lem, env->graphe->lem->data->name_box, i);
		if (i == -1)
			break ;
		a.x = env->grille_x[env->graphe->lem->data->pipe[i]->coor_x];
		a.y = env->grille_y[env->graphe->lem->data->pipe[i]->coor_y];
		b.x = env->grille_x[env->graphe->lem->data->coor_x];
		b.y = env->grille_y[env->graphe->lem->data->coor_y];
		draw_line(a, b, env);
		if (env->graphe->lem->next)
			env->graphe->lem = env->graphe->lem->next;
		else
			break ;
	}
	while (env->graphe->lem->prev)
		env->graphe->lem = env->graphe->lem->prev;
	while (env->graphe->prev)
	{
		if (env->graphe->nb_of_graphe == env->nb_graphe)
			break ;
		env->graphe = env->graphe->prev;
	}
}

int				fct_main(data_t *p)
{
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 0;
	p->longueur = p->longueur_win / (p->medium * 1.2);
	p->largeur = p->largeur_win / (p->medium * 1.2);
	print_start(p);
	print_line(p);
	fct_put_pixel(p);
	p->index_of_box = 0;
	return (1);
}

t_graphe		*new_graphe(t_lem *lem, t_graphe *prev, int nb)
{
	t_graphe	*tmp;

	tmp = NULL;
	if (!lem)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_graphe))))
		return (NULL);
	tmp->lem = lem;
	tmp->nb_of_graphe = nb;
	tmp->next = NULL;
	tmp->prev = prev;
	return (tmp);
}

t_graphe		*add_graphe(t_graphe *old, t_lem *lem, int nb)
{
	t_graphe	*tmp;

	if (old)
	{
		tmp = old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_graphe(lem, tmp, nb);
		return (old);
	}
	else
		return (new_graphe(lem, NULL, nb));
}

t_lem		*new_lem(t_data *line, int nb, t_lem *prev, int color)
{
	t_lem	*tmp;

	tmp = NULL;
	if (!line)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_lem))))
		return (NULL);
	tmp->data = line;
	tmp->lem = nb;
	tmp->color_ants = color;
	tmp->next = NULL;
	tmp->prev = prev;
	return (tmp);
}

t_lem		*add_lem(t_lem *lem, t_data *line, int nb, int color)
{
	t_lem	*tmp;

	if (lem)
	{
		tmp = lem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lem(line, nb, tmp, color);
		return (lem);
	}
	else
		return (new_lem(line, nb, NULL, color));
}

void			fcnt_rand(int *color, int nb)
{
	int			i;
	
	i = -1;
	srand(time(NULL));
	while (++i < nb)
		color[i] = rand();
}

t_graphe		*parsing_ants_file(t_file *file, t_infos *infos)
{
	t_graphe	*step;
	t_lem		*lem;
	char		**tab;
	char		**box;
	int			n_lem;
	int			color[infos->nb_of_fourmis + 1];
	int		i;
	int		j;
	int		x;

	(void)infos;
	step = NULL;
	fcnt_rand(color, infos->nb_of_fourmis);
	x = 0;
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
				n_lem = ft_atoi(box[0] + 1);
				lem = add_lem(lem, &infos->data[j], n_lem, color[n_lem - 1]);
			}
			step = add_graphe(step, lem, x++);
		}
		file = file->next;
	}
	return (step);
}

void		reset_win(data_t *p)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->longueur_win)
	{
		j = -1;
		while (++j < p->largeur_win)
			mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, 0);
	}
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
	else if (keycode == 45)
	{
		if (p->graphe->next)
			p->nb_graphe++;
		while (p->graphe->lem->prev)
			p->graphe->lem = p->graphe->lem->prev;
		if (p->graphe->next && p->nb_graphe > 0)
			p->graphe = p->graphe->next;
		reset_win(p);
	}
	else if (keycode == 11)
	{
		if (p->nb_graphe >= 0) 
			p->nb_graphe--;
		while (p->graphe->lem->prev)
			p->graphe->lem = p->graphe->lem->prev;
		if (p->graphe->prev)
			p->graphe = p->graphe->prev;
		reset_win(p);
	}
	else if (keycode == 49)
	{
		p->nb_graphe = -1;
		while (p->graphe->lem->prev)
			p->graphe->lem = p->graphe->lem->prev;
		while (p->graphe->prev)
			p->graphe = p->graphe->prev;
		p->n_lem = 0;
		reset_win(p);
	}
	else if (keycode == 18)
	{
		// p->trait->n_piece += 1;
	}
	else if (keycode == 19)
	{
		// p->trait->n_piece += 2;
	}
	else if (keycode == 20)
	{
		// p->trait->n_piece += 3;
	}
	else if (keycode == 21)
	{
		// p->trait->n_piece += 4;
	}
	else if (keycode == 23)
	{
		// p->trait->n_piece += 5;
	}
	else if (keycode == 22)
	{
		// p->trait->n_piece += 6;
	}
	else if (keycode == 26)
	{
		// p->trait->n_piece += 7;
	}
	else if (keycode == 28)
	{
		// p->trait->n_piece += 8;
	}
	else if (keycode == 25)
	{
		// p->trait->n_piece += 9;
	}
	else if (keycode == 29)
	{
	}
	else if (keycode == 27)
	{
		p->color = 256 * 256 * 256;
	}
	else if (keycode == 24)
	{
		p->color = 5000000;
	}
	else if (keycode != 0)
		printf("%d\n", keycode);
	fct_main(p);
	ft_put_graphe(p->graphe);
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


data_t		init_p(t_infos *infos, t_graphe *graphe)
{
	data_t	p;

	p.mlx_ptr = mlx_init();
	p.infos = infos;
	p.graphe = graphe;
	p.index_of_box = 0;
	p.nb_graphe = -1;
	p.n_lem = 0;
	p.color = 5000000;
	p.color_start = 120 * 256 * 256;
	p.color_end = 60 * 120 * 120;
	p.color_box_used = 60 * 70 * 60;
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

int     main(int argc, char **argv)
{
	t_infos	infos;
	data_t	p;
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
	p = init_p(&infos, graphe);
	// ft_put_list(infos.file);
	key_hook(0, &p);
	mlx_hook(p.mlx_win, 2, 0, key_hook, &p);
	mlx_do_key_autorepeaton(p.mlx_ptr);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}