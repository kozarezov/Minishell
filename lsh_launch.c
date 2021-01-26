/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:14:05 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/23 23:33:46 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_command_and_exe(t_pars *s_pars, int y)
{
	int		i;
	int		j;
	char	*path;

	j = 0;
	while (s_pars->cmd[y][j] != NULL)
	{
		if (ft_strchr("<>", s_pars->cmd[y][j][0]) != NULL)
		{
			do_redirection(s_pars, y, j);
			return (1);
		}
		j++;
	}
	if ((i = check_command((s_pars->cmd)[y][0])) != -1)
		our_command(i, y, s_pars);
	else
	{
		path = take_path(y, s_pars, "PATH");
		if ((execve(path, s_pars->cmd[y], s_pars->environ)) == -1)
			write_command_not_found(s_pars, y, 0);
	}
	return (1);
}

void		do_pipe(t_pars *s_pars, int i)
{
	while (s_pars->cmd[i] != NULL)
	{
		pipe(s_pars->pipe->p);
		s_pars->pipe->pid = fork();
		if (s_pars->pipe->pid == -1)
			exit(1);
		else if (s_pars->pipe->pid == 0)
		{
			dup2(s_pars->pipe->fd_in, 0);
			if (s_pars->cmd[i + 1] != NULL)
				dup2(s_pars->pipe->p[1], 1);
			close(s_pars->pipe->p[0]);
			check_command_and_exe(s_pars, i);
			exit(2);
		}
		else
		{
			g_flag_quit = 1;
			wait(&s_pars->err);
			close(s_pars->pipe->p[1]);
			s_pars->pipe->fd_in = s_pars->pipe->p[0];
			i++;
		}
	}
}

int			lsh_launch(t_pars *s_pars)
{
	s_pars->pipe->fd_in = 0;
	do_pipe(s_pars, 0);
	return (1);
}
