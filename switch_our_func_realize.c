/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_our_func_realize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:14:05 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/23 23:09:20 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		our_command(int i, int y, t_pars *s_pars)
{
	if (i == 6)
		do_exit(0, s_pars);
	if (i == 2)
		do_pwd();
	if (i == 0)
		do_echo(s_pars, y, 1);
	if (i == 1)
		do_cd(s_pars, y);
	if (i == 5)
		do_env(s_pars);
	if (i == 3)
		do_export(s_pars, y);
	if (i == 4)
		do_unset(s_pars, y);
	return (0);
}
