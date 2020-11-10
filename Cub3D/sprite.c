/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:10:43 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/28 10:42:18 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprites_loop_affect(t_struct *prm)
{
	prm->sprite.sprt_x = 0.5 +
		prm->sprite.x[prm->sprite.sprt_ord[prm->k]] - prm->pos_x;
	prm->sprite.sprt_y = 0.5 +
		prm->sprite.y[prm->sprite.sprt_ord[prm->k]] - prm->pos_y;
	prm->sprite.inv_det = 1.0 /
		(prm->plane_x * prm->dir_y - prm->dir_x * prm->plane_y);
	prm->sprite.trans_x = prm->sprite.inv_det *
		((prm->dir_y * prm->sprite.sprt_x) -
		(prm->dir_x * prm->sprite.sprt_y));
	prm->sprite.trans_y = prm->sprite.inv_det *
		((-prm->plane_y * prm->sprite.sprt_x) +
		(prm->plane_x * prm->sprite.sprt_y));
	prm->sprite.s_sprtx = (int)((prm->win.win_width / 2) *
			(1 + prm->sprite.trans_x / prm->sprite.trans_y));
	prm->sprite.sprt_h = abs((int)
			(prm->win.win_height / prm->sprite.trans_y));
	prm->sprite.s_drawy = -prm->sprite.sprt_h / 2 + prm->win.win_height / 2;
	if (prm->sprite.s_drawy < 0)
		prm->sprite.s_drawy = 0;
	prm->sprite.e_drawy = prm->sprite.sprt_h / 2 + prm->win.win_height / 2;
	if (prm->sprite.e_drawy >= prm->win.win_height)
		prm->sprite.e_drawy = prm->win.win_height - 1;
}

static void	calc_sprt_wdt(t_struct *param)
{
	param->sprite.sprt_w = abs((int)
			(param->win.win_height / (param->sprite.trans_y)));
	param->sprite.s_drawx = -param->sprite.sprt_w / 2 + param->sprite.s_sprtx;
	if (param->sprite.s_drawx < 0)
		param->sprite.s_drawx = 0;
	param->sprite.e_drawx = param->sprite.sprt_w / 2 + param->sprite.s_sprtx;
	if (param->sprite.e_drawx >= param->win.win_width)
		param->sprite.e_drawx = param->win.win_width - 1;
}

static void	put_sprt(t_struct *prm)
{
	int		y;

	if ((prm->sprite.trans_y > 0 && prm->sprite.strip > 0) &&
			(prm->sprite.strip < prm->win.win_width) &&
			(prm->sprite.trans_y < prm->sprite.zbuff[prm->sprite.strip]))
	{
		y = prm->sprite.s_drawy;
		while (y < prm->sprite.e_drawy)
		{
			prm->sprite.dist = (y) * 256 - prm->win.win_height * 128 +
				prm->sprite.sprt_h * 128;
			prm->tex.tex_y = ((prm->sprite.dist * prm->tex.texheight) /
					prm->sprite.sprt_h) / 256;
			prm->color =
				prm->sprite.texture[(prm->sprite.sprtw * prm->tex.tex_y) +
				prm->tex.tex_x];
			if (prm->color != 9961608)
				prm->texture[prm->sprite.strip + y * prm->win.win_width] =
					prm->color;
			y++;
		}
	}
}

void		sprites_loop(t_struct *prm)
{
	prm->k = 0;
	while (prm->k < prm->sprite.num)
	{
		sprites_loop_affect(prm);
		calc_sprt_wdt(prm);
		prm->sprite.strip = prm->sprite.s_drawx;
		while (prm->sprite.strip < prm->sprite.e_drawx)
		{
			prm->tex.tex_x = (int)(256 *
					(prm->sprite.strip -
					(-prm->sprite.sprt_w / 2 + prm->sprite.s_sprtx)) *
					prm->tex.texwidth / prm->sprite.sprt_w) / 256;
			put_sprt(prm);
			prm->sprite.strip++;
		}
		prm->k++;
	}
}
