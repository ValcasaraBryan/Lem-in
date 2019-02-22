/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:09:30 by glebouch          #+#    #+#             */
/*   Updated: 2019/02/18 13:09:33 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_puttamere(t_infos *in)
{
	int i = 0;
	
	 while (i < in->nb_of_box)
	 {
	 	int j = 0;
	 	while(j < in->data[i].nb_of_link)
	 	{
	 		ft_putchar('[');
	 		ft_putnbr(j);
	 		ft_putchar('-');
	 		ft_putnbr(in->data[i].pipe[j]->n_piece);
	 		ft_putchar(']');
	 		j++;
	 	}
	 	ft_putchar('\n');
	 	i++;
	}
}
void	ft_check_precedent(t_infos *infos, t_s *s, int n, int current)
{
	int i;

	i = 0;
	ft_putendl("sortie toto");
	while (i < infos->nb_of_box)
	{
		if (s->tp_tmp[i] == current)
			if (i > 0 && s->tp_tmp[i - 1] == n)
			{

	ft_putendl("sortie toto 2");
				s->t_i_try[s->i]++;
				return ;
			}
		i++;
	}
	return ;
}

int		ft_check_precedents(t_infos *infos, int *tab_path_n_piece, int n)
{
	// ft_putendl("tamere");
	int i;

	i = 0;
	while (i < infos->nb_of_box)
	{
		if (tab_path_n_piece[i] == n)
			return (0);
		i++;
	}
	return (1);
}
/*
**	t_i_try = tableau index des inf->pipe a essayer
**	tp_tmp = tab_path_n_piece, tableau qui contient
**				les num des pieces et forme le chemin
*/


/*
void	ft_search_path2(t_infos *inf, t_s *s)
{
	// ft_putendl("totoiii");

	while (s->t_i_try[s->i] < inf->data[s->i].nb_of_link 
		&& inf->data[s->i].commands != 2)
	{
		if (s->t_i_try[s->i] < inf->data[s->i].nb_of_link //verifie qu'il y a encore des liens (maybe obsolete)
			&& ft_check_precedents(inf, s->tp_tmp, inf->data[inf->data[s->i].pipe[s->t_i_try[s->i]]->n_piece].n_piece) //check du passage dans la salle du lien effectue
			&& inf->data[s->i].tl[s->t_i_try[s->i]])//verifier que le lien est pertinant
		{
			s->t_i_try[s->i]++;
			s->i = inf->data[\
				inf->data[s->i].pipe[s->t_i_try[s->i] - 1]->n_piece].n_piece;
			s->tp_tmp[s->j] = s->i;
			s->j++;
		}
		else
		{
			if (s->j > 1 && inf->data[inf->data[s->i].pipe[s->t_i_try[s->i]]->n_piece].n_piece != s->tp_tmp[s->j - 2])
			{
				ft_putendl("pointe vers precedent");
				inf->data[s->i].tl[s->t_i_try[s->i]] = 0;
			}
			s->t_i_try[s->i]++;
		}
	}
	if (inf->data[s->i].commands == 2)
	{
	ft_putendl("                                                      un path");
		inf->t_p = ft_update_tab_path(inf, s->tp_tmp);
		s->j--;
		s->tp_tmp[s->j] = -1;
		s->i = s->tp_tmp[s->j - 1];
	}
	else if (s->t_i_try[s->i] >= inf->data[s->i].nb_of_link)
	{
	ft_putendl("no path");
		ft_relay(inf, s);
	}
	// ft_putendl("sp2 fin");
}

void	ft_search_path22(t_infos *inf, t_s *s)
{
	int i = 0;
	printf("IN : %s\n",  inf->data[s->i].name_box);
	while (i < inf->data[s->i].nb_of_link)
	{
		if (ft_check_precedents(inf, s->tp_tmp, inf->data[inf->data[s->i].pipe[i]->n_piece].n_piece) //check du passage dans la salle du lien effectue
			&& inf->data[s->i].tl[i])//verifier que le lien est pertinant
		{
			i++;
			s->i = inf->data[inf->data[s->i].pipe[i - 1]->n_piece].n_piece;
			s->tp_tmp[s->j] = s->i;
			s->j++;
			if (inf->data[s->i].commands == 2)
			{
				ft_putendl("                                                      un path");
				inf->t_p = ft_update_tab_path(inf, s->tp_tmp);
				s->j--;
				s->tp_tmp[s->j] = -1;
				s->i = s->tp_tmp[s->j - 1];
			}
			else
				ft_search_path22(inf, s);
		}
		else
		{
			if (s->i == 9 && inf->data[inf->data[s->i].pipe[i]->n_piece].n_piece == 14)
				ft_putendl("bloup");
			if (s->j > 1 && inf->data[inf->data[s->i].pipe[i]->n_piece].n_piece != s->tp_tmp[s->j - 2])
			{
				ft_putendl("pointe vers precedent");
				inf->data[s->i].tl[i] = 0;
			}
			i++;
		}
		// if (s->t_i_try[s->i] >= inf->data[s->i].nb_of_link)
		// 	{
		// 		ft_putendl("no path");
		// 		ft_relay(inf, s);
		// 	}
	}
	i = 0;
	s->tp_tmp[s->j - 1] = -1;
	s->j--;
	s->i = s->tp_tmp[s->j - 1];

	printf("OUT s->t_i_try[s->i] %d : %d -  %s\n",  i, s->i,inf->data[s->i].name_box);
}

int		ft_search_path(t_infos *infos, int start)
{
	t_s s;

	s.i = 0;
	s.j = 1;

	ft_puttamere(infos);
	if (!(s.tp_tmp = ft_alloc_tab_int(infos->nb_of_box, -1)))
		return (0);
	if (!(s.t_i_try = ft_alloc_tab_int(infos->nb_of_box, 0)))
	{
		free(s.tp_tmp);
		return (0);
	}
	s.tp_tmp[0] = start;
	// ft_boucles(infos, &s, start);
	// while (s.i != start || s.t_i_try[start] < infos->data[start].nb_of_link)
	// {
//		printf("%s\n",  infos->data[s.i].name_box);
		// ft_search_path2(infos, &s);
		ft_search_path22(infos, &s);
	// }


	int i = 1;
	int j;
	while (i < infos->t_p[0][0])
	{
		j = 0;
		while (j < infos->nb_of_box && infos->t_p[i][j] != -1)
		{
			printf("%s - ", infos->data[infos->t_p[i][j++]].name_box);
		}
		printf("\n");
		i++;
	}
	ft_putendl("sortie 2");
	free(s.tp_tmp);
	free(s.t_i_try);
	ft_putnbr(infos->t_p[0][0]);
	return (infos->t_p[0][0]);
}
*/
void	ft_relay(t_infos *inf, t_s *s)
{
	(void)inf;
//	ft_putendl("cc\n");
//	inf->data[s->i].tl[s->t_i_try[s->i] - 1] = 0;
	s->t_i_try[s->i] = 0;
	s->tp_tmp[s->j - 1] = -1;
	s->j--;
	s->i = s->tp_tmp[s->j - 1];
}

