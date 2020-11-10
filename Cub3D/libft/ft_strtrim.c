/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:56:23 by ichejra           #+#    #+#             */
/*   Updated: 2019/10/29 13:13:50 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	if (s1 == NULL || ft_strlen(s1) == 0 || set == NULL)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && j >= i && ft_strchr(set, s1[j]))
		j--;
	if (j < i)
		return (ft_strdup(""));
	if (!(s = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	ft_memcpy(s, s1 + i, j - i + 1);
	s[j - i + 1] = '\0';
	return (s);
}
