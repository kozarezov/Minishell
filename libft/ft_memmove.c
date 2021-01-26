/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:00:23 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/04 10:00:25 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest != 0 || src != 0)
	{
		while (i < n)
		{
			if (src < dest)
				*((char*)dest - i + n - 1) =
				*((char*)src - i + n - 1);
			else
				*((char*)dest + i) = *((char*)src + i);
			i++;
		}
	}
	return (dest);
}
