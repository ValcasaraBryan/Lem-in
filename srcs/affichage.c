/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:53:30 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/29 14:53:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_put_list(t_file *file)
{
	while (file)
	{
		ft_putendl_fd(file->line, 1);
		file = file->next;
	}
	ft_putchar_fd('\n', 1);
}
