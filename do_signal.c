/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 15:19:26 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/22 16:33:21 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		do_signal(int sig)
{
	if (sig == SIGINT && g_flag_quit == 0)
	{
		write(1, "\b\b  \n", 5);
		prompt_string();
	}
	if (sig == SIGINT && g_flag_quit == 1)
		ft_putstr_fd("\n", 1);
	if (sig == SIGQUIT && g_flag_quit == 0)
	{
		write(1, "\b\b  \b\b", 6);
	}
	if (sig == SIGQUIT && g_flag_quit == 1)
	{
		ft_putstr_fd("Quit: 3\n", 1);
		g_flag_quit = 0;
	}
}
