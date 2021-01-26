/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:53:19 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/23 23:36:53 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		put_echo_str(char *str)
{
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		if (ft_strncmp(str + j, "\\\"", 2) == 0)
			ft_putchar_fd('"', 1);
		else if (str[j] != '"' && str[j] != '\'')
			ft_putchar_fd(str[j], 1);
		j++;
	}
}

void		print_err(t_pars *s_pars)
{
	char	*s;

	if (s_pars->err == 3)
	{
		ft_putstr_fd((s = ft_itoa(s_pars->err + 128)), 1);
	}
	else if (s_pars->status != 1)
	{
		ft_putstr_fd((s = ft_itoa(WEXITSTATUS(s_pars->err))), 1);
	}
	else
	{
		ft_putstr_fd((s = ft_itoa(s_pars->err)), 1);
	}
	s_pars->err = 0;
	s_pars->status = 0;
	free(s);
}

char		*echo_one(t_pars *s_pars, int y, int i)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = s_pars->cmd[y][i]))
	{
		ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		return (NULL);
	}
	else
		return (str);
}

int			do_echo(t_pars *s_pars, int y, int i)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = echo_one(s_pars, y, i)))
		return (1);
	if (ft_strncmp(str, "-n", 2) == 0)
	{
		flag = 1;
		i++;
		str = s_pars->cmd[y][i];
	}
	while (str != NULL && check_separator(str) == -1)
	{
		(ft_strnstr(str, "$?", ft_strlen(str)) != NULL) ?
		print_err(s_pars) : put_echo_str(str);
		i++;
		str = s_pars->cmd[y][i];
		if (str != NULL)
			ft_putchar_fd(' ', 1);
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
	return (1);
}