void	ft_search_path2(t_infos *inf, t_s *s)
{
	while (s->t_i_try[s->i] < inf->data[s->i].nb_of_link && \
		inf->data[s->i].commands != 2
		&& inf->data[s->i].tl[s->t_i_try[s->i]])
	{
		if (ft_check_precedents(inf, s->tp_tmp, \
			inf->data[inf->data[s->i].pipe[s->t_i_try[s->i]]->n_piece].n_piece))
		{
			s->t_i_try[s->i]++;
			s->i = inf->data[\
				inf->data[s->i].pipe[s->t_i_try[s->i] - 1]->n_piece].n_piece;
			s->tp_tmp[s->j] = s->i;
			s->j++;
		}
		else
			s->t_i_try[s->i]++;
	}
	if (inf->data[s->i].commands == 2)
	{
		inf->t_p = ft_update_tab_path(inf, s->tp_tmp);
		s->j--;
		s->tp_tmp[s->j] = -1;
		s->i = s->tp_tmp[s->j - 1];
	}
	else if (s->t_i_try[s->i] >= inf->data[s->i].nb_of_link)
		ft_relay(inf, s);
}

int		ft_search_path(t_infos *infos, int start)
{
	t_s s;

	s.i = start;
	s.j = 1;
	if (!(s.tp_tmp = ft_alloc_tab_int(infos->nb_of_box, -1)))
		return (0);
	if (!(s.t_i_try = ft_alloc_tab_int(infos->nb_of_box, 0)))
	{
		free(s.tp_tmp);
		return (0);
	}
	s.tp_tmp[0] = start;
	while (s.i != start || s.t_i_try[start] < infos->data[start].nb_of_link)
	{
		ft_search_path2(infos, &s);
	}
	free(s.tp_tmp);
	free(s.t_i_try);
	return (infos->t_p[0][0]);
}