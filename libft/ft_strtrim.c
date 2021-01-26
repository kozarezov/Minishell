/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:54:29 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/04 16:54:31 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		f;
	char	*str;

	if (s1 != NULL && (str = (char*)malloc(sizeof(char) *
	ft_strlen((char*)s1) + 1)))
	{
		s = 0;
		f = ft_strlen((char*)s1);
		while (ft_strchr(set, s1[s]) != NULL && s <= f)
			s++;
		while (ft_strchr(set, s1[f - 1]) != NULL && f - 1 > 0)
			f--;
		if (f != 0 || s <= f)
			str[f - s] = '\0';
		if (f != 0 || s <= f)
			while (s < --f + 1)
				str[f - s] = s1[f];
		else
			str[0] = '\0';
		return (str);
	}
	return (NULL);
}
