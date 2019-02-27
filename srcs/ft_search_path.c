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

int		ft_check_precedents(t_infos *infos, int *tab_path_n_piece, int n)
{
	// ft_putendl("tamere");
	int i;

	i = 0;
		// ft_putnbr(n);
		// ft_putnbr(i);
		// ft_putendl("ttggggt");
	while (i < infos->nb_of_box)
	{
		// ft_putendl("ttttttttttt");
		// ft_putnbr(tab_path_n_piece[i]);
		// ft_putendl("");
		if (tab_path_n_piece[i] == n)
			return (0);
		i++;
	}
	return (1);
}
