
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
	int					n_line;
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
	int				n_line;
	int				error[5];
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
	int				fourmis_to_end;
	int				nb_of_box;
	int				nb_of_hit;
	int				nb_of_hit_real;
	int				error[3];
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
#define	ERROR_INFOS	4
#define ERROR_NO_ALL_ANTS	0
#define	ERROR_ANTS_TOO_MOVE	1
#define	ERROR_BOX			2

static int	ft_str_is_digit_two(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!(ft_isdigit(str[i])))
			return (0);
	return (1);
}


t_file		*new_file(char *line, int n_line)
{
	t_file	*tmp;

	tmp = NULL;
	if (!line)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_file))))
		return (NULL);
	tmp->line = line;
	tmp->n_line = n_line;
	tmp->next = NULL;
	return (tmp);
}

t_file		*add_file(t_file *file, char *line, int n_line)
{
	t_file	*tmp;

	if (file)
	{
		tmp = file;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_file(line, n_line);
		return (file);
	}
	else
		return (new_file(line, n_line));
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
	infos->error[ERROR_NO_ALL_ANTS] = 0;
	infos->error[ERROR_ANTS_TOO_MOVE] = 0;
	infos->error[ERROR_BOX] = 0;
	infos->head_data = NULL;
	infos->data = NULL;
	infos->file = NULL;
	infos->head_ants = NULL;
	infos->ants = NULL;
	infos->nb_of_fourmis = 0;
	infos->fourmis_to_end = 0;
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

t_path		*new_path(t_data *current, t_infos *infos)
{
	t_path	*tmp;

	tmp = NULL;
	if (!current)
		return (NULL);
	if (!(tmp = malloc(sizeof(t_path))))
		return (NULL);
	tmp->prev = NULL;
	tmp->n_line = infos->file->n_line;
	tmp->error[ERROR_START] = 0;
	tmp->error[ERROR_END] = 0;
	tmp->error[ERROR_LINK] = 0;
	tmp->error[ERROR_ANTS] = 0;
	tmp->error[ERROR_INFOS] = (infos->error[ERROR_ANTS_TOO_MOVE]) ? 1 : 0;
	tmp->current = current;
	tmp->next = NULL;
	return (tmp);
}

void		add_path(t_ants *ants, t_data *current, t_infos *infos)
{
	t_path	*tmp;

	if (!current || !ants)
		return ;
	if (ants->path)
	{
		tmp = ants->path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_path(current, infos);
		tmp->next->prev = tmp;
	}
	else
		ants->path = new_path(current, infos);
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
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_ants		*find_ants(t_infos *infos, int n_ants)
{
	t_ants	*tmp;

	if (n_ants <= 0)
		return (NULL);
	tmp = infos->ants;
	while (tmp)
	{
		if (tmp->n_ants == n_ants)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int			len_tab_str(char **tab)
{
	int		i;

	i = -1;
	if (tab)
		while (tab[++i]);
	return (i);
}

int			check_commands_data(t_infos *infos, char *str, int commands)
{
	t_data	*tmp;

	tmp = infos->data;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0 && tmp->commands == commands)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			check_like_box(t_infos *infos, char **tab, char **split, int i)
{
	char	**split_cmp;
	int		len_tab;
	int		j;

	(void)infos;
	len_tab = len_tab_str(tab + i) + i;
	j = i;
	while (++j < len_tab)
	{
		if (!(split_cmp = ft_strsplit(tab[j], '-')))
			return (0);
		if (len_tab_str(split_cmp) == 2)
			if (ft_strcmp(split[1], split_cmp[1]) == 0)
				if (!check_commands_data(infos, split[1], 2))
					if (!check_commands_data(infos, split_cmp[1], 2))
						return (0);
	}
	return (1);
}

void		create_ants(t_infos *infos, char **tab)
{
	char	**split;
	int		n_ants;
	
	int		i;

	i = 0;
	n_ants = 0;
	while (tab[i])
	{
		if (!(split = ft_strsplit(tab[i], '-')))
			return ;
		if (len_tab_str(split) == 2)
		{
			if (!(check_like_box(infos, tab, split, i)))
				infos->error[ERROR_BOX] = 1;
			// ft_printf("%d - %d\n", n_ants, ft_atoi(split[0] + 1));
			// ft_printf("%d\n", infos->error[ERROR_ANTS_TOO_MOVE]);
			if (!infos->error[ERROR_ANTS_TOO_MOVE])
				infos->error[ERROR_ANTS_TOO_MOVE] = (n_ants >= ft_atoi(split[0] + 1)) ? 1 : 0;
			// ft_printf("%d\n", infos->error[ERROR_ANTS_TOO_MOVE]);
			n_ants = ft_atoi(split[0] + 1);
			infos->ants = add_ants(infos->ants, n_ants);
			add_path(find_ants(infos, n_ants), find_data(infos, split[1]), infos);
		}
		i++;
	}
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
		else if (len_tab_str(pipe) == 1 && ft_str_is_digit_two(tab[0]))
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
	if (len_tab_str(tab) == 1 && tab[0][0] != 'L')
	{
		if (tab && ft_str_is_digit_two(tab[0]))
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
	infos->head_data = infos->data;
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
				ft_printf("Line : %d\tERROR_START\tL%d\n", infos->ants->path->n_line, infos->ants->n_ants);
			if (infos->ants->path->error[ERROR_END])
				ft_printf("Line : %d\tERROR_END\tL%d\n", infos->ants->path->n_line, infos->ants->n_ants);
			if (infos->ants->path->error[ERROR_LINK])
				ft_printf("Line : %d\tERROR_LINK\tL%d-%s\n", infos->ants->path->n_line, infos->ants->n_ants, infos->ants->path->current->name);
			if (infos->ants->path->error[ERROR_ANTS])
				ft_printf("Line : %d\tERROR_ANTS\tL%d\n", infos->ants->path->n_line, infos->ants->n_ants);
			if (!infos->ants->path->next)
				break ;
			infos->ants->path = infos->ants->path->next;
		}
		while (infos->ants->path->prev)
			infos->ants->path = infos->ants->path->prev;
		infos->ants = infos->ants->next;
	}
	if (infos->error[ERROR_NO_ALL_ANTS])
		ft_printf("ERROR_NO_ALL_ANTS\n");
	if (infos->error[ERROR_ANTS_TOO_MOVE])
		ft_printf("ERROR_ANTS_TOO_MOVE\n");
	if (infos->error[ERROR_BOX])
		ft_printf("ERROR_BOX\n");
	ft_printf("\n");
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
			infos->ants->path = infos->ants->path->next;
		}
		if (infos->ants->path->current->commands == 2 && infos->ants->n_ants <= infos->nb_of_fourmis)
		{
			infos->fourmis_to_end++;
			flag = 2;
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
		if (infos->nb_of_fourmis >= ants)
			ants++;
		infos->ants = infos->ants->next;
	}
	infos->ants = infos->head_ants;
	infos->error[ERROR_NO_ALL_ANTS] = (infos->fourmis_to_end < infos->nb_of_fourmis) ? 1 : 0;
	error = (infos->fourmis_to_end < infos->nb_of_fourmis) ? 1 : error;
	error = infos->error[ERROR_ANTS_TOO_MOVE] ? 1 : error;
	error = infos->error[ERROR_BOX] ? 1 : error;
	if (error > 0)
		return (0);
	else
		return (1);
}


int			ft_check(int fd)
{
	t_infos	infos;
	char	*line;
	int		n_line;
	int		ret;

	init_infos(&infos);
	n_line = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		infos.file = add_file(infos.file, line, n_line++);
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
	// infos.head_data = infos.data;
	// infos.head_ants = infos.ants;
	if (!(check_log_hit(&infos)))
	{
		print_error(&infos);
		ft_printf("ANTS_TO_END\t\t\t%d / %d\nHIT\t\t\t\t%d / %d\n",
			infos.fourmis_to_end, infos.nb_of_fourmis, infos.nb_of_hit_real, infos.nb_of_hit);
		return (0);
	}
	if (ret == -1)
	{
		ft_printf("Error GNL\n");
		return (0);
	}
	ft_printf("ANTS_TO_END\t\t\t%d / %d\nHIT\t\t\t\t%d / %s\n",
			infos.fourmis_to_end, infos.nb_of_fourmis, infos.nb_of_hit_real, infos.nb_of_hit > 0 ? ft_itoa(infos.nb_of_hit) : "Not Precised");
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