/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:20:03 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:32:37 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_man(t_struct *param)
{
	if (param->er == 'R')
		ft_putstr_fd("Error\nInvalid Resolution", 1);
	else if (param->er == 'F' || param->er == 'C')
		ft_putstr_fd("Error\nInvalid floor or ceil color", 1);
	else if (param->er == 'M')
		ft_putstr_fd("Error\nInvalid Map", 1);
	else if (param->tex.tex_er == 1)
		ft_putstr_fd("Error\nInvalid Path", 1);
	else if (param->err.alloc == 1)
		ft_putstr_fd("Error\nallocation failed", 1);
	else if (!param->index)
		ft_putstr_fd("Error\nInvalid Map", 1);
	else
		return ;
	ft_free(param);
	exit(0);
}

void	err_man_missing_key(t_struct *prm)
{
	if (prm->err.count < 8)
	{
		ft_putstr_fd("Error\nMissing Informations", 1);
		ft_free(prm);
		exit(0);
	}
}
