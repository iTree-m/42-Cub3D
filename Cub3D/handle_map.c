/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:33:37 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:15:26 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	manage_dir_affect(t_struct *prm, int k)
{
	if (k == 1)
	{
		prm->plane_x = 0.0;
		prm->plane_y = -0.66;
		prm->dir_x = 1.0;
		prm->dir_y = 0.0;
	}
	else if (k == 2)
	{
		prm->plane_x = 0.0;
		prm->plane_y = 0.66;
		prm->dir_x = -1.0;
		prm->dir_y = 0.0;
	}
	else if (k == 3)
	{
		prm->plane_x = 0.66;
		prm->plane_y = 0.0;
		prm->dir_x = 0.0;
		prm->dir_y = 1.0;
	}
}

static void	manage_dir(t_struct *prm, int i, int j)
{
	prm->pos_x = i + 0.5;
	prm->pos_y = j + 0.5;
	if (prm->err.jindex == 2)
	{
		ft_putstr_fd("Error\nDouble Position", 1);
		ft_free(prm);
		exit(0);
	}
	if (prm->map[i][j] == 'S')
		manage_dir_affect(prm, 1);
	else if (prm->map[i][j] == 'N')
		manage_dir_affect(prm, 2);
	else if (prm->map[i][j] == 'E')
		manage_dir_affect(prm, 3);
	else if (prm->map[i][j] == 'W')
	{
		prm->plane_x = -0.66;
		prm->plane_y = 0.0;
		prm->dir_x = 0.0;
		prm->dir_y = -1.0;
	}
	prm->err.jindex = 2;
}

static void	get_map_len_affect(t_struct *prm, int i)
{
	int		j;

	prm->old_lng = prm->lng;
	prm->lng = (int)ft_strlen(prm->map[i]);
	if (prm->map_wid < prm->lng)
		prm->map_wid = prm->lng;
	j = -1;
	while (++j < prm->lng)
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

static void	get_map_len(t_struct *prm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < prm->map_hgt)
	{
		j = -1;
		get_map_len_affect(prm, i);
		while (++j < prm->lng)
		{
			if (prm->map[i][j] == ' ')
				check_map_er(prm, i, j);
			else if (prm->map[i][j] == 'N' || prm->map[i][j] == 'S' ||
					prm->map[i][j] == 'E' || prm->map[i][j] == 'W')
				manage_dir(prm, i, j);
			else if (prm->map[i][j] == '2')
				prm->sprite.num++;
		}
		(prm->old_lng > prm->lng) ? check_map_len_thd(prm, i, 1) : 0;
		(prm->lng > prm->old_lng) ? check_map_len_thd(prm, i, 2) : 0;
	}
}

void		handle_map(t_struct *prm)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	j = -1;
	if (!prm->map)
	{
		ft_putstr_fd("Error\nInvalid Map", 1);
		ft_free(prm);
		exit(0);
	}
	while (++j < (int)ft_strlen(prm->map[0]))
		check_map_er_sec(prm, j, 1);
	i = -1;
	while (++i < prm->map_hgt)
		check_map_er_sec(prm, i, 2);
	j = -1;
	while (++j < (int)ft_strlen(prm->map[prm->map_hgt - 1]))
		check_map_er_sec(prm, j, 3);
	get_map_len(prm);
	(prm->err.jindex != 2) ? prm->er = 'M' : 0;
}
