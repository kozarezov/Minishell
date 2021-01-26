/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:14:05 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/19 18:47:18 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			do_pwd(void)
{
	char	*buf;
	char	*line;

	buf = NULL;
	line = getcwd(buf, 0);
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n", 1);
	free(buf);
	free(line);
	return (0);
}
