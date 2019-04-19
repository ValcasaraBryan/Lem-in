
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
	int				error[4];
	struct s_path	*next;
}					t_path;

typedef struct		s_ants
{
	int				n_ants;
	t_path			*path;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_infos
{
	int				flag;
	int				nb_of_fourmis;
	int				nb_of_box;
	int				nb_of_hit;
	int				nb_of_hit_real;
	t_data			*head_data;
	t_data			*data;
	t_file			*file;
	t_ants			*head_ants;
	t_ants			*ants;
}					t_infos;

#define ERROR_START	0
#define	ERROR_END	1
#define	ERROR_LINK	2
#define	ERROR_ANTS	3

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
	infos->file = NULL;
	infos->head_ants = NULL;
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
		return (new_link(data));
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

t_path		*new_path(t_data *current)
{
	t_path	*tmp;

	tmp = NULL;
	if (!current)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_path))))
		return (NULL);
	tmp->prev = NULL;
	tmp->error[0] = 0;
	tmp->error[1] = 0;
	tmp->error[2] = 0;
	tmp->error[3] = 0;
	tmp->current = current;
	tmp->next = NULL;
	return (tmp);
}

void		add_path(t_ants *ants, t_data *current)
{
	t_path	*tmp;

	if (ants->path)
	{
		tmp = ants->path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_path(current);
		tmp->next->prev = tmp;
	}
	else
		ants->path = new_path(current);
}

t_ants		*new_ants(int ants)
{
	t_ants	*tmp;

	tmp = NULL;
	if (ants < 1)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_ants))))
		return (NULL);
	tmp->n_ants = ants;
	tmp->path = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_ants		*add_ants(t_ants *old_ants, int ants)
{
	t_ants	*tmp;

	if (old_ants)
	{
		tmp = old_ants;
		if (tmp->n_ants == ants)
			return (old_ants);
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->n_ants == ants)
				return (old_ants);
		}
		tmp->next = new_ants(ants);
		return (old_ants);
	}
	else
		return (new_ants(ants));
}

