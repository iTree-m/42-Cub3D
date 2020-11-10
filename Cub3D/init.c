/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:17:34 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:12:34 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_tex_vars(t_struct *param)
{
	param->tex.tex_n = NULL;
	param->tex.tex_s = NULL;
	param->tex.tex_w = NULL;
	param->tex.tex_e = NULL;
	param->tex.tex_er = 0;
	param->tex.tex_y = 0;
	param->tex.tex_x = 0;
	param->sprite.spr = NULL;
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
}

static void	init_mov_data(t_struct *param)
{
	param->time = 0;
	param->oldtime = 0;
	param->raydir_x = 0;
	param->raydir_y = 0;
	param->camera_x = 0;
	param->sidedist_x = 0;
	param->sidedist_y = 0;
	param->deltadist_x = 0;
	param->deltadist_y = 0;
	param->perpwalldist = 0;
	param->old_dir_x = 0;
	param->old_plane_x = 0;
	param->x_step = 0;
	param->y_step = 0;
	param->side = 0;
	param->ln_height = 0;
	param->draw_end = 0;
	param->draw_start = 0;
	param->wallx = 0;
	param->x = 0;
	param->y = 0;
}

static void	init_err_vars(t_struct *param)
{
	param->err.count = 0;
	param->err.alloc = 0;
	param->err.index = 0;
	param->err.jindex = 0;
	param->err.r_index = 0;
	param->err.f_index = 0;
	param->err.c_index = 0;
	param->err.e_index = 0;
	param->err.w_index = 0;
	param->err.n_index = 0;
	param->err.so_index = 0;
	param->err.s_index = 0;
}

void		init_struct(t_struct *param)
{
	param->movespeed = 0.2;
	param->rotspeed = 0.1;
	param->map_wid = 0;
	param->map_hgt = 0;
	param->map_x = 0;
	param->map_y = 0;
	init_mov_data(param);
	param->color = 0;
	param->i_wdth = 0;
	param->i_height = 0;
	param->f_clr = 0;
	param->c_clr = 0;
	init_tex_vars(param);
	param->index = 0;
	param->sprite.num = 0;
	param->check = 0;
	param->save = 0;
	param->lng = 0;
	param->old_lng = 0;
	param->ret = 0;
	init_err_vars(param);
}
