/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:49:47 by ichejra           #+#    #+#             */
/*   Updated: 2019/10/29 10:12:07 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	if (dst == NULL || src == NULL || n == 0)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (source[i] && i < n)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dst);
}