t_data		*find_data(t_infos *infos, char *str)
{
	t_data	*tmp;

	tmp = infos->data;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_path		*find_path(t_infos *infos, int n_ants)
{
	t_ants	*tmp;

	tmp = infos->ants;
	while (tmp)
	{
		if (tmp->n_ants == n_ants)
			break ;
		tmp = tmp->next;
	}
	return (tmp->path);
}

t_ants		*find_ants(t_infos *infos, int n_ants)
{
	t_ants	*tmp;

	tmp = infos->ants;
	while (tmp)
	{
		if (tmp->n_ants == n_ants)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void		create_ants(t_infos *infos, char **tab)
{
	char	**split;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!(split = ft_strsplit(tab[i], '-')))
			return ;
		if (split && split[0] && split[1])
		{
			infos->ants = add_ants(infos->ants, ft_atoi(split[0] + 1));
			add_path(find_ants(infos, ft_atoi(split[0] + 1)), find_data(infos, split[1]));
		}
		i++;
	}
}

int			len_tab_str(char **tab)
{
	int		i;

	i = -1;
	if (tab)
		while (tab[++i]);
	return (i);
}

int			format(char *line, t_infos *infos)
{
	char	**tab;
	char	**pipe;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	if (len_tab_str(tab) == 1 && tab[0][0] != 'L')
	{
		if (!(pipe = ft_strsplit(line, '-')))
			return (-1);
		if (len_tab_str(pipe) == 2)
			add_pipe(infos, ft_strdup(pipe[0]), ft_strdup(pipe[1]));
		else if (len_tab_str(pipe) == 1 && ft_str_is_digit(tab[0]))
			return (1);
		else
			return (0);
	}
	else if (len_tab_str(tab) == 3 && tab[0][0] != 'L')
		infos->data = add_data(infos->data, ft_strdup(tab[0]), infos);
	else if (len_tab_str(tab) >= 1)
		create_ants(infos, tab);
	else
		return (0);
	return (1);
}

int			add_val_data(char *line, t_infos *infos)
{
	char	**tab;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	if (len_tab_str(tab) == 1)
	{
		if (tab && ft_str_is_digit(tab[0]))
		{
			infos->nb_of_fourmis = ft_atoi(tab[0]);
			return (1);
		}
	}
	else if (len_tab_str(tab) == 3 && tab[0][0] != 'L')
	{
		infos->nb_of_box++;
		return (1);
	}
	else if (len_tab_str(tab) >= 1)
	{
		if (ft_strcmp(line, "#Here is the number of lines required:") == 32)
			infos->nb_of_hit = ft_atoi(line + 39);
		else if (line && line[0] == 'L')
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
	infos->head_ants = infos->ants;
	return (1);
}

int			check_link(t_data *link, t_data *current)
{
	t_link	*tmp;

	if (!link)
		return (0);
	tmp = link->pipe;
	while (tmp)
	{
		if (ft_strcmp(tmp->data->name, current->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_data		*init_start(t_infos *infos)
{
	t_data	*tmp;

	tmp = infos->data;
	while (tmp)
	{
		if (tmp->commands == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_data		*init_next(t_data *start, t_data *current)
{
	t_link	*tmp;

	if (!start || !current)
		return (NULL);
	tmp = start->pipe;
	while (tmp)
	{
		if (ft_strcmp(tmp->data->name, current->name) == 0)
			return (tmp->data);
		tmp = tmp->next;
	}
	return (NULL);
}


void		print_error(t_infos *infos)
{
	while (infos->ants)
	{
		while (infos->ants->path)
		{
			if (infos->ants->path->error[ERROR_START])
				ft_printf("ERROR_START L%d-%s\n", infos->ants->n_ants, infos->ants->path->current->name);
			if (infos->ants->path->error[ERROR_END])
				ft_printf("ERROR_END   L%d-%s\n", infos->ants->n_ants, infos->ants->path->current->name);
			if (infos->ants->path->error[ERROR_LINK])
				ft_printf("ERROR_LINK  L%d-%s\n", infos->ants->n_ants, infos->ants->path->current->name);
			if (infos->ants->path->error[ERROR_ANTS])
				ft_printf("ERROR_ANTS  L%d-%s\n", infos->ants->n_ants, infos->ants->path->current->name);
			if (!infos->ants->path->next)
				break ;
			infos->ants->path = infos->ants->path->next;
		}
		while (infos->ants->path->prev)
			infos->ants->path = infos->ants->path->prev;
		infos->ants = infos->ants->next;
	}
}

int			check_log_hit(t_infos *infos)
{
	int		error;
	int		ants;
	int		flag;
	t_data	*start;
	t_data	*next;

	ants = 1;
	flag = 1;
	error = 0;
	while (infos->ants)
	{
		if (ants != infos->ants->n_ants)
		{
			infos->ants->path->error[ERROR_ANTS] = 1;
			error++;
		}
		start = init_start(infos);
		if (flag == 1)
		{
			if (check_link(start, infos->ants->path->current))
				flag = 0;
			else
			{
				infos->ants->path->error[ERROR_START] = 1;
				error++;
			}
		}
		next = init_next(start, infos->ants->path->current);
		while (infos->ants->path->next)
		{
			next = init_next(next, infos->ants->path->next->current);
			if (!(check_link(next, infos->ants->path->current)))
			{
				infos->ants->path->error[ERROR_LINK] = 1;
				error++;
			}
			if (infos->ants->path->next->current->commands == 2)
				flag = 2;
			infos->ants->path = infos->ants->path->next;
		}
		while (infos->ants->path->prev)
			infos->ants->path = infos->ants->path->prev;
		if (flag == 2)
			flag = 1;
		else if (flag == 0)
		{
			flag = 1;
			infos->ants->path->error[ERROR_END] = 1;
			error++;
		}
		ants++;
		infos->ants = infos->ants->next;
	}
	infos->ants = infos->head_ants;
	if (error > 0)
		return (0);
	else
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
	if (!(check_file(&infos)))
		return (1);
	// while (infos.data)
	// {
		// ft_printf("%-6s", infos.data->name);
		// ft_printf("%-6s", (infos.data->commands == 1) ? "START" : (infos.data->commands == 2) ? "END" : "");
		// while (infos.data->pipe)
		// {
			// ft_printf("%s ", infos.data->pipe->data->name);
			// infos.data->pipe = infos.data->pipe->next;
			// if (infos.data->pipe)
				// ft_printf(" -> ");
		// }
		// ft_printf("\n");
		// infos.data = infos.data->next;
	// }
	// while (infos.ants)
	// {
		// while (infos.ants->path)
		// {
			// ft_printf("L%d-%s ", infos.ants->n_ants, infos.ants->path->current->name);
			// if (!infos.ants->path->next)
				// break ;
			// infos.ants->path = infos.ants->path->next;
		// }
		// while (infos.ants->path)
		// {
			// if (!infos.ants->path->prev)
				// break ;
			// infos.ants->path = infos.ants->path->prev;
		// }
		// ft_printf("\n");
		// infos.ants = infos.ants->next;
	// }
	// infos.ants = infos.head_ants;
	if (!(check_log_hit(&infos)))
	{
		print_error(&infos);
		ft_printf("foumis = %d\nsalles = %d\nnombre de coup recommandé == %d\nnombre de coup real == %d\n",
			infos.nb_of_fourmis, infos.nb_of_box, infos.nb_of_hit, infos.nb_of_hit_real);
		return (0);
	}
	if (ret == -1)
	{
		ft_printf("Error GNL\n");
		return (0);
	}
	ft_printf("foumis = %d\nnombre de coup recommandé == %d\nnombre de coup real == %d\n",
			infos.nb_of_fourmis, infos.nb_of_hit, infos.nb_of_hit_real);
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
			ft_printf("\nFiles is not correct\n");
		else
			ft_printf("\nFiles is correct\n");
	}
	return (0);
}