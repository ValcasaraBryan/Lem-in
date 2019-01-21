/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:10:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/21 18:10:26 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

int         main(int argc, char **argv)
{
    char *line;
    (void)argc;
    (void)argv;

    line = NULL;
    while (get_next_line(0, &line) > 0)
        ft_fprintf("%s\n", 2, line);
    return (0);
}