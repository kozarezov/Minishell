/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 09:26:09 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/23 22:51:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_redirection(t_pars *s_pars, int y)
{
	int		j;

	j = 0;
	while (s_pars->cmd[y][j] != NULL)
	{
		if (ft_strchr("<>", s_pars->cmd[0][j][0]) != NULL)
			return (1);
		j++;
	}
	return (0);
}

void		lets_work(t_pars *s_pars, char *line)
{
	int		flag;

	while (s_pars->s_e[s_pars->position] != NULL)
	{
		if (check_colision_line(s_pars) == 0)
		{
			s_pars->cmd = do_cmd(s_pars, 0, 0, 0);
			delete_apostrof(s_pars);
			flag = check_redirection(s_pars, 0);
			if (s_pars->cmd[0][0] != NULL && s_pars->cmd[1] == NULL &&
			flag == 0)
				if (check_command(s_pars->cmd[0][0]) != -1)
					our_command(check_command(s_pars->cmd[0][0]), 0, s_pars);
				else
					lsh_launch(s_pars);
			else
				lsh_launch(s_pars);
			if (s_pars->s_e[s_pars->position] != NULL)
				s_pars->position++;
			clear_cmd(s_pars);
		}
	}
	clear_s_e(s_pars, line);
}

char		*read_input_line(char *line, int i)
{
	int		j;

	if ((j = get_next_line(0, &line)) > 0)
	{
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (ft_strlen(line) != 0 && i != ft_strlen(line))
			return (line);
	}
	return (NULL);
}

void		main_loop(t_pars *s_pars)
{
	char	*line;
	int		flag_eof;

	(void)signal(SIGINT, do_signal);
	(void)signal(SIGQUIT, do_signal);
	while (1)
	{
		g_flag_quit = 0;
		prompt_string();
		if ((flag_eof = get_next_line(0, &line)) > 0)
		{
			s_pars->s_e = split_with_all_separator(line);
			s_pars->position = 0;
			if (check_colision_line(s_pars) == 0)
			{
				parse_env(s_pars);
				lets_work(s_pars, line);
			}
		}
		else
			do_exit(s_pars->err, s_pars);
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_pars	*s_pars;
	t_pipe	*s_pipe;

	if (argc >= 0 && argv)
	{
		s_pars = malloc(sizeof(t_pars));
		s_pipe = malloc(sizeof(t_pipe));
		s_pars->pipe = s_pipe;
		s_pars->env = NULL;
		s_pars->environ = envp;
		s_pars->flag_eof = 0;
		s_pars->err = 0;
		s_pars->status = 0;
		g_flag_quit = 0;
		add_environ(s_pars);
		main_loop(s_pars);
		clear_env(&s_pars->env);
		free(s_pars);
	}
	return (0);
}
