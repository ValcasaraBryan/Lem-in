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

void			norm_main(t_infos *infos)
{
	if (!(check_file_bonus(infos, NULL, 0, 0)))
	{
		erase_infos(infos);
		erase_data(infos);
	}
	if (!(check_commandes(infos)))
	{
		erase_infos(infos);
		erase_data(infos);
	}
	if (!(add_pipe(infos, infos->file)))
	{
		erase_infos(infos);
		erase_data(infos);
	}
	if (!(logical_infos_box(infos)))
	{
		erase_infos(infos);
		erase_data(infos);
	}
}

int				text_error(t_infos *infos)
{
	erase_infos(infos);
	erase_data(infos);
	perror("Wrong Data ");
	return (0);
}

int				main(void)
{
	t_infos		infos;
	t_data_p	p;

	infos = get_file_bonus();
	if (!infos.file || infos.nb_of_fourmis <= 0)
		erase_infos(&infos);
	if (!(init_data(&infos)))
	{
		erase_infos(&infos);
		erase_data(&infos);
	}
	norm_main(&infos);
	if (!infos.file || !infos.data)
		return (text_error(&infos));
	p = init_p(&infos, parsing_ants_file(infos.file, &infos));
	send_usage();
	if (!p.mlx_win)
		return (erase_all(&p, 0));
	key_hook(49, &p);
	mlx_hook(p.mlx_win, 2, 0, key_hook, &p);
	mlx_do_key_autorepeaton(p.mlx_ptr);
	mlx_loop(p.mlx_ptr);
	return (0);
}
