/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:17:00 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/06 10:39:43 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_loop(t_struct *param)
{
	int i;
	int j;
	int	z;

	i = 0;
	z = 0;
	while (i < param->map_hgt)
	{
		j = 0;
		while (j < param->map_wid)
		{
			if (param->map[i][j] == '2')
			{
				while (z < param->sprite.num)
				{
					param->sprite.x[z] = i;
					param->sprite.y[z] = j;
					z++;
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

void	wall_hit(t_struct *param)
{
	while (param->hit == 0)
	{
		if (param->sidedist_x < param->sidedist_y)
		{
			param->sidedist_x += param->deltadist_x;
			param->map_x += param->x_step;
			param->side = 0;
		}
		else
		{
			param->sidedist_y += param->deltadist_y;
			param->map_y += param->y_step;
			param->side = 1;
		}
		if (param->map[param->map_x][param->map_y] == '1')
			param->hit = 1;
	}
}

void	player_step(t_struct *prm)
{
	if (prm->raydir_x < 0)
	{
		prm->x_step = -1;
		prm->sidedist_x = (prm->pos_x - prm->map_x) * prm->deltadist_x;
	}
	else
	{
		prm->x_step = 1;
		prm->sidedist_x = (prm->map_x + 1.0 - prm->pos_x) * prm->deltadist_x;
	}
	if (prm->raydir_y < 0)
	{
		prm->y_step = -1;
		prm->sidedist_y = (prm->pos_y - prm->map_y) * prm->deltadist_y;
	}
	else
	{
		prm->y_step = 1;
		prm->sidedist_y = (prm->map_y + 1.0 - prm->pos_y) * prm->deltadist_y;
	}
}
