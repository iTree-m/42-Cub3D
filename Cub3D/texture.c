/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:46:56 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/28 10:26:18 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex(t_struct *param)
{
	if (param->raydir_x > 0 && param->side == 0)
		param->data = (int *)mlx_get_data_addr(param->tex.tex_n,
				&param->bpp, &param->sl, &param->e);
	else if (param->raydir_x < 0 && param->side == 0)
		param->data = (int *)mlx_get_data_addr(param->tex.tex_s,
				&param->bpp, &param->sl, &param->e);
	if (param->raydir_x > 0)
	{
		if (param->side == 1 && param->raydir_y >= 0)
			param->data = (int *)mlx_get_data_addr(param->tex.tex_w,
					&param->bpp, &param->sl, &param->e);
		else if (param->side == 1)
			param->data = (int *)mlx_get_data_addr(param->tex.tex_e,
					&param->bpp, &param->sl, &param->e);
	}
	else
	{
		if (param->side == 1 && param->raydir_y >= 0)
			param->data = (int *)mlx_get_data_addr(param->tex.tex_w,
					&param->bpp, &param->sl, &param->e);
		else if (param->side == 1)
			param->data = (int *)mlx_get_data_addr(param->tex.tex_e,
					&param->bpp, &param->sl, &param->e);
	}
}

void	tex_loop(t_struct *prm)
{
	if (prm->side == 0)
		prm->wallx = prm->pos_y + prm->perpwalldist * prm->raydir_y;
	else
		prm->wallx = prm->pos_x + prm->perpwalldist * prm->raydir_x;
	prm->wallx -= floor(prm->wallx);
	prm->tex.tex_x = (int)(prm->wallx * (double)prm->tex.texwidth);
	if (prm->side == 0 && prm->raydir_x > 0)
		prm->tex.tex_x = prm->tex.texwidth - prm->tex.tex_x - 1;
	if (prm->side == 1 && prm->raydir_y < 0)
		prm->tex.tex_x = prm->tex.texwidth - prm->tex.tex_x - 1;
	prm->step = 1.0 * prm->tex.texheight / prm->ln_height;
	prm->tex_pos =
		((prm->draw_start - prm->win.win_height / 2 + prm->ln_height / 2) *
		prm->step);
	prm->y = prm->draw_start;
	while (prm->y < prm->draw_end)
	{
		prm->tex.tex_y = (int)prm->tex_pos & (prm->tex.texheight - 1);
		prm->tex_pos += prm->step;
		prm->color =
			prm->data[prm->tex.texwidth * prm->tex.tex_y + prm->tex.tex_x];
		(prm->side == 1) ? prm->color = (prm->color >> 1) & 8355711 : 0;
		prm->texture[prm->win.win_width * prm->y + prm->x] = prm->color;
		prm->y++;
	}
}

void	f_and_c_clr(t_struct *param)
{
	int i;
	int j;

	i = -1;
	while (++i < param->draw_start)
	{
		param->texture[param->x + i * param->win.win_width] = param->c_clr;
	}
	j = param->draw_end - 1;
	while (++j < param->win.win_height)
	{
		param->texture[param->x + param->win.win_width * j] = param->f_clr;
	}
}
