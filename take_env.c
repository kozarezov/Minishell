/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:07:42 by ceccentr          #+#    #+#             */
/*   Updated: 2020/09/22 17:25:58 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*take_str_for_env(char *str, int pos)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i + pos] != '\0' && str[i + pos] \
		!= '$' && str[i + pos] != ' ' && str[i + pos] != '"')
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i + pos] != '\0' && str[i + pos] \
		!= '$' && str[i + pos] != ' ' && str[i + pos] != '"')
	{
		s[i] = str[i + pos];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*take_env(t_pars *s_pars, char *str, int pos)
{
	char	*s;
	t_env	*tmp;

	pos++;
	tmp = s_pars->env;
	s = take_str_for_env(str, pos);
	if (s[0] == '?')
		return (NULL);
	while (tmp)
	{
		if (ft_strncmp(s, tmp->name, ft_strlen(s)) == 0)
		{
			free(s);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	free(s);
	return (" ");
}

int			*ft_temp_str(char *temp, int pos, char *str)
{
	int		i;

	pos++;
	i = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '$' || str[pos] == ' ')
		{
			while (str[i + pos] != '\0')
			{
				temp[i] = str[i + pos];
				i++;
			}
			temp[i] = '\0';
			return (0);
		}
		pos++;
	}
	temp[i] = '\0';
	return (0);
}

int			search_env(t_pars *s_pars, char **str, int pos)
{
	char	*buf;
	char	*temp;
	char	*temp_str;

	if (!(temp = take_env(s_pars, *str, pos)))
		return (0);
	if (!(buf = malloc(sizeof(char) * (ft_strchr(*str, '$') - *str + 1))))
		return (0);
	ft_strlcpy(buf, *str, (ft_strchr(*str, '$') - *str + 1));
	if (!(temp_str = malloc(sizeof(char) * \
		(ft_strlen(*str) + ft_strlen(temp)) + 1)))
		return (0);
	ft_temp_str(temp_str, pos, *str);
	free(*str);
	if (!(*str = ft_strjoin(buf, temp)))
		return (0);
	free(buf);
	if (!(buf = ft_strdup(*str)))
		return (0);
	free(*str);
	if (!(*str = ft_strjoin(buf, temp_str)))
		return (0);
	free(temp_str);
	free(buf);
	return (0);
}
