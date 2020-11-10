/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:56:38 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 11:55:19 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_old_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_map_len(t_struct *prm)
{
	int		i;

	i = 0;
	while (prm->map[i] != '\0')
		i++;
	return (i);
}

static char	**ft_new_map(t_struct *prm)
{
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*))))
	{
		prm->err.alloc = 1;
		return (NULL);
	}
	*map = NULL;
	return (map);
}

static char	**ft_add_to_map(t_struct *prm, char **line)
{
	int		len;
	int		i;
	char	**new_tab;

	i = 0;
	len = ft_map_len(prm);
	if (!(new_tab = (char**)malloc(sizeof(char*) * (len + 2))))
	{
		prm->err.alloc = 1;
		return (NULL);
	}
	while (i < len)
	{
		new_tab[i] = ft_strdup(prm->map[i]);
		i++;
	}
	new_tab[i] = ft_strdup(*line);
	new_tab[++i] = NULL;
	clear_old_tab(prm->map);
	return (new_tab);
}

void		store_map(t_struct *prm, char **ln)
{
	if (prm->index == 2)
		return ;
	if (!prm->map)
		prm->map = ft_new_map(prm);
	if (prm->err.alloc == 1)
	{
		ft_putstr_fd("Error\nallocation failed", 1);
		ft_free(prm);
		exit(0);
	}
	prm->map_hgt++;
	prm->map = ft_add_to_map(prm, ln);
	if (prm->err.alloc == 1)
	{
		ft_putstr_fd("Error\nallocation failed", 1);
		ft_free(prm);
		exit(0);
	}
	prm->index = 1;
}
