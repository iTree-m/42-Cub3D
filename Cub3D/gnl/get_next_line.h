/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:32:08 by ichejra           #+#    #+#             */
/*   Updated: 2020/10/27 16:13:43 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_gnl
{
	int			flag;
	int			index;
	int			res;
	char		*s1;
	char		*s2;
}				t_gnl;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_fstrjoin(char *s1, char *s2);
char			*ft_fstrjoin_c(char *s1, char const *s2, int c);
char			*ft_strchr(const char *s, int c);

#endif
