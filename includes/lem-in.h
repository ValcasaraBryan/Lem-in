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
    int                 nb_of_box;
    int                 nb_of_fourmis;
    t_file              *file;
    t_data              *data;
}                       t_infos;

int                     parsing_line(char *line, int etapes);
int						free_tab_str(char ***str);

#endif
