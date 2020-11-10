/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:13:24 by ichejra           #+#    #+#             */
/*   Updated: 2019/10/29 14:05:19 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	n;
	long long	sign;

	i = 0;
	n = 0;
	sign = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (n * 10 + (long long)str[i] - '0' < n)
			return (sign == 1 ? 0 : -1);
		n = (n * 10) + ((long long)str[i++] - '0');
	}
	if (sign == 1)
		return ((int)-n);
	return ((int)n);
}
