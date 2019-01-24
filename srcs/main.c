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

void        ft_put_list(t_file *file)
{
    ft_fprintf("\nlist chainée :\n-----------------\n", 2);
    while (file)
    {
        ft_fprintf("%s -> ", 2, file->line);
        if (file->next)
            ft_fprintf("%s\n", 2, file->next->line);
        else
            ft_fprintf("NULL\n", 2);
        file = file->next;
    }
    ft_fprintf("\n", 2);
}

int         check_file(t_infos *infos)
{
    t_file  *head;
    int     check_order;
    char    **tab;

    if (!infos->file)
        return (0);
    check_order = 0;
    head = infos->file;
    tab = NULL;
    if (infos->file->next)
        infos->file = infos->file->next;
    while (infos->file)
    {
        check_order = (ft_strcmp(infos->file->line, "##start") == 0 || ft_strcmp(infos->file->line, "##end") == 0) ? 0 : check_order;
        if (!check_order && infos->file->next)
            infos->file = infos->file->next;
        if (infos->file->line && infos->file->line[0] == '#' && infos->file->line[1] != '#')
        {
            if (!infos->file->next)
            {
                infos->file = head;
                return (1);
            }
            while (infos->file->next && infos->file->line[0] == '#' && infos->file->line[1] != '#')
                infos->file = infos->file->next;
        }
        check_order = (!check_order && check_nb_char(infos->file->line, 2, ' ')) ? 1 : check_order;
        check_order = (check_order == 1 && check_nb_char(infos->file->line, 1, '-')) ? 2 : check_order;
        check_order = (check_order != 1 && check_order != 2) ? -1 : check_order;
        if (check_order == 1)
        {
            ft_fprintf("check_order = 1 [%s]\n", 2, infos->file->line);
        }
        else if (check_order == 2)
        {
            if (check_nb_char(infos->file->line, 2, ' '))
            {
                infos->file = head;
                return (0);
            }
            ft_fprintf("check_order = 2 [%s]\n", 2, infos->file->line);
        }
        else if (check_order == -1)
        {
            infos->file = head;
            return (0);
        }
        infos->file = infos->file->next;
    }
    infos->file = head;
    return (1);
}

int         init_data(t_infos *infos)
{
    int     i;

    if (infos->nb_of_box < 0)
        return (0);
    if (!(infos->data = malloc(sizeof(t_data) * (infos->nb_of_box + 1))))
        return (0);
    if (infos->data)
    {
        i = -1;
        while (++i <= infos->nb_of_box)
        {
            infos->data[i].name_box = NULL;
            infos->data[i].n_piece = 0;
            infos->data[i].nb_of_link = 0;
            infos->data[i].commands = 0;
            infos->data[i].coor_x = 0;
            infos->data[i].coor_y = 0;
            infos->data[i].pipe = NULL;
        }
        return (1);
    }
    return (0);
}

int         main(int argc, char **argv)
{
    t_infos infos;
    (void)argc;
    (void)argv;

    infos = get_file();

    if (!(init_data(&infos)))
        return (0);
    if (!(check_file(&infos)))
        erase_infos(&infos);
    ft_put_list(infos.file);
    ft_fprintf("nb_of_fourmi = %d\n", 2, infos.nb_of_fourmis);
    ft_fprintf("nb_of_box = %d\n", 2, infos.nb_of_box);
    ft_fprintf("nb_of_pipe = %d\n", 2, infos.nb_of_pipe);
    ft_fprintf("file = %p\n", 2, infos.file);
    ft_fprintf("data = %p\n", 2, infos.data);
    ft_fprintf("data->pipe = %p\n", 2, infos.data->pipe);
    return (0);
}

void        erase_infos(t_infos *infos)
{
    t_file  *head;

    perror("Error file ");
    if (infos->file)
        while (infos->file)
        {
            head = infos->file->next;
            free(infos->file->line);
		    infos->file->line = NULL;
            free(infos->file);
		    infos->file = NULL;
			infos->file = head;
        }
}

t_infos     get_file(void)
{
    t_infos infos;
    char    *line;
    int     etapes;

    line = NULL;
    etapes = 0;
    infos.file = NULL;
    infos.data = NULL;
    infos.nb_of_fourmis = 0;
    infos.nb_of_box = 0;
    infos.nb_of_pipe = 0;
    while (get_next_line(0, &line) > 0)
    {
        if (!(parsing_line(&infos, line, etapes)))
        {
            if (line)
            {
                free(line);
                line = NULL;
            }
            get_next_line(0, NULL);
            erase_infos(&infos);
            break ;
        }
        if (etapes == 0)
        {
            infos.nb_of_fourmis = ft_atoi(line);
            etapes++;
        }
        infos.file = add_file(infos.file, line);
    }
    return (infos);
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