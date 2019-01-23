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

int         main(int argc, char **argv)
{
    t_infos infos;
    char *line;
    int     etapes;
    (void)argc;
    (void)argv;

    line = NULL;
    etapes = 0;
    infos.file = NULL;
    infos.data = NULL;
    infos.nb_of_box = 0;
    while (get_next_line(0, &line) > 0)
    {
        if (!(parsing_line(line, etapes)))
        {
            perror("Error file ");
            break ;
        }
        if (etapes == 0)
        {
            infos.nb_of_fourmis = ft_atoi(line);
            etapes++;
        }
        infos.file = add_file(infos.file, line);
    }
    while (infos.file)
    {
        ft_fprintf("%s\n", 2, infos.file->line);
        infos.file = infos.file->next;
    }
    return (0);
}

int			free_tab_str(char ***str)
{
	char	**tab;
	int		i;

	i = -1;
	tab = *str;
	if (!tab)
		return (0);
	else
	{
		while (tab[++i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		free(tab);
		tab = NULL;
		*str = tab;
	}
	return (i);
}

// premiere ligne = nb de fourmi

// # commantaire, ignorer

// ## commande start ou end defini la ligne suivante
// nom_de_salle x_salle y_salle

// nom_de_salle x_salle y_salle

// salle_?-salle? defini les tubes