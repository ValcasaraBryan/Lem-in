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
	int					**tab_path;
}                       t_infos;

/*
**          main.c
*/

int                     check_file(t_infos *infos);
int                     init_data(t_infos *infos);

void                    erase_infos(t_infos *infos);
t_infos                 get_file(void);
int						free_tab_str(char ***str);
/*
**          parsing.c
*/
int                     parsing_line(t_infos *infos, char *line, int etapes);
int                     parsing_pipe_line(t_infos *infos, char ***tab);
int                     check_nb_char(char *str, int nb, char c);
/*
**          affichage.c
*/
void                    ft_put_list(t_file *file);
void                    ft_put_data(t_infos *infos);
/*
**          list_chain.c
*/
t_file                  *new_file(char *line);
t_file                  *add_file(t_file *file, char *line);

/*
**          algo.c
*/
int						ft_algo(t_infos *infos);

/*
**          choose_path.c
*/
void					ft_choose_path(t_infos *infos);



#endif
