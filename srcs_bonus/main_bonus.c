/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:32:28 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 16:32:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int				main(int argc, char **argv)
{
	t_infos		infos;
	t_file		*head;
	data_t		p;
	t_graphe	*graphe;

	(void)argc;
	(void)argv;
	infos = get_file_bonus();
	if (!infos.file)
		erase_infos(&infos);
	if (!(init_data(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	head = infos.file;
	if (!(skip_line_fourmi(&infos)))
		return (0);
	if (!(check_file_bonus(&infos, head, 0, 0)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(check_commandes(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(add_pipe(&infos, infos.file)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!(logical_infos_box(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	if (!infos.file || !infos.data)
	{
		perror("Wrong Data ");
		return (0);
	}
	graphe = parsing_ants_file(infos.file, &infos);
	p = init_p(&infos, graphe);
	key_hook(0, &p);
	mlx_hook(p.mlx_win, 2, 0, key_hook, &p);
	mlx_do_key_autorepeaton(p.mlx_ptr);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
