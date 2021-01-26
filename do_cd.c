/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:56:24 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/23 21:53:57 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		write_error_cd(t_pars *s_pars, int y)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(s_pars->cmd[y][1], 1);
	ft_putstr_fd(": No such file or directory\n", 2);
	s_pars->err = 1;
	s_pars->status = 1;
}

int			do_cd(t_pars *s_pars, int y)
{
	char	*path;
	char	*tmp;

	path = take_path(y, s_pars, "HOME");
	if (s_pars->cmd[y][1] != NULL)
	{
		if (s_pars->cmd[y][1][0] == '~')
		{
			tmp = ft_strdup(s_pars->cmd[y][1]);
			s_pars->cmd[y][1] = ft_strjoin(path, tmp + 1);
			free(tmp);
		}
		if (chdir(s_pars->cmd[y][1]) != 0)
			write_error_cd(s_pars, y);
	}
	else
	{
		if (path[0] == 'c')
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		chdir(path);
	}
	return (1);
}
