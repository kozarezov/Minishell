/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:34:27 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/24 00:04:00 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			reset_env(t_pars *s_pars, char *name, char *value)
{
	t_env	*tmp;

	tmp = s_pars->env;
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, ft_strlen(name)) == 0)
		{
			if (ft_strncmp(value, tmp->value, ft_strlen(value)) == 0)
			{
				free(name);
				free(value);
				return (1);
			}
			else
			{
				free(name);
				free(tmp->value);
				tmp->value = value;
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

void		add_env(t_pars *s_pars, int i)
{
	char	**tmp;
	char	*name;
	char	*value;

	tmp = ft_split(s_pars->s_e[i], '=');
	name = ft_strdup(tmp[0]);
	value = ft_strdup(tmp[1]);
	if (reset_env(s_pars, name, value) == 0)
		ft_add_back(&s_pars->env, ft_new(name, value, 0));
	clear_temp(tmp);
}

void		add_environ(t_pars *s_pars)
{
	int		i;
	char	**tmp;
	char	*name;
	char	*value;

	i = 0;
	while (s_pars->environ[i] != NULL)
	{
		tmp = ft_split(s_pars->environ[i], '=');
		name = ft_strdup(tmp[0]);
		value = ft_strdup(tmp[1]);
		if (reset_env(s_pars, name, value) == 0)
			ft_add_back(&s_pars->env, ft_new(name, value, 1));
		clear_temp(tmp);
		i++;
	}
}

int			parse_env(t_pars *s_pars)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while (s_pars->s_e[i] != NULL)
	{
		j = 0;
		flag = 0;
		while (s_pars->s_e[i][j] != '\0')
		{
			if (s_pars->s_e[i][j] == '\'')
				flag = 1;
			if (s_pars->s_e[i][j] == '=')
			{
				add_env(s_pars, i);
				s_pars->s_e[i][j] = '\0';
			}
			if (s_pars->s_e[i][j] == '$' && flag == 0)
				j = search_env(s_pars, &s_pars->s_e[i], j);
			j++;
		}
		i++;
	}
	return (1);
}
