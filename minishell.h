/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:48:44 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/22 22:39:25 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <signal.h>
# include <errno.h>

typedef	struct		s_env
{
	char			*name;
	char			*value;
	int				environ;
	int				sort;
	struct s_env	*next;
}					t_env;

typedef struct		s_pipe
{
	int				p[2];
	int				fd_in;
	pid_t			pid;
}					t_pipe;

typedef struct		s_pars
{
	int				position;
	char			***cmd;
	char			**s_e;
	char			**environ;
	t_env			*env;
	t_pipe			*pipe;
	int				flag_eof;
	int				flag_quit;
	int				err;
	int				status;
}					t_pars;

int					g_flag_quit;
int					get_next_line(int fd, char **line);
void				prompt_string();
char				*our_command_list(int i);
char				*our_separator_list(int i);
int					do_pwd();
int					do_echo(t_pars *s_pars, int y, int i);
int					do_cd(t_pars *s_pars, int y);
int					check_separator(char *str);
int					check_command(char *str);
int					standart_command(t_pars *s_pars);
void				clear_s_e(t_pars *s_pars, char *line);
char				**split_with_all_separator(char *line);
int					parse_env(t_pars *s_pars);
void				clear_env(t_env **lst);
void				do_exit(int i, t_pars *s_pars);
int					search_env(t_pars *s_pars, char **str, int pos);
void				add_environ(t_pars *s_pars);
void				skip_arg_before_separator(t_pars *s_pars);
int					lsh_launch(t_pars *s_pars);
int					do_env(t_pars *s_pars);
int					do_export(t_pars *s_pars, int y);
void				ft_add_back(t_env **lst, t_env *new);
t_env				*ft_new(char *name, char *value, int env);
int					do_unset(t_pars *s_pars, int y);
char				*take_path(int y, t_pars *s_pars, char *need);
void				write_command_not_found(t_pars *s_pars, int y, int i);
int					our_command(int i, int y, t_pars *s_pars);
int					do_redirection(t_pars *s_pars, int y, int j);
void				clear_temp(char **tmp);
char				***do_cmd(t_pars *s_pars, int i, int j, int k);
void				lets_work(t_pars *s_pars, char *line);
void				do_signal(int sig);
char				***do_cmd(t_pars *s_pars, int i, int j, int k);
int					check_colision_line(t_pars *s_pars);
void				clear_cmd(t_pars *s_pars);
void				delete_apostrof(t_pars *s_pars);
int					env_error(char *str, t_pars *s_pars, int y);

#endif
