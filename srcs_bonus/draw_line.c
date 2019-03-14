/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:55:02 by brvalcas          #+#    #+#             */
/*   Updated: 2019/03/13 15:55:03 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int				absolute_value(int nb)
{
	return (nb < 0 ? -nb : nb);
}

static t_line	setup_params(t_pos a, t_pos b)
{
	t_line		params;

	params.sign_y = (a.y < b.y ? 1 : -1);
	params.sign_x = (a.x < b.x ? 1 : -1);
	params.delta_y = absolute_value(b.y - a.y);
	params.delta_x = absolute_value(b.x - a.x);
	params.offset = params.delta_x - params.delta_y;
	params.error = 0;
	return (params);
}

void			draw_line(t_pos a, t_pos b, data_t *env, int color)
{
	t_line		params;
	t_pos		p;

	params = setup_params(a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		mlx_pixel_put(env->mlx_ptr, env->mlx_win, p.x, p.y, color);
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	mlx_pixel_put(env->mlx_ptr, env->mlx_win, p.x, p.y, color);
}

void			print(data_t *env, int i)
{
	t_pos		a;
	t_pos		b;

	a.x = env->grille_x[env->graphe->lem->data->pipe[i]->coor_x];
	a.y = env->grille_y[env->graphe->lem->data->pipe[i]->coor_y];
	b.x = env->grille_x[env->graphe->lem->data->coor_x];
	b.y = env->grille_y[env->graphe->lem->data->coor_y];
	draw_line(a, b, env, env->graphe->lem->color_ants);
}
