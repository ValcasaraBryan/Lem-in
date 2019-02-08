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
#define a 0
#define b 11
#define c 8
#define d 2
#define e 14
#define f 3
#define g 5
#define h 4
#define i 34
#define j 38
#define k 40
#define l 37
#define m 46
#define n 45
#define o 31
#define p 35
#define q 12
#define r 15
#define s 1
#define t 17
#define u 32
#define v 9
#define w 13
#define x 7
#define y 16
#define z 6
*/
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
    struct s_data       **pipe;
}                       t_data;

typedef struct          s_infos
{
    int                 nb_of_fourmis;
    int                 nb_of_box;
    int                 nb_of_pipe;
    int                 nb_path_max;
    t_file              *file;
    t_data              *data;
}                       t_infos;

/*
**          affichage.c
*/
void                    ft_put_list(t_file *file);
void                    ft_put_data(t_infos *infos);
/*
**          algo.c
*/
int                     ft_algo(t_infos *infos);
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
