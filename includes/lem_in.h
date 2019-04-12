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
# include "./algo.h"
# include "./weights.h"

/*
**          num_a = numero de la fourmi
**          path_u = chemin que suit la fourmi
**          indx = index du path auquel la fourmi se trouve
*/

typedef struct			s_ants
{
	int					num_a;
	int 				path_u;
	int 				indx;
	struct s_ants		*next;
}						t_ants;

typedef struct			s_graph
{
	int					*path;
	int					c_r;
	int 				climbe;
	struct s_graph		*next;
}						t_graph;
/*
**          utile dans ft_resolution
*/
typedef struct			s_r
{
	int					nb_turn_max;
	int					num_g;
}						t_r;

typedef struct			s_file
{
	char				*line;
	struct s_file		*next;
}						t_file;

typedef struct			s_path_comp
{
	int 				npc;
	int 				**tpc;
	struct s_path_comp	*next;
}						t_path_comp;

typedef struct			s_data
{
	char				*name_box;
	int					n_piece;
	int					nb_of_link;
	int					commands;
	int					coor_x;
	int					coor_y;
	int					full;
	struct s_data		**pipe;
	int					*p_state;
	int					weight;
}						t_data;
/*
**          t_p = tableau qui contient tous les chemins qui existent
**          first_ant = liste des fourmis
**          t_p_c = tab_path_compatibles, contient les index des chemins
**                  compatibles (pour t_p_c[3], contient les index a
**                  reporter dans t_p de 4 chemins compatibles)
**          nb_path_max = nombre de chemins maximum
**			l = premier element de la liste des chemis qui existent
*/
typedef struct			s_infos
{
	int					nb_of_fourmis;
	int					nb_f_left;
	int					nb_of_box;
	int					nb_of_pipe;
	int					nb_path_max;
	t_file				*file;
	t_data				*data;
	int					**t_p;
	int 				**tp_final;
	int 				tp_final_capacity;
	int 				**t_p_c;
	t_ants				*first_ant;
	t_graph				*l;
	int					ind_start;
	int					ind_end;
	int					r;
	int 				nb_group_path;
}						t_infos;
/*
**          PARTIE PARSING
**          affichage.c
*/
void					ft_put_list(t_file *file);
/*
**          check_commandes.c
*/
int						check_commandes(t_infos *infos);
int						skip_line_fourmi(t_infos *infos);
int						commantaire(t_infos *infos);
int						init_command(t_infos *infos, int commande);
int						norm_check_file(t_infos *infos, t_file *head,
						int returne);
/*
**          check_file.c
*/
int						skip_commentaire(t_infos *infos, t_file *head);
int						init_check_order(t_infos *infos, int check_order);
int						step_check(t_infos *infos, t_file *head,
						int check_order, int commande);
int						check_file(t_infos *infos, int commande,
						int check_order);
/*
**          get_file.c
*/
t_infos					get_file(void);
/*
**          init_data.c
*/
int						init_data(t_infos *infos);
/*
**          liberation.c
*/
void					erase_infos(t_infos *infos);
void					erase_data(t_infos *infos);
/*
**          list_chain.c
*/
t_file					*new_file(char *line);
t_file					*add_file(t_file *file, char *line);
/*
**          logical_infos_box.c
*/
int						logical_infos_pipe(t_data data);
int						logical_infos_box(t_infos *infos);
/*
**          parsing.c
*/
int						parsing_line(t_infos *infos, char *line, int etapes);
int						parsing_pipe_line(t_infos *infos, char ***tab);
int						check_nb_char(char *str, int nb, char c);
/*
**          valeur_data.c
*/
int						malloc_pipe(t_infos *infos, int i, int len);
int						valeur_data(t_infos *infos, int commande);
int						add_pipe(t_infos *infos, t_file *file);
/*
**          valeur_pipe.c
*/
int						norm_valeur_pipe(char ***tmp, int returne);
int						ft_find_str_in_tab(t_infos *infos, char *str);
int						add_link(t_infos *infos, int index_data,
						int index_pipe);
int						valeur_pipe(t_infos *infos);
/*
**          PARTIE ALGO
**          algo.c
*/
int						ft_algo_2(t_infos *infos);
int						ft_algo(t_infos *infos);
/*
**          alloc_tp....c
*/
int						ft_init_tab_path(t_infos *infos);
int						ft_alloue_p_states(t_infos *inf);
int						*ft_alloc_tab_int(int n, int val_initial);
/*
**          frees_algo.c
*/
void					ft_free_tab_int(int **tab, int height);
void					ft_free_all(t_infos *infos);
void					ft_lstdel_all(t_ants **fa);
/*
**          ft_check_precedents.c
*/
int						ft_check_precedents(t_infos *infos,
int 					*tab_path_n_piece, int n);

/*
**          ft_update_tab_path.c
*/
int						**ft_update_tab_path(t_infos *infos, int *tab);
int						ft_update_tab_path_2(t_infos *infos, int **tmp,
						int *tab, t_t *t);
/*
**          graph_utils.c
*/
int						*ft_updated_path(t_infos *inf, int *old_p, int room);
int						ft_add_graph_end(t_infos *inf, t_graph **fg, int *old_p,
						int room);
void					ft_new_graph(t_graph **fg);
void					ft_graph_del_start(t_graph **fa);
void					ft_lstdel_all_graph(t_graph **fa);
/*
**          list_utils.c
*/
void					ft_lstdel_start(t_ants **fa);
int						ft_lstadd_end(t_ants **fa, int num_a, int path, int room);
void					ft_lstadd_start(t_ants **fa, int num_ant, int path, int room);
void					ft_new_lst(t_ants **fa);
t_ants					*ft_lstdel_num_ant(t_ants **fa, int ant_to_del);
/*
**          move_ants.c
*/
int						ft_next_room_is_free(t_infos *infos, int index_path,
						int index_room);
t_ants					*ft_move_ants2(t_infos *i, int room_free, t_ants *tmp);
int						ft_move_ants(t_infos *i);
/*
**          resolution.c
*/
int						ft_fill_tab_path_turn_i(t_infos *t, int n, int **t_p_t,
						int nb_turn_max);
int						ft_find_group(t_infos *infos, int **tgt, int nb_gp,
						int nb_turn_max);
int						ft_create_ants(t_infos *i, int nb_ants_to_create);
int						ft_resolve2(t_infos *inf, t_r *res, int **tgt,
						int nb_gp);
int						ft_resolve(t_infos *infos, int nbr_group_path);
/*
**          utils_algo.c
*/
int						ft_min_int(int a, int b);
int						ft_max_int(int a, int b);
int						ft_init_tab_path(t_infos *infos);
int						ft_find_paths(t_infos *infos);
int						*ft_alloc_tab_int(int n, int val_initial);
int						ft_length_path(int *tab, int n);
/*
**          utils_edmonds.c
*/
int						ft_pipe_state(t_infos *inf, int r1, int r2);
void					ft_put_pipes_to_zero(t_infos *inf, int r1, int r2);
void					ft_put_pipe_to_one(t_infos *inf, int r1, int r2);
/*
**          weights.c
*/
int						ft_put_weights(t_infos *inf);
int						ft_save_paths(t_infos *inf);
int						ft_save_paths2(t_infos *inf, int i);
int						ft_init_w(t_infos *inf, t_w *w);
int						ft_ed(t_infos *inf);

#endif
