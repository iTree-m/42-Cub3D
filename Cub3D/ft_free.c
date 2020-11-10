/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:10:08 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 11:09:23 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free(t_struct *prm)
{
	int	i;

	i = -1;
	if (prm->map != NULL)
	{
		while (++i < prm->map_hgt)
			free(prm->map[i]);
	}
	(prm->sprite.x != 0) ? free(prm->sprite.x) : 0;
	(prm->sprite.y != 0) ? free(prm->sprite.y) : 0;
	(prm->sprite.sprt_ord != 0) ? free(prm->sprite.sprt_ord) : 0;
	(prm->sprite.sprt_dist != 0) ? free(prm->sprite.sprt_dist) : 0;
	(prm->sprite.zbuff != 0) ? free(prm->sprite.zbuff) : 0;
	(prm->no != NULL) ? free(prm->no) : 0;
	(prm->so != NULL) ? free(prm->so) : 0;
	(prm->ea != NULL) ? free(prm->ea) : 0;
	(prm->we != NULL) ? free(prm->we) : 0;
	(prm->sprite.spr != NULL) ? free(prm->sprite.spr) : 0;
}
