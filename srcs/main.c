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
	int				nb_of_box;
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
	t_infos			*infos;
}					data_t;

int			val_max_coor(t_data *data, char c)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	while (data[i].name_box)
	{
		if (c == 'x')
			if (data[i].coor_x > val)
				val = data[i].coor_x;
		if (c == 'y')
		if (data[i].coor_y > val)
			val = data[i].coor_y;
		i++;
	}
	return (val);
}

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
	p->color_carre_x = 100000000;
	p->color_carre_y = 100000000;
	p->color_interieur = 54461616;
	p->longueur = (p->longueur_win * 5) / 100;
	p->largeur = (p->largeur_win * 5) / 100;
	while (i < p->longueur_win)
	{
		j = 0;
		while (j < p->largeur_win)
		{
			mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color);	
			j++;
		}
		i++;
	}
	while (p->infos->data[p->nb_of_box].name_box)
	{
		p->centre_y = p->infos->data[p->nb_of_box].coor_y * ((p->longueur_win * 3.5) / 100); // centre du carre
		p->centre_x = p->infos->data[p->nb_of_box].coor_x * ((p->largeur_win * 3.5) / 100); // centre du carre
		i = p->centre_x;
		while (i < p->centre_x + p->longueur)
		{
			j = p->centre_y;
			while (j < p->centre_y + p->largeur)
			{
				if (i != p->centre_x && i != p->centre_x + p->longueur - 1
					&& j != p->centre_y && j != p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_interieur);
				if (i == p->centre_x || i == p->centre_x + p->longueur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_x);			
				if (j == p->centre_y || j == p->centre_y + p->largeur - 1)
					mlx_pixel_put(p->mlx_ptr, p->mlx_win, i, j, p->color_carre_y);
				j++;
			}
			i++;
		}
		printf("x = %d - y = %d\n", p->infos->data[p->nb_of_box].coor_x, p->infos->data[p->nb_of_box].coor_y);
		p->nb_of_box++;
	}
	p->nb_of_box = 0;
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
	ft_put_data(&infos);
	ft_put_list(infos.file);
	ft_fprintf("OK\n", 1);
	ft_fprintf("\\-------------------------------------------/\n\n\n", 2);
	p.infos = &infos;
	p.color = 0;
	p.nb_of_box = 0;
	p.longueur_win =  val_max_coor(infos.data, 'x') * 50;
	p.largeur_win = val_max_coor(infos.data, 'y') * 50;
	// p.longueur_win = (p.largeur_win < (p.longueur_win * 3)) ? (p.longueur_win / 2) : p.longueur_win;
	// \p.largeur_win = (p.longueur_win < (p.largeur_win * 2)) ? (p.largeur_win / 2) : p.largeur_win;
	printf("%d - %d\n", p.longueur_win, p.largeur_win);
	p.mlx_win = mlx_new_window(p.mlx_ptr, p.longueur_win, p.largeur_win, "mlx 42");
	mlx_key_hook(p.mlx_win, key_hook, &p);
	mlx_loop(p.mlx_ptr);
	erase_infos(&infos);
	erase_data(&infos);
	return (0);
}
