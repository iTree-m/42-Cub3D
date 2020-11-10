/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:23:57 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/07 12:04:16 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_chars(t_struct *prm)
{
	int i;
	int j;

	i = -1;
	while (++i < prm->map_hgt)
	{
		j = -1;
		while (++j < prm->lng - 2)
		{
			if (prm->map[i][j] != '0' && prm->map[i][j] != '1'
			&& prm->map[i][j] != ' ' && prm->map[i][j] != '2'
			&& prm->map[i][j] != 'N' && prm->map[i][j] != 'S'
			&& prm->map[i][j] != 'E' && prm->map[i][j] != 'W')
			{
				ft_putstr_fd("Error\nInvalid Map", 1);
				ft_free(prm);
				exit(0);
			}
		}
	}
}
