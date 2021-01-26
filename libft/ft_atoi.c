/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:53:28 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/02 18:28:18 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	size_t					i;
	size_t					count;
	unsigned long long int	res;

	i = 0;
	count = 0;
	res = 0;
	while ((str[i] < 58 && str[i] > 47) || (((str[i] < 14 && str[i] > 8) ||
	str[i] == 32) && count == 0) || ((str[i] == 43 || str[i] == 45) &&
	(str[i + 1] < 58 && str[i + 1] > 47 && count == 0)))
	{
		if (str[i] < 58 && str[i] > 47)
		{
			res = (str[i] - 0x30) + res * 10;
			count++;
			if (res > 2147483647 && str[i - count] != 45)
				return (-1);
			if (res > 2147483648 && str[i - count] == 45)
				return (0);
		}
		i++;
	}
	if (str[i - count - 1] == 45)
		return ((int)(res * -1));
	return ((int)res);
}
