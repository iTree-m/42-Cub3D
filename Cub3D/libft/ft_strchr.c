/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:36:55 by ichejra           #+#    #+#             */
/*   Updated: 2019/10/29 12:34:23 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
