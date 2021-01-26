/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:23:07 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/21 15:23:09 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			write_error_collision(t_pars *s_pars, int i, int j)
{
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 1);
		ft_putchar_fd(s_pars->s_e[i][j], 1);
		ft_putstr_fd("`\n", 1);
		return (1);
	}
}

int			check_colision_line(t_pars *s_pars)
{
	int		i;
	int		j;

	i = 0;
	while (s_pars->s_e[i] != NULL)
	{
		j = 0;
		while (s_pars->s_e[i][j] != '\0')
		{
			if ((s_pars->s_e[i][j] == '|' && s_pars->s_e[i][j + 1] == '|') ||
			(s_pars->s_e[i][j] == '|' && s_pars->s_e[i + 1] != NULL &&
			s_pars->s_e[i + 1][0] == ';') || (s_pars->s_e[i][0] == ';' &&
			s_pars->s_e[i + 1] != NULL && s_pars->s_e[i + 1][0] == ';') ||
			(s_pars->s_e[0][0] == ';') || (s_pars->s_e[0][0] == '|') ||
			(s_pars->s_e[i][j] == '|' && s_pars->s_e[i + 1] == NULL) ||
			(s_pars->s_e[i][j] == '>' && s_pars->s_e[i][j + 1] != '\0' &&
			s_pars->s_e[i][j + 2] != '\0' && s_pars->s_e[i][j + 1] == '>' &&
			s_pars->s_e[i][j + 2] == '>') || (s_pars->s_e[i][j] == '<' &&
			s_pars->s_e[i][j + 1] != '\0' && s_pars->s_e[i][j + 1] == '<'))
				return (write_error_collision(s_pars, i, j));
			j++;
		}
		i++;
	}
	return (0);
}
