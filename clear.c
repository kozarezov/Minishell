/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:31:57 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/22 17:10:05 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		clear_temp(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void		clear_env(t_env **lst)
{
	t_env	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->name);
		free((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
}

void		clear_s_e(t_pars *s_pars, char *line)
{
	int		i;

	i = 0;
	while (s_pars->s_e[i] != NULL)
		free(s_pars->s_e[i++]);
	free(s_pars->s_e);
	free(line);
}

void		clear_cmd(t_pars *s_pars)
{
	int		i;

	i = 0;
	while (s_pars->cmd[i])
	{
		free(s_pars->cmd[i]);
		i++;
	}
	free(s_pars->cmd);
}
