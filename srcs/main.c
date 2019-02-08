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
#include <mlx.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

int			key_hook(int keycode, data_t *param)
{
	int i;
	int j;

	i = 0;
	if (keycode == 36)
		printf("ENTREE\n");
	else if (keycode == 53)
		printf("ESC\n");
	else if (keycode == 126)
		printf("HAUT\n");
	else if (keycode == 125)
		printf("BAS\n");
	else if (keycode == 123)
		printf("GAUCHE\n");
	else if (keycode == 124)
		printf("DROIT\n");
	else
		printf("%d\n", keycode);
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(param->mlx_ptr, param->mlx_win, i, j, keycode * 50);	
			j++;
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	data_t	p;
	t_infos	infos;

	(void)argc;
	(void)argv;
	(void)p;
	p.mlx_ptr = mlx_init();
	ft_fprintf("/-------------------------------------------\\\n", 2);
	infos = get_file();
	
	if (!infos.file)
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		return (0);
	}
	if (!(init_data(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(check_file(&infos, 0, 0)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(check_commandes(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}
	if (!(logical_infos_box(&infos)))
	{
		perror("ERROR ");
		ft_fprintf("\\-------------------------------------------/\n\n\n\n", 2);
		erase_infos(&infos);
		erase_data(&infos);
		return (0);
	}

	// ft_algo(&infos);
	// ft_put_data(&infos);
	ft_put_list(infos.file);
	ft_fprintf("OK\n", 1);
	ft_fprintf("\\-------------------------------------------/\n\n\n", 2);
	erase_infos(&infos);
	erase_data(&infos);
	
	p.mlx_win = mlx_new_window(p.mlx_ptr, 500, 500, "mlx 42");
	mlx_key_hook(p.mlx_win, key_hook, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
