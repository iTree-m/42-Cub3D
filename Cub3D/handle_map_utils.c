/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:03:15 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:13:46 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_err(t_struct *prm)
{
	ft_putstr_fd("Error\nInvalid Map", 1);
	ft_free(prm);
	exit(0);
}

void		check_map_er(t_struct *prm, int i, int j)
{
	if ((prm->map[i][j + 1] != '1' && prm->map[i][j + 1] != ' '))
		map_err(prm);
	if (j != 0 && prm->map[i][j - 1] != '1' && prm->map[i][j - 1] != ' ')
		map_err(prm);
	if (i != 0 && prm->map[i - 1][j] != '1' && prm->map[i - 1][j] != ' ')
	{
		if ((ft_strlen(ft_strtrim(prm->map[i - 1], " ")) <=
		ft_strlen(ft_strtrim(prm->map[i], " ")))
		&& prm->map[i - 1][j] != '0' && prm->map[i - 1][j] != '2')
			return ;
		else
			map_err(prm);
	}
	if (i != prm->map_hgt - 1 && prm->map[i + 1][j] != '1' &&
	prm->map[i + 1][j] != ' ')
	{
		if ((ft_strlen(ft_strtrim(prm->map[i + 1], " ")) <=
		ft_strlen(ft_strtrim(prm->map[i], " ")))
		&& prm->map[i + 1][j] != '0' && prm->map[i + 1][j] != '2')
			return ;
		else
			map_err(prm);
	}
}

void		check_map_er_sec(t_struct *prm, int i, int k)
{
	if (k == 1)
	{
		if (prm->map[0][i] != '1' && prm->map[0][i] != ' ')
			map_err(prm);
	}
	else if (k == 2)
	{
		prm->lng = ft_strlen(prm->map[i]);
		if (prm->map[i][prm->lng - 1] != '1')
			map_err(prm);
	}
	else if (k == 3)
	{
		if (prm->map[prm->map_hgt - 1][i] != '1' &&
				prm->map[prm->map_hgt - 1][i] != ' ')
			map_err(prm);
	}
}

static void	check_ending(t_struct *prm, int *i, int *j)
{
	*j = prm->lng - prm->old_lng;
	while (*j > 0)
	{
		if (prm->map[*i][prm->lng - *j] == '0')
			map_err(prm);
		(*j)--;
	}
}

void		check_map_len_thd(t_struct *prm, int i, int k)
{
	int		j;

	if (k == 1)
	{
		j = prm->lng - 1;
		if (i != 0)
		{
			while (++j < prm->old_lng)
			{
				if (prm->map[i - 1][j] != '1' && prm->map[i - 1][j] != ' ')
					map_err(prm);
			}
		}
	}
	if (k == 2)
		check_ending(prm, &i, &j);
}
