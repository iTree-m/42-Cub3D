/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:11:36 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/06 11:01:30 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_map_loop_affect(t_struct *param)
{
	param->camera_x = 2 * param->x / (double)param->win.win_width - 1;
	param->raydir_x = param->dir_x + param->plane_x * param->camera_x;
	param->raydir_y = param->dir_y + param->plane_y * param->camera_x;
	param->map_x = (int)param->pos_x;
	param->map_y = (int)param->pos_y;
	param->deltadist_x = fabs(1 / param->raydir_x);
	param->deltadist_y = fabs(1 / param->raydir_y);
	param->hit = 0;
}

static void	draw_map_loop(t_struct *prm)
{
	prm->x = 0;
	while (prm->x < prm->win.win_width)
	{
		draw_map_loop_affect(prm);
		player_step(prm);
		wall_hit(prm);
		if (prm->side == 0)
			prm->perpwalldist = (prm->map_x - prm->pos_x +
				((1 - prm->x_step) / 2)) / prm->raydir_x;
		else
			prm->perpwalldist = (prm->map_y - prm->pos_y +
				((1 - prm->y_step)) / 2) / prm->raydir_y;
		prm->ln_height = (int)(prm->win.win_height / prm->perpwalldist);
		prm->draw_start = -prm->ln_height / 2 + prm->win.win_height / 2;
		if (prm->draw_start < 0)
			prm->draw_start = 0;
		prm->draw_end = prm->ln_height / 2 + prm->win.win_height / 2;
		if (prm->draw_end >= prm->win.win_height)
			prm->draw_end = prm->win.win_height - 1;
		set_tex(prm);
		tex_loop(prm);
		f_and_c_clr(prm);
		prm->sprite.zbuff[prm->x] = prm->perpwalldist;
		prm->x++;
	}
}

static int	draw_map_alloc(t_struct *prm, int k)
{
	if (k == 1)
		if (!(prm->sprite.zbuff = (double *)malloc((prm->win.win_width + 1) *
						sizeof(double))))
		{
			prm->err.alloc = 1;
			return (-1);
		}
	if (k == 2)
		if (!(prm->sprite.x = (int *)malloc((prm->sprite.num + 1) *
			sizeof(int))) || !(prm->sprite.y =
				(int *)malloc((prm->sprite.num + 1) * sizeof(int))))
		{
			prm->err.alloc = 1;
			return (-1);
		}
	if (k == 2)
		if (!(prm->sprite.sprt_ord = (int *)malloc(sizeof(int) *
			(prm->sprite.num + 1))) || !(prm->sprite.sprt_dist =
			(double *)malloc(sizeof(double) * (prm->sprite.num + 1))))
		{
			prm->err.alloc = 1;
			return (-1);
		}
	return (1);
}

void		draw_map(t_struct *param)
{
	int		x;

	x = 0;
	if ((x = draw_map_alloc(param, 1)) != 1)
		return ;
	mlx_clear_window(param->win.mlx_ptr, param->win.win_ptr);
	param->img = mlx_new_image(param->win.mlx_ptr, param->win.win_width,
		param->win.win_height);
	param->texture = (int *)mlx_get_data_addr(param->img, &param->bpp,
		&param->sl, &param->e);
	draw_map_loop(param);
	if ((x = draw_map_alloc(param, 2)) != 1)
		return ;
	sprite_loop(param);
	param->sprite.texture = (int *)mlx_get_data_addr(param->sprite.img,
	&param->sprite.s_bpp, &param->sprite.s_sl, &param->sprite.s_en);
	if ((x = draw_map_alloc(param, 3)) != 1)
		return ;
	sortsprites(param);
	sprites_loop(param);
	mlx_put_image_to_window(param->win.mlx_ptr, param->win.win_ptr,
		param->img, 0, 0);
	if (param->save == 0)
		mlx_destroy_image(param->win.mlx_ptr, param->img);
}
