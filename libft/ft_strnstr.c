/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:27:00 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/03 14:27:03 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t length)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*str2)
		return ((char *)str1);
	while (i <= length)
	{
		if (str2[0] == str1[i])
		{
			j = 0;
			while (str2[j] == str1[i + j] && str2[j] != 0 && i + j <
			length && str1[i + j] != '\0')
				j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		i++;
	}
	return (0);
}
