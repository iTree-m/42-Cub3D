/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 10:52:52 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/07 13:01:39 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_double_key(t_struct *prm, char *ln)
{
	if ((prm->err.r_index == 1 && ln[0] == 'R')
	|| (prm->err.c_index == 1 && ln[0] == 'C')
	|| (prm->err.f_index == 1 && ln[0] == 'F')
	|| (prm->err.n_index == 1 && ln[0] == 'N' && ln[1] == 'O')
	|| (prm->err.so_index == 1 && ln[0] == 'S' && ln[1] == 'O')
	|| (prm->err.w_index == 1 && ln[0] == 'W' && ln[1] == 'E')
	|| (prm->err.e_index == 1 && ln[0] == 'E' && ln[1] == 'A')
	|| (prm->err.s_index == 1 && ln[0] == 'S'))
	{
		ft_putstr_fd("Error\nDouble Keys", 1);
		ft_free(prm);
		exit(0);
	}
}

void	alloc_fail(t_struct *prm)
{
	ft_putstr_fd("Error\nallocation failed", 1);
	ft_free(prm);
	exit(0);
}

void	check_unknown_char(t_struct *prm)
{
	ft_putstr_fd("Error\nInvalid Map", 1);
	ft_free(prm);
	exit(0);
}
