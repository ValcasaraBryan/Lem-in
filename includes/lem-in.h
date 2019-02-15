/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:08:40 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/21 18:08:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

/*
**			num_a = numero de la fourmi
**			path_a = chemin aue suit la fourmi
**			indx = index du path auquel la fourmi se trouve
*/

typedef struct s_ants
{
	int num_a;
	int path_u;
	int indx;
	struct s_ants *next;
}				t_ants;

typedef struct          s_t
{
	int 				i;
	int 				j;
	int 				r;
	int 				n;
}                       t_t;

typedef struct          s_file
{
	char                *line;
	struct s_file       *next;
}                       t_file;

typedef struct          s_data
{
	char                *name_box;
	int                 n_piece;
	int                 nb_of_link;
	int                 commands;
	int                 coor_x;
	int                 coor_y;
	int					full;
	struct s_data       **pipe;
}                       t_data;
/*
**			t_p = tableau qui contient tous les chemins qui existent
**			first_ant = liste des fourmis
**			t_p_c = tab_path_compatibles, contient les index des chemins 
**					compatibles (pour t_p_c[3], contient les index a 
**					reporter dans t_p de 4 chemins compatibles)
**			nb_path_max = nombre de chemins maximum
*/
typedef struct          s_infos
{
	int                 nb_of_fourmis;
	int					nb_f_left;
	int                 nb_of_box;
	int                 nb_of_pipe;
	int					nb_path_max;
	t_file              *file;
	t_data              *data;
	int					**tab_path;
	t_ants				*first_ant;
	int 				**tab_paths_compatibles;
}                       t_infos;

/*
**			affichage.c
*/
void                    ft_put_list(t_file *file);
void                    ft_put_data(t_infos *infos);
/*
**			algo.c
*/
int                     ft_algo(t_infos *infos);
int						ft_length_path(int *tab, int n);
void					ft_free_tab_int(int **tab, int height);
int						ft_min_int(int a, int b);
/*
**          choose_path.c
*/

int						ft_choose_paths(t_infos *infos);
/*
**          resolution.c
*/

int		ft_resolve(t_infos *infos, int nbr_group_path);

/*
**          list_utils.c
*/
void ft_lstdel_all(t_ants **fa);
void	ft_lstdel_start(t_ants **fa);
int ft_lstadd_end(t_ants **fa, int num_ant, int path, int room);
void	ft_lstadd_start(t_ants **fa, int num_ant, int path, int room);
void ft_new_lst(t_ants **fa);
t_ants *ft_lstdel_num_ant(t_ants **fa, int ant_to_del);
/*
**          check_commandes.c
*/
int			            check_commandes(t_infos *infos);
int			            skip_line_fourmi(t_infos *infos);
int			            init_command(t_infos *infos, int commande);
int			            norm_check_file(t_infos *infos, t_file *head, int returne);
/*
**          check_file.c
*/
int			            retour_check_file(t_infos *infos, t_file *head, int retour);
int			            skip_commentaire(t_infos *infos, t_file *head, int retour);
int			            init_check_order(t_infos *infos, int check_order);
int			            step_check(t_infos *infos, t_file *head, int check_order, int commande);
int			            check_file(t_infos *infos, int commande, int check_order);
/*
**          get_file.c
*/
t_infos		            get_file(void);
/*
**          init_data.c
*/
int			            init_data(t_infos *infos);
/*
**          liberation.c
*/
void		            erase_infos(t_infos *infos);
void		            erase_data(t_infos *infos);
/*
**          list_chain.c
*/
t_file                  *new_file(char *line);
t_file                  *add_file(t_file *file, char *line);
/*
**          logical_infos_box.c
*/
int			            logical_infos_pipe(t_data data);
int			            logical_infos_box(t_infos *infos);
/*
**          parsing.c
*/
int                     parsing_line(t_infos *infos, char *line, int etapes);
int                     parsing_pipe_line(t_infos *infos, char ***tab);
int                     check_nb_char(char *str, int nb, char c);
/*
**          valeur_data.c
*/
int			            nb_of_link(t_infos *infos, char *str);
int			            malloc_pipe(t_infos *infos, int i, int len);
int			            valeur_data(t_infos *infos, int commande);
/*
**          valeur_pipe.c
*/
int			            norm_valeur_pipe(char ***tmp, int returne);
int			            check_pipe_double(t_infos *infos, char ***tab);
void		            add_link(t_infos *infos, int index_data, int index_pipe);
int			            valeur_pipe(t_infos *infos);
#endif
