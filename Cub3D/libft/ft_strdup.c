/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:00:24 by ichejra           #+#    #+#             */
/*   Updated: 2019/10/29 13:07:23 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
