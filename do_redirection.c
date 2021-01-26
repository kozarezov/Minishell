/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:34:36 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/22 22:22:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			go_open(t_pars *s_pars, int y, int lst)
{
	int fd;

	if (ft_strncmp(">>", s_pars->cmd[y][lst], 3) != 0)
		fd = open(s_pars->cmd[y][lst + 1], O_CREAT | \
			O_WRONLY | O_TRUNC, S_IRWXU);
	else
		fd = open(s_pars->cmd[y][lst + 1], O_CREAT | \
			O_WRONLY | O_APPEND, S_IRWXU);
	return (fd);
}

int			go_right(t_pars *s_pars, int y, int j, int lst)
{
	int		fd;
	int		i;
	char	*path;

	while (s_pars->cmd[y][j] != NULL)
	{
		if (ft_strchr(">", s_pars->cmd[y][j++][0]) != NULL)
		{
			if (lst > 0)
				close(fd);
			lst = j - 1;
			fd = go_open(s_pars, y, lst);
			s_pars->cmd[y][lst] = NULL;
		}
	}
	dup2(fd, 1);
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

int			go_left(t_pars *s_pars, int y, int j)
{
	int		fd;
	int		i;
	char	*path;
	int		lst;

	while (s_pars->cmd[y][j] != NULL)
	{
		if (ft_strchr("<", s_pars->cmd[y][j][0]) != NULL)
		{
			lst = j;
			s_pars->cmd[y][lst] = NULL;
		}
		j++;
	}
	fd = open(s_pars->cmd[y][lst + 1], O_RDONLY, S_IRWXU);
	dup2(fd, 0);
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

int			do_redirection(t_pars *s_pars, int y, int j)
{
	if (s_pars->cmd[y][j][0] == '>')
		go_right(s_pars, y, j, 0);
	else if (s_pars->cmd[y][j][0] == '<')
		go_left(s_pars, y, j);
	return (1);
}
