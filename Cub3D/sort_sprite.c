/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:13:21 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/28 10:27:04 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_dist(int i, int j, t_struct *param)
{
	int		tmp;

	tmp = param->sprite.sprt_dist[i];
	param->sprite.sprt_dist[i] = param->sprite.sprt_dist[j];
	param->sprite.sprt_dist[j] = tmp;
}

static void	swap_order(int i, int j, t_struct *param)
{
	int		tmp;

	tmp = param->sprite.sprt_ord[i];
	param->sprite.sprt_ord[i] = param->sprite.sprt_ord[j];
	param->sprite.sprt_ord[j] = tmp;
	swap_dist(i, j, param);
}

void		sortsprites(t_struct *prm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < prm->sprite.num)
	{
		prm->sprite.sprt_ord[i] = i;
		prm->sprite.sprt_dist[i] = (((prm->pos_x - prm->sprite.x[i]) *
					(prm->pos_x - prm->sprite.x[i])) +
				((prm->pos_y - prm->sprite.y[i]) *
				(prm->pos_y - prm->sprite.y[i])));
	}
	i = -1;
	while (++i < prm->sprite.num - 1)
	{
		j = i;
		while (j < prm->sprite.num)
		{
			if (prm->sprite.sprt_dist[i] < prm->sprite.sprt_dist[j])
				swap_order(i, j, prm);
			j++;
		}
	}
}
