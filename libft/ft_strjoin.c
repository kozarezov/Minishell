/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:27:19 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/04 16:27:21 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	j = ft_strlen((char*)s1);
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen((char*)s1) +
	sizeof(char) * ft_strlen((char*)s2) + 1)))
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - j] != '\0')
	{
		str[i] = s2[i - j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
