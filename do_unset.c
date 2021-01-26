/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:24:47 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/22 22:39:19 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_it_env(char *str, t_env **lst, t_env *tmp)
{
	if (ft_strncmp(str, tmp->name, ft_strlen(str)) == 0)
	{
		*lst = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		return (1);
	}
	return (0);
}

int			del_environ(char *str, t_env **lst)
{
	t_env	*tmp;
	t_env	*buf;

	tmp = *lst;
	if (is_it_env(str, lst, tmp) == 1)
		return (1);
	buf = tmp->next;
	while (buf)
	{
		if (ft_strncmp(str, buf->name, ft_strlen(str)) == 0)
		{
			tmp->next = buf->next;
			free(buf->name);
			free(buf->value);
			free(buf);
			return (1);
		}
		tmp = buf;
		buf = buf->next;
	}
	return (0);
}

int			do_unset(t_pars *s_pars, int y)
{
	char	*str;
	int		i;

	i = 1;
	str = s_pars->cmd[y][i];
	if (str == NULL || check_separator(str) != -1)
		return (1);
	while (str != NULL && check_separator(str) == -1)
	{
		if (env_error(str, s_pars, y) == 1)
			del_environ(str, &s_pars->env);
		i++;
		str = s_pars->cmd[y][i];
	}
	return (0);
}
