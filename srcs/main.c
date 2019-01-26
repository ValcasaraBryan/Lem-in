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

void        ft_put_data(t_infos *infos)
{
    int     i;
    
    i = 0;
    if (infos)
    {
        if (infos->data)
        {
            while (i < infos->nb_of_box && infos->data[i].name_box)
            {
                ft_fprintf("nom        = %s\n", 2, infos->data[i].name_box);
                ft_fprintf("n_piece    = %d\n", 2, infos->data[i].n_piece);
                ft_fprintf("nb_of_link = %d\n", 2, infos->data[i].nb_of_link);
                ft_fprintf("commands   = %d\n", 2, infos->data[i].commands);
                ft_fprintf("x          = %d\n", 2, infos->data[i].coor_x);
                ft_fprintf("y          = %d\n\n", 2, infos->data[i].coor_y);
                i++;
            }
            ft_fprintf("\n", 2);
        }
    }
}

int         retour_check_file(t_infos *infos, t_file *head, int retour)
{
    if (retour == 0)
        perror("Error order box-pipe ");
    infos->file = head;
    return (retour);
}

int         skip_commentaire(t_infos *infos, t_file *head, int retour)
{
    if (!infos->file->next)
        return (retour_check_file(infos, head, retour));
    while (infos->file->next && infos->file->line[0] == '#'
        && infos->file->line[1] != '#')
        infos->file = infos->file->next;
    return (0);
}

int         init_check_order(t_infos *infos, int check_order)
{
    check_order = (!check_order && check_nb_char(infos->file->line, 2, ' '))
        ? 1 : check_order;
    check_order = (check_order == 1 && check_nb_char(infos->file->line, 1, '-'))
        ? 2 : check_order;
    check_order = (check_order != 1 && check_order != 2) ? -1 : check_order;
    return (check_order);
}

int         nb_of_link(t_infos *infos, char *str)
{
    t_file *head;
    char **tmp;
    int     i;

    head = infos->file;
    tmp = NULL;
    i = 0;
    while (head)
    {
        if (!(tmp = ft_strsplit(head->line, '-')))
            return (0);
        if (!tmp[0] || !tmp[1])
            free_tab_str(&tmp);
        if (tmp && ft_strcmp(str, tmp[0]) == 0)
            i++;
        free_tab_str(&tmp);
        head = head->next;
    }
    return (i);
}

int         valeur_data(t_infos *infos, int commande)
{
    char    **tmp;
    int     i;
    int     len;

    tmp = NULL;
    i = 0;
    len = 0;
    if (infos->file && infos->file->line && infos->data)
    {
        while (i <= infos->nb_of_box && infos->data[i].name_box)
            i++;
        if (!(tmp = ft_strsplit(infos->file->line, ' ')))
            return (0);
        if (!tmp[0] || !tmp[1] || !tmp[2])
            return (0);
        infos->data[i].name_box = tmp[0];
        infos->data[i].n_piece = i;
        infos->data[i].nb_of_link = nb_of_link(infos, infos->data[i].name_box);
        infos->data[i].commands = commande;
        infos->data[i].coor_x = ft_atoi(tmp[1]);
        infos->data[i].coor_y = ft_atoi(tmp[2]);
        if (!(infos->data[i].pipe = (t_data **)malloc(sizeof(t_data *) * (infos->data[i].nb_of_link + 1))))
            return (0);
        while (len <= infos->data[i].nb_of_link)
            infos->data[i].pipe[len++] = NULL;
        free(tmp);
        tmp = NULL;
    }
    return (1);
}

int         valeur_pipe(t_infos *infos)
{
    (void)infos;
    return (0);
}

int         step_check(t_infos *infos, t_file *head, int check_order, int commande)
{
    
    if ((check_order = init_check_order(infos, check_order)) == -1)
        return (retour_check_file(infos, head, 0));
    if (check_order == 1)
    {
        valeur_data(infos, commande);
        ft_fprintf("check_order = 1 [%s]\n", 2, infos->file->line);
        return (1);
    }
    if (check_order == 2)
    {
        if (check_nb_char(infos->file->line, 2, ' '))
            return (retour_check_file(infos, head, 0));
        // valeur_pipe(infos);
        ft_fprintf("check_order = 2 [%s]\n", 2, infos->file->line);
        return (2);
    }
    return (0);
}

int         check_file(t_infos *infos)
{
    t_file  *head;
    int     commande;
    int     check_order;

    if (!infos->file)
        return (0);
    check_order = 0;
    head = infos->file;
    if (infos->file->next && ft_str_is_digit(infos->file->line)
        && ft_atoi(infos->file->line) > 0)
        infos->file = infos->file->next;
    while (infos->file)
    {
        check_order = (ft_strcmp(infos->file->line, "##start") == 0 || ft_strcmp(infos->file->line, "##end") == 0) ? 0 : check_order;
        commande = (ft_strcmp(infos->file->line, "##start")) == 0 ? 1 : 0;
        commande = (ft_strcmp(infos->file->line, "##end")) == 0 ? 2 : commande;
        if (!check_order && infos->file->next)
            infos->file = infos->file->next;
        if (infos->file->line && infos->file->line[0] == '#'
            && infos->file->line[1] != '#')
                if (skip_commentaire(infos, head, 1))
                    return (1);
        if (!(check_order = step_check(infos, head, check_order, commande)))
            return (0);
        infos->file = infos->file->next;
    }
    return (retour_check_file(infos, head, 1));
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

    ft_fprintf("/-------------------------------------------\\\n", 2);
    infos = get_file();
    if (!infos.file)
    {
        perror("Error File = 1st step ");
        return (0);
    }
    if (!(init_data(&infos)))
    {
        perror("Error Data = 2nd step ");
        return (0);
    }
    if (!(check_file(&infos)))
        erase_infos(&infos);
    // ft_put_list(infos.file);
    ft_put_data(&infos);
    ft_fprintf("nb_of_fourmi = %d\n", 2, infos.nb_of_fourmis);
    ft_fprintf("nb_of_box = %d\n", 2, infos.nb_of_box);
    ft_fprintf("nb_of_pipe = %d\n", 2, infos.nb_of_pipe);
    ft_fprintf("infos = %p\n", 2, infos);
    ft_fprintf("file = %p\n", 2, infos.file);
    ft_fprintf("data = %p\n", 2, infos.data);
    ft_fprintf("data->pipe = %p\n\n\\-------------------------------------------/\n", 2, infos.data->pipe);
    return (0);
}

void        erase_infos(t_infos *infos)
{
    t_file  *head;

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