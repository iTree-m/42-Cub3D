/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:46:52 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/04 14:32:39 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_c_err(t_struct *prm, int *x)
{
	prm->er = 'C';
	*x = 1;
}

static int	check_err(t_struct *prm, char **ln, int i)
{
	int		x;

	x = 0;
	if (i == 1)
	{
		if (!ft_isdigit(**ln))
			get_c_err(prm, &x);
	}
	else if (i == 2)
	{
		if (**ln != ' ')
			get_c_err(prm, &x);
		skip_sp(ln);
	}
	else if (i == 3)
	{
		if (**ln != ',')
			get_c_err(prm, &x);
	}
	return (x);
}

static void	get_c_clr(t_struct *prm, char **ln)
{
	prm->c_clr = (prm->r << 16) + (prm->g << 8) + prm->b;
	skip_dig(ln);
	skip_sp(ln);
	prm->err.count++;
	prm->err.c_index = 1;
}

static int	check_limit_and_terminal(t_struct *prm, char **ln, int k)
{
	int		x;

	x = 0;
	if (k == 1)
	{
		if (prm->r > 255 || prm->g > 255 || prm->b > 255)
		{
			prm->er = 'C';
			x = 1;
		}
	}
	if (k == 2)
	{
		if (**ln != '\0' && **ln != '\n')
		{
			prm->er = 'C';
			x = 1;
		}
	}
	return (x);
}

void		ceil_color(t_struct *prm, char **ln)
{
	prm->ret = 0;
	(*ln)++;
	if ((prm->ret = check_err(prm, ln, 2)) == 1)
		return ;
	if ((prm->ret = check_err(prm, ln, 1)) == 1)
		return ;
	prm->r = ft_atoi(*ln);
	skip_dig(ln);
	if ((prm->ret = check_err(prm, ln, 3)) == 1)
		return ;
	(*ln)++;
	if ((prm->ret = check_err(prm, ln, 1)) == 1)
		return ;
	prm->g = ft_atoi(*ln);
	skip_dig(ln);
	if ((prm->ret = check_err(prm, ln, 3)) == 1)
		return ;
	(*ln)++;
	if ((prm->ret = check_err(prm, ln, 1)) == 1)
		return ;
	prm->b = ft_atoi(*ln);
	if ((prm->ret = check_limit_and_terminal(prm, ln, 1)) == 1)
		return ;
	get_c_clr(prm, ln);
	check_limit_and_terminal(prm, ln, 2);
}
