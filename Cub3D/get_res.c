/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:30:25 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/07 12:05:52 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_dig(t_struct *prm, char **ln)
{
	int		ret;

	ret = 0;
	if (!ft_isdigit(**ln))
	{
		prm->er = 'R';
		ret = 1;
	}
	return (ret);
}

static void	win_affect(t_struct *prm, char **ln, int k)
{
	if (k == 1)
	{
		prm->win.win_width = ft_atoi(*ln);
		if (prm->win.win_width > 2560)
			prm->win.win_width = 2560;
		if (prm->win.win_width == 0)
		{
			ft_putstr_fd("Error\nResolution Error", 1);
			ft_free(prm);
			exit(0);
		}
	}
	if (k == 2)
	{
		prm->win.win_height = ft_atoi(*ln);
		if (prm->win.win_height > 1440)
			prm->win.win_height = 1440;
		if (prm->win.win_height == 0)
		{
			ft_putstr_fd("Error\nResolution Error", 1);
			ft_free(prm);
			exit(0);
		}
	}
}

void		get_res(t_struct *prm, char **ln)
{
	(*ln)++;
	prm->ret = 0;
	if (**ln != ' ')
	{
		prm->er = 'R';
		return ;
	}
	skip_sp(ln);
	if ((prm->ret = check_dig(prm, ln)) == 1)
		return ;
	win_affect(prm, ln, 1);
	skip_dig(ln);
	skip_sp(ln);
	check_dig(prm, ln);
	win_affect(prm, ln, 2);
	skip_dig(ln);
	if (ft_isspace(**ln))
		skip_sp(ln);
	if (**ln != '\0' && **ln != '\n')
		prm->er = 'R';
	prm->err.count++;
	prm->err.r_index = 1;
}
