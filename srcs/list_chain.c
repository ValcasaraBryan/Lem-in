/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:55:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/29 14:55:02 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_file      *new_file(char *line)
{
    t_file *tmp;

    tmp = NULL;
    if (!(tmp = malloc(sizeof(t_file))))
        return (NULL);
    tmp->line = (line && tmp) ? line : NULL;
    tmp->next = NULL;
    return (tmp);
}

t_file      *add_file(t_file *file, char *line)
{
    t_file *tmp;

    if (file)
    {
        tmp = file;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_file(line);
        return (file);
    }
    else
        return (new_file(line));
}
