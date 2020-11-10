/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:21:09 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/03 09:40:14 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_for_back(t_struct *prm, int *key)
{
	if (*key == 126 || *key == 13)
	{
		if (prm->map[(int)(prm->pos_x +
				(prm->dir_x * prm->movespeed))][(int)prm->pos_y] != '1')
			prm->pos_x += prm->dir_x * prm->movespeed;
		if (prm->map[(int)(prm->pos_x)][(int)(prm->pos_y +
				(prm->dir_y * prm->movespeed))] != '1')
			prm->pos_y += prm->dir_y * prm->movespeed;
	}
	if (*key == 125 || *key == 1)
	{
		if (prm->map[(int)(prm->pos_x -
				(prm->dir_x * prm->movespeed))][(int)prm->pos_y] != '1')
			prm->pos_x -= prm->dir_x * prm->movespeed;
		if (prm->map[(int)(prm->pos_x)][(int)(prm->pos_y -
				(prm->dir_y * prm->movespeed))] != '1')
			prm->pos_y -= prm->dir_y * prm->movespeed;
	}
}

static void	ft_rot_right(t_struct *prm)
{
	prm->old_dir_x = prm->dir_x;
	prm->dir_x = prm->dir_x * cos(-prm->rotspeed) -
		prm->dir_y * sin(-prm->rotspeed);
	prm->dir_y = prm->old_dir_x * sin(-prm->rotspeed) +
		prm->dir_y * cos(-prm->rotspeed);
	prm->old_plane_x = prm->plane_x;
	prm->plane_x = prm->plane_x * cos(-prm->rotspeed) -
		prm->plane_y * sin(-prm->rotspeed);
	prm->plane_y = prm->old_plane_x * sin(-prm->rotspeed) +
		prm->plane_y * cos(-prm->rotspeed);
}

static void	ft_rot_left(t_struct *prm)
{
	prm->old_dir_x = prm->dir_x;
	prm->dir_x = prm->dir_x * cos(prm->rotspeed) -
		prm->dir_y * sin(prm->rotspeed);
	prm->dir_y = prm->old_dir_x * sin(prm->rotspeed) +
		prm->dir_y * cos(prm->rotspeed);
	prm->old_plane_x = prm->plane_x;
	prm->plane_x = prm->plane_x * cos(prm->rotspeed) -
		prm->plane_y * sin(prm->rotspeed);
	prm->plane_y = prm->old_plane_x * sin(prm->rotspeed) +
		prm->plane_y * cos(prm->rotspeed);
}

static void	move_left_right(t_struct *prm, int *key)
{
	if (*key == 2)
	{
		if (prm->map[(int)(prm->pos_x + prm->dir_y *
			prm->movespeed)][(int)(prm->pos_y)] != '1')
			prm->pos_x += prm->dir_y * prm->movespeed;
		if (prm->map[(int)(prm->pos_x)][(int)(prm->pos_y -
		prm->dir_x * prm->movespeed)] != '1')
			prm->pos_y -= prm->dir_x * prm->movespeed;
	}
	if (*key == 0)
	{
		if (prm->map[(int)(prm->pos_x - prm->dir_y *
		prm->movespeed)][(int)(prm->pos_y)] != '1')
			prm->pos_x -= prm->dir_y * prm->movespeed;
		if (prm->map[(int)(prm->pos_x)][(int)(prm->pos_y +
		prm->dir_x * prm->movespeed)] != '1')
			prm->pos_y += prm->dir_x * prm->movespeed;
	}
}

int			key_press(int key, t_struct *prm)
{
	if (key == 126 || key == 13)
		ft_move_for_back(prm, &key);
	if (key == 125 || key == 1)
		ft_move_for_back(prm, &key);
	if (key == 124)
		ft_rot_right(prm);
	if (key == 123)
		ft_rot_left(prm);
	if (key == 2)
		move_left_right(prm, &key);
	if (key == 0)
		move_left_right(prm, &key);
	if (key == 53)
		exit(0);
	draw_map(prm);
	return (0);
}
