/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:29:32 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/02 11:48:29 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t n)
{
	size_t i;
	size_t y;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	y = ft_strlen(dest);
	if (n <= y)
		return (ft_strlen(src) + n);
	while ((i < (n - y - 1)) && (src[i] != '\0'))
	{
		dest[y + i] = src[i];
		i++;
	}
	dest[y + i] = '\0';
	return (ft_strlen(src) + y);
}
