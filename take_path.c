/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:55:48 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/20 16:15:10 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*search_path(t_pars *s_pars, char *str)
{
	t_env	*tmp;

	tmp = s_pars->env;
	while (tmp)
	{
		if (ft_strncmp(str, tmp->name, ft_strlen(tmp->name)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char		*open_dir(t_pars *s_pars, int y, char *old_path)
{
	int		i;
	char	**temp;
	char	*tmp;
	char	*dir;
	int		fd;

	i = 0;
	temp = ft_split(old_path, ':');
	while (temp[i] != NULL)
	{
		tmp = ft_strjoin(temp[i], "/");
		dir = ft_strjoin(tmp, s_pars->cmd[y][0]);
		free(tmp);
		fd = open(dir, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			clear_temp(temp);
			return (dir);
		}
		i++;
	}
	clear_temp(temp);
	return (NULL);
}

char		*if_path(t_pars *s_pars, int y, char *old_path)
{
	char	*path;
	char	*dir;
	char	*str;

	str = s_pars->cmd[y][0];
	if (ft_strnstr(str, "/", ft_strlen(str)) != NULL)
	{
		path = ft_strdup(str);
		return (path);
	}
	if (ft_strnstr(old_path, "/", ft_strlen(old_path)) != NULL)
	{
		if (!(dir = open_dir(s_pars, y, old_path)))
			return (str);
		path = ft_strdup(dir);
		free(dir);
		return (path);
	}
	else
	{
		path = ft_strjoin(old_path, s_pars->cmd[y][0]);
		return (path);
	}
}

char		*take_path(int y, t_pars *s_pars, char *need)
{
	char	*old_path;

	if (!(old_path = search_path(s_pars, need)))
		return (s_pars->cmd[y][0]);
	if (need[0] == 'P')
		return (if_path(s_pars, y, old_path));
	else
		return (old_path);
}
