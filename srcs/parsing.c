/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:19:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/23 17:19:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int         parsing_line(char *line, int etapes)
{
    char **tmp;
    char **pipe;

    tmp = NULL;
    pipe = NULL;
    if (!line)
        return (0);
    if (etapes == 0)
        return ((ft_atoi(line)) <= 0 ? 0 : 1);
    if (line[0] == '#' && line[1] == '#'
        && (ft_strcmp(line, "##start") == 0
        || ft_strcmp(line, "##end") == 0))
            return (1);
    if (line[0] == '#' && line[1] != '#')
            return (1);
    if (!(tmp = ft_strsplit(line, ' ')))
        return (0);
    if (tmp[0] && tmp[1] && tmp[2]
        && (ft_atoi(tmp[0]) >= 0 && ft_atoi(tmp[1]) >= 0
        && ft_atoi(tmp[2]) >= 0))
    {
        free_tab_str(&tmp);
        return (1);
    }
    if (tmp[0] && !tmp[1])
    {
        if (!(pipe = ft_strsplit(tmp[0], '-')))
        {
            free_tab_str(&tmp);
            return (0);
        }
        if (pipe[0] && pipe[1])
        {
            free_tab_str(&tmp);
            free_tab_str(&pipe);
            return (1);
        }
    }
    free_tab_str(&tmp);
    free_tab_str(&pipe);
    return (0);
}