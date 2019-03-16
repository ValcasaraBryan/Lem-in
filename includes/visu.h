/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:36:36 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:36:39 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "lem_in.h"
# include <mlx.h>

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

typedef struct		s_pos
{
	int				y;
	int				x;
	int				z;
	int				color;
}					t_pos;

typedef struct		s_line
{
	int				error;
	int				offset;
	int				sign_y;
	int				sign_x;
	int				delta_y;
	int				delta_x;
}					t_line;

typedef struct		s_data_p
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				longueur_win;
	int				largeur_win;
	int				*grille_x;
	int				*grille_y;
	int				centre_x;
	int				centre_y;
	int				longueur;
	int				largeur;
	int				medium;
	int				maximum_x;
	int				maximum_y;
	t_infos			*infos;
	int				index_of_box;
	t_graphe		*graphe;
	int				nb_graphe;
	int				n_lem;
	int				color_start;
	int				color_end;
	int				color_carre_x;
	int				color_carre_y;
	int				color_interieur;
}					t_data_p;

/*
**          parsing_ants_file.c
*/
void				fcnt_rand(int *color, int nb);
int					num_data(t_infos *infos, char *str);
t_graphe			*parsing_ants_file(t_file *file, t_infos *infos);
/*
**          init_p.c
*/
int					val_max_coor(t_data *data, char c);
void				coordinates_too_high(t_data_p *p);
t_data_p			init_p(t_infos *infos, t_graphe *graphe);
/*
**          check_file_bonus.c
*/
int					check_file_bonus(t_infos *infos, t_file *head,
					int commande, int check_order);
/*
**          get_file_bonus.c
*/
t_infos				init_val_bonus(void);
int					parsing_ants(t_infos *infos, char **line);
t_infos				get_file_bonus(void);
/*
**          ants_move.c
*/
int					ants_move(char **tab);
/*
**          affichage_bonus.c
*/
void				print_all_link(t_data_p *env);
/*
**          list_graphe.c
*/
t_graphe			*new_graphe(t_lem *lem, t_graphe *prev, int nb);
t_graphe			*add_graphe(t_graphe *old, t_lem *lem, int nb);
t_lem				*new_lem(t_data *line, int nb, t_lem *prev, int color);
t_lem				*add_lem(t_lem *lem, t_data *line, int nb, int color);
/*
**          grille_win.c
*/
int					init_grille_x_y(t_data_p *p);
int					init_tab_x_y(t_data_p *p);
/*
**          print_link.c
*/
int					check_next(t_data_p *p, t_graphe *graphe);
void				reset_graphe_lem(t_data_p *env);
void				print_no_start(t_data_p *env);
int					check_start(t_data_p *p);
void				print_start(t_data_p *env);
/*
**          draw_line.c
*/
int					absolute_value(int nb);
void				draw_line(t_pos a, t_pos b, t_data_p *env, int color);
void				print(t_data_p *env, int i);
/*
**          put_square.c
*/
int					check_box(t_data_p *p, int val);
int					check_box_color(t_data_p *p, int val);
int					fct_put_pixel(t_data_p *p);
/*
**          utils_bonus.c
*/
int					check_end(t_data_p *p);
void				print_start_to_end(t_data_p *p);
int					fct_main(t_data_p *p);
int					norm_free_tab(char ***tab, int	retourn);
/*
**          fct_key_hook.c
*/
int					erase_all(t_data_p *p, int val);
void				send_usage(void);
int					key_hook(int keycode, t_data_p *p);
/*
**          liberation_bonus.c
*/
void				erase_graphe(t_data_p *p);
/*
**          main_bonus.c
*/
void				norm_main(t_infos *infos);
int					text_error(void);
#endif
