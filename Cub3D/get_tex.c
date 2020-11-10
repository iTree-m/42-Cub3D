/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:25:11 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:11:18 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_paths(t_struct *prm)
{
	ft_putstr_fd("Error\nPath Incorrect", 1);
	ft_free(prm);
	exit(0);
}

void		get_tex(t_struct *prm)
{
	if (!(prm->tex.tex_s = mlx_xpm_file_to_image(prm->win.mlx_ptr, prm->no,
		&prm->i_wdth, &prm->i_height)))
		check_paths(prm);
	if (!(prm->tex.tex_n = mlx_xpm_file_to_image(prm->win.mlx_ptr, prm->so,
		&prm->i_wdth, &prm->i_height)))
		check_paths(prm);
	if (!(prm->tex.tex_e = mlx_xpm_file_to_image(prm->win.mlx_ptr, prm->we,
		&prm->i_wdth, &prm->i_height)))
		check_paths(prm);
	if (!(prm->tex.tex_w = mlx_xpm_file_to_image(prm->win.mlx_ptr, prm->ea,
		&prm->i_wdth, &prm->i_height)))
		check_paths(prm);
	if (!(prm->sprite.img = mlx_xpm_file_to_image(prm->win.mlx_ptr,
		prm->sprite.spr, &prm->sprite.sprtw, &prm->sprite.sprth)))
		check_paths(prm);
}
