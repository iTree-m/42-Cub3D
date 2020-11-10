/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:06:51 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/28 10:23:04 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		protectline(int fd, char **line, char *s, int flag)
{
	if (flag == 0)
	{
		if (!(*line = ft_fstrjoin_c(*line, s, '\n')))
			get_next_line(fd, NULL);
	}
	if (flag == 1)
	{
		if (!(*line = ft_fstrjoin(*line, s)))
			get_next_line(fd, NULL);
	}
}

static int		line_loop(int fd, char **s, char **line, t_gnl *vars)
{
	char		*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((vars->res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[vars->res] = '\0';
		vars->index = 1;
		if ((vars->s2 = ft_strchr(buff, '\n')))
		{
			if (!(*s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
				return (-1);
			protectline(fd, line, buff, 0);
			ft_memmove(*s, vars->s2 + 1, vars->res - (vars->s2 - buff));
			break ;
		}
		else
		{
			protectline(fd, line, buff, 1);
			(ft_strchr(buff, '\0')) ? vars->index = 0 : 0;
		}
	}
	free(buff);
	return (vars->res == -1 ? -1 : vars->index);
}

static char		*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		dup[len] = s1[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

static void		init_vars(t_gnl *vars, char **ln)
{
	vars->flag = 0;
	vars->index = 0;
	vars->res = 0;
	*ln = ft_strdup("");
}

int				get_next_line(int fd, char **line)
{
	t_gnl		vars;
	static char	*s;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	init_vars(&vars, line);
	if (s && !(ft_strchr(s, '\n')))
	{
		protectline(fd, line, s, 1);
		if (ft_strchr(s, '\0'))
		{
			vars.flag = 0;
			(s) ? free(s) : 0;
		}
		else
			vars.flag = 1;
	}
	else if (s && (vars.s1 = ft_strchr(s, '\n')))
	{
		protectline(fd, line, s, 0);
		ft_memmove(s, vars.s1 + 1, ft_strlen(vars.s1 + 1) + 1);
		return (1);
	}
	return (line_loop(fd, &s, line, &vars) || vars.flag);
}
