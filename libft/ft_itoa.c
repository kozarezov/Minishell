/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 08:51:14 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/06 08:51:15 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	positive_number(int z)
{
	if (z < 0)
		z = (z * (-1)) / 10;
	else
		z = z / 10;
	return (z);
}

static int	balance(int z)
{
	if (z < 0)
		z = (z % 10) * -1 + 48;
	else
		z = z % 10 + 48;
	return (z);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = n;
	while (j != 0)
	{
		j = positive_number(j);
		i++;
	}
	j = n;
	if (n <= 0)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = balance(n);
		n = positive_number(n);
	}
	if (j < 0)
		str[0] = '-';
	return (str);
}
