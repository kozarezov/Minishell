/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:48:03 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/23 23:35:16 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			skip_arg_before_separator(t_pars *s_pars)
{
	while (s_pars->s_e[s_pars->position] != NULL &&
		ft_strchr(";|", s_pars->s_e[s_pars->position][0]) == NULL)
		s_pars->position++;
}

int				check_separator(char *str)
{
	int			i;
	const char	*command_list[] = {";", "'", ">>", ">", "<", "|"};

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(str, (char*)command_list[i], ft_strlen(str)) == 0 &&
		ft_strlen(str) == ft_strlen((char*)command_list[i]))
			return (i);
		i++;
	}
	return (-1);
}

int				check_command(char *str)
{
	int			i;
	const char	*command_list[] = {"echo", "cd", "pwd", "export", \
		"unset", "env", "exit"};

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp((char*)command_list[i], str,
		ft_strlen((char*)command_list[i])) == 0 &&
		ft_strlen(str) == ft_strlen((char*)command_list[i]))
			return (i);
		i++;
	}
	return (-1);
}

void			write_command_not_found(t_pars *s_pars, int y, int i)
{
	ft_putstr_fd("minishell: ", 2);
	if (ft_strncmp("$?", s_pars->cmd[y][0], 2) == 0)
		if (s_pars->err > 127)
			ft_putnbr_fd(127, 2);
		else
			ft_putnbr_fd(s_pars->err, 2);
	else
	{
		while (s_pars->cmd[y][0][i])
		{
			if (s_pars->cmd[y][0][i] != '\'' && s_pars->cmd[y][0][i] != '"')
			{
				if (s_pars->cmd[y][0][i] == '\\')
					ft_putchar_fd(s_pars->cmd[y][0][++i], 2);
				else
					ft_putchar_fd(s_pars->cmd[y][0][i], 2);
			}
			i++;
		}
	}
	ft_putstr_fd(": command not found\n", 2);
	s_pars->err = 127;
	s_pars->status = 1;
	exit(127);
}

void			delete_apostrof(t_pars *s_pars)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (s_pars->cmd[i])
	{
		j = 0;
		while (s_pars->cmd[i][j])
		{
			if (s_pars->cmd[i][j][0] == '"' || s_pars->cmd[i][j][0] == '\'')
			{
				k = 0;
				while (++k <= ft_strlen(s_pars->cmd[i][j]) - 2)
					s_pars->cmd[i][j][k - 1] = s_pars->cmd[i][j][k];
				if (ft_strlen(s_pars->cmd[i][j]) - 2 == 0)
					s_pars->cmd[i][j][k++ - 1] = ' ';
				s_pars->cmd[i][j][k - 1] = '\0';
			}
			j++;
		}
		i++;
	}
}
