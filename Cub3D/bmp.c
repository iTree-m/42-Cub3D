/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 12:08:26 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/27 16:21:05 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		write_body(t_struct *prm, t_bmp *bmp)
{
	int			x;
	int			y;

	y = prm->win.win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < prm->win.win_width)
		{
			bmp->img_bmp[bmp->index++] =
				prm->texture[y * prm->win.win_width + x] >> 0;
			bmp->img_bmp[bmp->index++] =
				prm->texture[y * prm->win.win_width + x] >> 8;
			bmp->img_bmp[bmp->index++] =
				prm->texture[y * prm->win.win_width + x] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (prm->win.win_width * 3) % 4) % 4)
		{
			bmp->img_bmp[bmp->index++] = 0;
			x++;
		}
		y--;
	}
}

static void		write_int(t_bmp *bmp, unsigned int val)
{
	bmp->img_bmp[bmp->index++] = val >> 0;
	bmp->img_bmp[bmp->index++] = val >> 8;
	bmp->img_bmp[bmp->index++] = val >> 16;
	bmp->img_bmp[bmp->index++] = val >> 24;
}

static void		write_header_file(t_bmp *bmp)
{
	bmp->img_bmp[bmp->index++] = 'B';
	bmp->img_bmp[bmp->index++] = 'M';
	write_int(bmp, bmp->size);
	write_int(bmp, 0x00000000);
	bmp->img_bmp[bmp->index++] = 54;
	bmp->img_bmp[bmp->index++] = 0;
	bmp->img_bmp[bmp->index++] = 0;
	bmp->img_bmp[bmp->index++] = 0;
}

static void		write_file_info(t_struct *param, t_bmp *bmp)
{
	int			i;

	bmp->img_bmp[bmp->index++] = 40;
	bmp->img_bmp[bmp->index++] = 0;
	bmp->img_bmp[bmp->index++] = 0;
	bmp->img_bmp[bmp->index++] = 0;
	write_int(bmp, param->win.win_width);
	write_int(bmp, param->win.win_height);
	bmp->img_bmp[bmp->index++] = 1;
	bmp->img_bmp[bmp->index++] = 0;
	bmp->img_bmp[bmp->index++] = 24;
	bmp->img_bmp[bmp->index++] = 0;
	i = 0;
	while (i < 24)
	{
		bmp->img_bmp[bmp->index++] = 0;
		i++;
	}
}

int				ft_save(t_struct *prm, char *filename)
{
	int			fd;
	t_bmp		bmp;

	bmp.index = 0;
	bmp.size = 54 + 3 * prm->win.win_width * prm->win.win_height;
	if (!(bmp.img_bmp = malloc(bmp.size)))
	{
		prm->err.alloc = 1;
		free(bmp.img_bmp);
		return (-1);
	}
	if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
		return (-1);
	write_header_file(&bmp);
	write_file_info(prm, &bmp);
	write_body(prm, &bmp);
	write(fd, bmp.img_bmp, bmp.size);
	close(fd);
	free(bmp.img_bmp);
	return (0);
}
