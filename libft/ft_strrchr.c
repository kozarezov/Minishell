/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:59:19 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/03 10:59:57 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen((char*)str);
	if (len > 0)
	{
		if (ch != '\0')
		{
			while (len > 0)
			{
				if ((int)str[len - 1] == ch)
					return ((char*)str + len - 1);
				len--;
			}
		}
		else
			return ((char*)str + len);
	}
	else
	{
		if (ch == '\0')
			return ((char*)str);
	}
	return (NULL);
}
