/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:47:38 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/23 23:48:47 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		search_eq(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			str[i] = '\0';
		i++;
	}
}

int			go_to_environ(char *str, t_pars *s_pars)
{
	t_env	*tmp;
	char	*name;
	char	*value;

	search_eq(str);
	tmp = s_pars->env;
	while (tmp)
	{
		if (ft_strncmp(str, tmp->name, ft_strlen(str)) == 0)
		{
			tmp->environ = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	name = ft_strdup(str);
	value = ft_strdup(" \0");
	ft_add_back(&s_pars->env, ft_new(name, value, 1));
	return (0);
}

int			export_nothing(t_pars *s_pars)
{
	t_env	*tmp;
	int		i;

	i = 655;
	while (i < 1233)
	{
		tmp = s_pars->env;
		while (tmp)
		{
			if (tmp->environ == 1 && tmp->sort == i)
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putstr_fd(tmp->name, 1);
				ft_putstr_fd("=", 1);
				ft_putstr_fd("\"", 1);
				ft_putstr_fd(tmp->value, 1);
				ft_putstr_fd("\"", 1);
				ft_putstr_fd("\n", 1);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (1);
}

int			env_error(char *str, t_pars *s_pars, int y)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == ' ' || (str[j] >= 33 && str[j] <= 64))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(s_pars->cmd[y][0], 2);
			ft_putstr_fd(": '", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("'", 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			s_pars->err = 1;
			s_pars->status = 1;
			return (0);
		}
		j++;
	}
	return (1);
}

int			do_export(t_pars *s_pars, int y)
{
	char	*str;
	int		i;

	i = 1;
	str = s_pars->cmd[y][i];
	if (str == NULL)
	{
		export_nothing(s_pars);
		return (1);
	}
	while (str != NULL)
	{
		if (env_error(str, s_pars, y) == 1)
			go_to_environ(str, s_pars);
		i++;
		str = s_pars->cmd[y][i];
	}
	return (0);
}
