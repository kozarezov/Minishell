/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:51:19 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/08 11:51:21 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lst_begin;

	if (*lst)
	{
		lst_begin = *lst;
		while (lst_begin->next)
			lst_begin = lst_begin->next;
		lst_begin->next = new;
	}
	else
		*lst = new;
}
