/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:29:32 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/02 11:24:23 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	if (src != NULL && dest != NULL)
	{
		if (n != 0)
		{
			while (i < (n - 1) && src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
		while (src[i] != '\0')
			i++;
		return (i);
	}
	else
		return (0);
}
