/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:10:36 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/10 11:48:26 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	if (dst == NULL || src == NULL || len == 0)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source < dest && dest < source + len)
		while (i < len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	else
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	return (dst);
}

char	*ft_fstrjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*s;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = s1 == NULL ? 0 : ft_strlen(s1);
	len2 = s2 == NULL ? 0 : ft_strlen(s2);
	if (!(s = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		s[i] = s2[i - len1];
		i++;
	}
	free(s1);
	s[i] = '\0';
	return (s);
}

char	*ft_fstrjoin_c(char *s1, char const *s2, int c)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*s;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = s1 == NULL ? 0 : ft_strlen(s1);
	len2 = s2 == NULL ? 0 : ft_strlen(s2);
	if (!(s = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (s1 && i < len1 && s1[i] != c)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && i - len1 < len2 && s2[i - len1] != c)
	{
		s[i] = s2[i - len1];
		i++;
	}
	free(s1);
	s[i] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	if (s == NULL)
		return (NULL);
	s1 = (char *)s;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return (s1 + i);
		i++;
	}
	if (s1[i] == (char)c)
		return (s1 + i);
	return (NULL);
}
