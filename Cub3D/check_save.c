/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:57:22 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/04 11:58:57 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_save(char **argv, t_struct *param)
{
	if (argv[2] != NULL)
	{
		if (argv[2][0] == '-' && argv[2][1] == '-' &&
		argv[2][2] == 's' && argv[2][3] == 'a' && argv[2][4] == 'v'
		&& argv[2][5] == 'e')
		{
			param->save = 1;
			draw_map(param);
			ft_save(param, "cub3d.bmp");
			exit(0);
		}
	}
	return (-1);
}
