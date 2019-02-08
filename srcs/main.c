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

typedef struct		data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				longueur_win;
	int				largeur_win;
	int				color;
	int				color_carre_x;
	int				color_carre_y;
	int				color_interieur;
	int				centre_x;
	int				centre_y;
	int				longueur;
	int				largeur;
}					data_t;

int			key_hook(int keycode, data_t *p)
{
	int i;
	int j;

	i = 0;
	if (keycode == 36)
		printf("ENTREE\n");
	else if (keycode == 53)
		printf("ESC\n");
	else if (keycode == 126)
	{
		p->color++;
		printf("HAUT %d\n", p->color);
	}
	else if (keycode == 125)
	{
		p->color--;
		printf("BAS %d\n", p->color);
	}
	else if (keycode == 123)
	{
		p->color -= 15;
		printf("GAUCHE %d\n", p->color);
	}
	else if (keycode == 124)
	{
		p->color += 15;
		printf("DROIT %d\n", p->color);
	}
	else if (keycode == 67)
	{
		p->color *= 10;
		printf("* %d\n", p->color);
	}
	else if (keycode == 69)
	{
		p->color += 100;
		printf("+ %d\n", p->color);
	}
	else if (keycode == 78)
	{
		p->color -= 100;
		printf("- %d\n", p->color);
	}
	else if (keycode == 75)
	{
		p->color /= 10;
		printf("/ %d\n", p->color);
	}
	else
		printf("%d\n", keycode);
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color);	
			j++;
		}
		i++;
	}
	i = p->centre_x;
	while (i < p->centre_x + p->largeur)
	{
		j = p->centre_y;
		while (j < p->centre_y + p->longueur)
		{
			if (i != p->centre_x && i != p->centre_x + p->largeur - 1
				&& j != p->centre_y && j != p->centre_y + p->longueur - 1)
				mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_interieur);
			if (i == p->centre_x || i == p->centre_x + p->largeur - 1)
				mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_x);			
			if (j == p->centre_y || j == p->centre_y + p->longueur - 1)
				mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_y);
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
	p.color = 0;
	p.color_carre_x = 100000000;
	p.color_carre_y = 100000000;
	p.color_interieur = 54461616;
	p.longueur_win = 500;
	p.largeur_win = 500;
	p.longueur = 50;
	p.largeur = 50;
	p.centre_x = infos.data[0].coor_x + (p.longueur / 2); // centre du carre
	p.centre_y = infos.data[0].coor_y + (p.largeur / 2); // centre du carre
	p.mlx_win = mlx_new_window(p.mlx_ptr, p.longueur_win, p.largeur_win, "mlx 42");
	mlx_key_hook(p.mlx_win, key_hook, &p);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
