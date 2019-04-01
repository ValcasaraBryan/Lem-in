/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weights.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:08:40 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/21 18:08:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEIGHTS_H
# define WEIGHTS_H

# define W weight
# define C commands
# define NP n_piece
# define I inf

typedef struct	s_w
{
	int			j;
	int			k;
	int			k2;
	int			*tab;
	int			*tab2;
}				t_w;

#endif
