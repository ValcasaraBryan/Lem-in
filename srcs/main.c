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
	if (!(check_file(&infos, 0, 0)))
	{
		perror("ERROR ");
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(check_commandes(&infos)))
	{
		perror("ERROR ");
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(logical_infos_box(&infos)))
	{
		perror("ERROR ");
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(ft_algo(&infos)))
	{
		perror("ERROR ");
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
