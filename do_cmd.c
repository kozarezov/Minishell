/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 08:36:15 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/22 14:52:38 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		***do_cmd(t_pars *s_pars, int i, int j, int k)
{
	char	***cmd;

	while (s_pars->s_e[s_pars->position + i] != NULL &&
	s_pars->s_e[s_pars->position + i][0] != ';')
		i++;
	cmd = (char ***)malloc((i + 1) * sizeof(char**));
	cmd[0] = (char **)malloc(10 * sizeof(char *));
	while (s_pars->s_e[s_pars->position] != NULL &&
	s_pars->s_e[s_pars->position][0] != ';')
	{
		if (s_pars->s_e[s_pars->position][0] != '|')
			cmd[j][k++] = s_pars->s_e[s_pars->position];
		else
		{
			cmd[j++][k] = NULL;
			k = 0;
			cmd[j] = (char **)malloc(10 * sizeof(char *));
		}
		s_pars->position++;
	}
	if (k != 0)
		cmd[j++][k] = NULL;
	cmd[j] = NULL;
	return (cmd);
}
