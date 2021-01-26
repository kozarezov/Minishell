/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:50:53 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/04 12:50:56 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t size)
{
	size_t *res;

	if (!(res = (size_t *)malloc(size * num)))
		return (0);
	ft_memset(res, '\0', size * num);
	return (res);
}
