/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:33:52 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:34:09 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_close(t_struct *param)
{
	(void)param;
	exit(0);
}

static void		if_failed_alloc(t_struct *param)
{
	if (param->err.alloc == 1)
	{
		ft_putstr_fd("Error\nallocation failed", 1);
		ft_free(param);
		exit(0);
	}
}

static void		ft_tools(t_struct *param, int k)
{
	if (k == 1)
	{
		param->win.win_ptr = mlx_new_window(param->win.mlx_ptr,
			param->win.win_width, param->win.win_height, "Cub3D");
		param->tex.texwidth = param->i_wdth;
		param->tex.texheight = param->i_height;
	}
	if (k == 2)
	{
		mlx_hook(param->win.win_ptr, 2, 0, key_press, param);
		mlx_hook(param->win.win_ptr, 17, 0, ft_close, param);
		mlx_loop(param->win.mlx_ptr);
	}
}

static void		check_arg(int ac, char **av, int i)
{
	if (i == 1)
	{
		if (ac < 2 || ac > 3)
		{
			ft_putstr_fd("Error\nArguments not valid", 1);
			exit(0);
		}
	}
	if (i == 2)
	{
		if (ac == 3 && (ft_strcmp(av[2], "--save") != 0))
		{
			ft_putstr_fd("Error\nArguments not valid", 1);
			exit(0);
		}
	}
}

int				main(int ac, char **av)
{
	t_struct	param;

	init_struct(&param);
	if ((param.fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nInvalid Map", 1);
		exit(0);
	}
	check_arg(ac, av, 1);
	line_loop(&param);
	close(param.fd);
	error_man(&param);
	err_man_missing_key(&param);
	check_arg(ac, av, 2);
	param.win.mlx_ptr = mlx_init();
	get_tex(&param);
	ft_tools(&param, 1);
	(ac == 3) ? check_save(av, &param) : 0;
	if_failed_alloc(&param);
	draw_map(&param);
	if_failed_alloc(&param);
	ft_tools(&param, 2);
	ft_free(&param);
	return (0);
}
