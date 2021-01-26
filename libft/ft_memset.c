/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:20:44 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/01 13:42:01 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *memdest, int ch, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)memdest)[i] = (unsigned char)ch;
		i++;
	}
	return (memdest);
}
