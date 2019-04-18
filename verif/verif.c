
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:13:19 by brvalcas          #+#    #+#             */
/*   Updated: 2019/04/18 15:13:22 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef struct			s_file
{
	char				*line;
	struct s_file		*next;
}						t_file;

typedef struct		s_link
{
	struct s_data	*data;
	struct s_link	*next;
}					t_link;

typedef struct		s_data
{
	char			*name;
	int				commands;
	struct s_link	*pipe;
	struct s_data	*next;
}					t_data;

typedef struct		s_path
{
	struct s_path	*prev;
	t_data			*current;
	struct s_path	*next;
}					t_path;

typedef struct		s_ants
{
	int				n_ants;
	t_path			*path;
}					t_ants;

typedef struct		s_infos
{
	int				flag;
	int				nb_of_fourmis;
	int				nb_of_box;
	int				nb_of_hit;
	int				nb_of_hit_real;
	t_data			*data;
	t_data			*head_data;
	t_file			*file;
	t_file			*head_file;
	t_ants			*ants;
}					t_infos;

t_file		*new_file(char *line)
{
	t_file	*tmp;

	tmp = NULL;
	if (!line)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_file))))
		return (NULL);
	tmp->line = line;
	tmp->next = NULL;
	return (tmp);
}

t_file		*add_file(t_file *file, char *line)
{
	t_file	*tmp;

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

t_data		*new_data(char *name, t_infos *infos)
{
	t_data	*tmp;

	tmp = NULL;
	if (!name)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_data))))
		return (NULL);
	tmp->name = name;
	tmp->commands = infos->flag;
	if (infos->flag)
		infos->flag = 0;
	tmp->pipe = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_data		*add_data(t_data *data, char *name, t_infos *infos)
{
	t_data	*tmp;

	if (data)
	{
		tmp = data;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_data(name, infos);
		return (data);
	}
	else
		return (new_data(name, infos));
}

void		init_infos(t_infos *infos)
{
	infos->flag = 0;
	infos->head_data = NULL;
	infos->data = NULL;
	infos->head_file = NULL;
	infos->file = NULL;
	infos->ants = NULL;
	infos->nb_of_fourmis = 0;
	infos->nb_of_box = 0;
	infos->nb_of_hit = 0;
	infos->nb_of_hit_real = 0;
}

t_link		*new_link(t_data *data)
{
	t_link	*tmp;

	tmp = NULL;
	if (!data)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_link))))
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

t_link		*add_link(t_link *link, t_data *data)
{
	t_link	*tmp;

	if (link)
	{
		tmp = link;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link(data);
		return (link);
	}
	else
	{
		return (new_link(data));
	}
}

t_data		*check_data(t_infos *infos, char *str)
{
	t_data	*tmp;

	tmp = infos->data;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		add_pipe(t_infos *infos, char *name, char *name_link)
{
	t_data *tmp;
	t_data *tmp_2;

	tmp = check_data(infos, name);
	tmp_2 = check_data(infos, name_link);
	tmp->pipe = add_link(tmp->pipe, tmp_2);
	tmp_2->pipe = add_link(tmp_2->pipe, tmp);
}

int			format(char *line, t_infos *infos)
{
	char	**tab;
	char	**pipe;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	if (tab && tab[0] && !tab[1])
	{
		if (!(pipe = ft_strsplit(line, '-')))
			return (-1);
		if (pipe && pipe[0] && !pipe[2])
		{
			add_pipe(infos, ft_strdup(pipe[0]), ft_strdup(pipe[1]));
		}
		else if (tab && ft_str_is_digit(tab[0]))
			return (1);
		else
			return (0);
	}
	else if (tab && tab[0] && tab[1] && tab[2] && !tab[3])
	{
		infos->data = add_data(infos->data, ft_strdup(tab[0]), infos);
	}
	else if (tab && (tab[0] || tab[1] || tab[2] || tab[3]))
	{
		// ft_printf("%s\n", line);
		// faire le chemin de chaque fourmis dans la liste chainee t_path houra
	}
	else
		return (0);
	return (1);
}

int			add_val_data(char *line, t_infos *infos)
{
	char	**tab;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	if (tab && tab[0] && !tab[1])
	{
		if (tab && ft_str_is_digit(tab[0]))
		{
			infos->nb_of_fourmis = ft_atoi(tab[0]);
			return (1);
		}
	}
	else if (tab && tab[0] && tab[1] && tab[2] && !tab[3])
	{
		infos->nb_of_box++;
		return (1);
	}
	else if (tab && (tab[0] || tab[1] || tab[2] || tab[3]))
	{
		if (ft_strcmp(line, "#Here is the number of lines required:") == 32)
			infos->nb_of_hit = ft_atoi(line + 39);
		else
			infos->nb_of_hit_real++;
		return (1);
	}
	return (0);
}

int			check_file(t_infos *infos)
{
	char	*line;

	while (infos->file)
	{
		line = infos->file->line;
		if (line && ft_strcmp(line, "##end") == 0)
			infos->flag = 2;
		if (line && ft_strcmp(line, "##start") == 0)
			infos->flag = 1;
		if (line && line[0] != '#')
			format(line, infos);
		infos->file = infos->file->next;
	}

	ft_printf("foumis = %d\nsalles = %d\nnombre de coup recommandé == %d\nnombre de coup real == %d\n",
		infos->nb_of_fourmis, infos->nb_of_box, infos->nb_of_hit, infos->nb_of_hit_real);
	return (1);
}

int			ft_check(int fd)
{
	t_infos	infos;
	char	*line;
	int		ret;

	init_infos(&infos);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		infos.file = add_file(infos.file, line);
		add_val_data(line, &infos);
	}
	infos.head_file = infos.file;
	if (!(check_file(&infos)))
		return (1);
	while (infos.data)
	{
		ft_printf("%-6s", infos.data->name);
		ft_printf("%-6s", (infos.data->commands == 1) ? "START" : (infos.data->commands == 2) ? "END" : "");
		while (infos.data->pipe)
		{
			ft_printf("%s ", infos.data->pipe->data->name);
			infos.data->pipe = infos.data->pipe->next;
			if (infos.data->pipe)
				ft_printf(" -> ");
		}
		ft_printf("\n");
		infos.data = infos.data->next;
	}
	if (ret == -1)
	{
		ft_printf("Error GNL\n");
		return (0);
	}

	return (1);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Usage : ./check_result [fichier]\n");
	}
	else
	{
		if ((fd = open(argv[argc - 1], O_RDONLY)) == -1)
		{
			ft_printf("Files does'nt exist\n");
			return (0);
		}
		if (!(ft_check(fd)))
			return (0);
		else
			ft_printf("\nFiles is correct\n");
	}
	return (0);
}