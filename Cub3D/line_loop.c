/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:38:46 by ichejra           #+#    #+#             */
/*   Updated: 2020/11/09 12:17:24 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_dir_path(t_struct *prm, char *ln, int *check)
{
	if (*check == 1)
	{
		prm->no = ft_strtrim(ln, " ");
		prm->err.count++;
		prm->err.n_index = 1;
	}
	if (*check == 2)
	{
		prm->so = ft_strtrim(ln, " ");
		prm->err.count++;
		prm->err.so_index = 1;
	}
	if (*check == 3)
	{
		prm->we = ft_strtrim(ln, " ");
		prm->err.count++;
		prm->err.w_index = 1;
	}
	if (*check == 4)
	{
		prm->ea = ft_strtrim(ln, " ");
		prm->err.count++;
		prm->err.e_index = 1;
	}
}

static void	check_dir_path(t_struct *prm, char *ln, int check)
{
	if (ln[2] != ' ')
	{
		prm->tex.tex_er = 1;
		return ;
	}
	ln = ln + 2;
	while (*ln != '.')
	{
		if (*ln != ' ')
		{
			prm->tex.tex_er = 1;
			return ;
		}
		ln++;
	}
	get_dir_path(prm, ln, &check);
}

static void	check_sprt_path(t_struct *prm, char *ln)
{
	if (ln[1] != ' ')
	{
		prm->tex.tex_er = 1;
		return ;
	}
	ln = ln + 1;
	while (*ln != '.')
	{
		if (*ln != ' ')
		{
			prm->tex.tex_er = 1;
			return ;
		}
		ln++;
	}
	prm->sprite.spr = ft_strtrim(ln, " ");
	prm->err.count++;
	prm->err.s_index = 1;
}

static void	check_fst_char(t_struct *prm, char *ln)
{
	check_double_key(prm, ln);
	if (ln[0] == 'R')
		get_res(prm, &ln);
	else if (ln[0] == 'F')
		floor_color(prm, &ln);
	else if (ln[0] == 'C')
		ceil_color(prm, &ln);
	else if (ln[0] == 'N' && ln[1] == 'O')
		check_dir_path(prm, ln, 1);
	else if (ln[0] == 'S' && ln[1] == 'O')
		check_dir_path(prm, ln, 2);
	else if (ln[0] == 'W' && ln[1] == 'E')
		check_dir_path(prm, ln, 3);
	else if (ln[0] == 'E' && ln[1] == 'A')
		check_dir_path(prm, ln, 4);
	else if (ln[0] == 'S')
		check_sprt_path(prm, ln);
	else if (ln[0] == ' ' || ln[0] == '1')
		store_map(prm, &ln);
	else if (prm->index == 1 && ln[0] != '1' && ln[0] != ' ')
		prm->index = 2;
}

void		line_loop(t_struct *prm)
{
	int		l;
	char	*ln;

	l = 1;
	while (l == 1)
	{
		l = get_next_line(prm->fd, &ln);
		if (ln[0] != 'R' && ln[0] != 'F' && ln[0] != 'C' && ln[0] != 'N' &&
		ln[0] != 'S' && ln[0] != 'E' && ln[0] != 'W' && ln[0] != ' '
		&& ln[0] != '1' && ln[0] != '\0')
			check_unknown_char(prm);
		if ((ln[0] == 'N' && ln[1] != 'O') || (ln[0] == 'W' && ln[1] != 'E')
		|| (ln[0] == 'E' && ln[1] != 'A'))
			check_unknown_char(prm);
		check_fst_char(prm, ln);
		if (prm->err.alloc == 1)
			alloc_fail(prm);
		if (prm->index == 2 && ln[0] != '\0')
			check_unknown_char(prm);
	}
	handle_map(prm);
	free(ln);
}
