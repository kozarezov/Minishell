/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:45:44 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/03 10:45:46 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') ||
	(ch >= 'a' && ch <= 'z'))
		return (1);
	return (0);
}
