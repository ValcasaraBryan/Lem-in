/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:10:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/31 14:36:39 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			main(int argc, char **argv)
{
	t_infos	infos;

	(void)argc;
	(void)argv;
	ft_fprintf("/-------------------------------------------\\\n", 2);
	infos = get_file();
	if (!infos.file)
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		return (0);
	}
	if (!(init_data(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		return (0);
	}
	if (!(check_file(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		return (0);
	}
	if (!(check_commandes(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		return (0);
	}
	if (!(logical_infos_box(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		return (0);
	}
	// ft_algo(&infos);
	// ft_put_data(&infos);
	// ft_fprintf("nb_of_fourmi = %d\n", 2, infos.nb_of_fourmis);
	// ft_fprintf("nb_of_box = %d\n", 2, infos.nb_of_box);
	// ft_fprintf("nb_of_pipe = %d\n", 2, infos.nb_of_pipe);
	// ft_fprintf("infos = %p\n", 2, infos);
	// ft_fprintf("file = %p\n", 2, infos.file);
	// ft_fprintf("data = %p\n", 2, infos.data);
	// ft_fprintf("data->pipe = %p\n\n", 2, infos.data->pipe);
	ft_put_list(infos.file);
	ft_fprintf("OK\n", 1);
	ft_fprintf("\\-------------------------------------------/\n\n\n", 2);
	return (0);
}
