/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:10:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/22 18:46:08 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			norm_main(t_infos *infos)
{
	if (!(check_file(infos, 0, 0)))
	{
		perror("ERROR ");
		erase_infos(infos);
		erase_data(infos);
		return (0);
	}
	if (!(check_commandes(infos)))
	{
		perror("ERROR ");
		erase_infos(infos);
		erase_data(infos);
		return (0);
	}
	if (!(add_pipe(infos, infos->file)))
	{
		perror("ERROR ");
		erase_infos(infos);
		erase_data(infos);
		return (0);
	}
	return (1);
}

int			norm_main_two(t_infos *infos)
{
	if (!(logical_infos_box(infos)))
	{
		perror("ERROR ");
		erase_infos(infos);
		erase_data(infos);
		return (0);
	}
	if (!(ft_algo(infos)))
	{
		perror("ERROR ");
		erase_infos(infos);
		erase_data(infos);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_infos	infos;

	(void)argc;
	(void)argv;
	infos = get_file();
	if (!infos.file)
	{
		perror("ERROR ");
		erase_infos(&infos);
		return (0);
	}
	if (!(init_data(&infos)))
	{
		perror("ERROR ");
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(norm_main(&infos)))
		return (0);
	if (!(norm_main_two(&infos)))
		return (0);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
