/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:10:27 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/03 15:10:29 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	if (ch != '\0')
	{
		while (str[i] != '\0')
		{
			if ((int)str[i] == ch)
				return ((char*)str + i);
			i++;
		}
	}
	else
		return ((char*)str + ft_strlen((char*)str));
	return (NULL);
}
