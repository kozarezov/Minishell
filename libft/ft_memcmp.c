/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 20:23:05 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/03 20:23:06 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	i;
	char	*buf1_t;
	char	*buf2_t;

	i = 0;
	buf1_t = (char*)buf1;
	buf2_t = (char*)buf2;
	if (n == 0)
		return (0);
	while ((unsigned char)buf1_t[i] == (unsigned char)buf2_t[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)buf1_t[i] - (unsigned char)buf2_t[i]);
}
