/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:38:52 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/04 14:38:54 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*str;

	i = 0;
	if (s == NULL)
		return (0);
	y = (unsigned int)ft_strlen((char*)s);
	if (start + len > y)
		len = y - start;
	if (start < y)
	{
		if (!(str = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		while (i < len && s[start + i] != '\0')
		{
			str[i] = (char)s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
