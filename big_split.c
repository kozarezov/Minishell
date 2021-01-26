/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 08:52:54 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/19 19:05:51 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**clear_all(int j, char **res)
{
	while (j > 0)
		free(res[--j]);
	free(res);
	return (NULL);
}

int			check_some_symvols(char *l, int i, int w)
{
	if (l[i] == ' ')
		while (l[i + w] == ' ' && l[i + w] != '\0')
			w++;
	if (l[i] == '>')
		while (l[i + w] == '>' && l[i + w] != '\0')
			w++;
	if (l[i] == '<')
		while (l[i + w] == '<' && l[i + w] != '\0')
			w++;
	return (w);
}

int			count_lenght_word(char *l, int i, int w)
{
	if (ft_strchr(";|><\'\"", l[i]) == NULL)
		while ((ft_strchr(" ;|><\'\"", l[i + w]) == NULL && l[i + w] != '\0') ||
		((i + w) > 0 && ft_strchr("\\", l[i + w - 1]) != NULL))
			w++;
	w = check_some_symvols(l, i, w);
	if (l[i] == '"' && ++w != 0)
		while ((l[i + w] != '\"' && l[i + w] != '\0') || (l[i + w] == '"'
		&& (i + w - 1) != 0 && l[i + w - 1] == '\\'))
			w++;
	if (l[i] == '\'' && ++w != 0)
		while ((l[i + w] != '\'' && l[i + w] != '\0') || (l[i + w] == '\''
		&& (i + w - 1) != 0 && l[i + w - 1] == '\\'))
			w++;
	if (((l[i + w] == ';' || l[i + w] == '|') && w == 0) || l[i + w] == '=')
		w++;
	if (((l[i + w] == '"' && l[i] == '"') || (l[i + w] == '\'' &&
	l[i] == '\'')) && w != 0)
		w++;
	return (w);
}

char		**split_with_all_separator(char *line)
{
	int		i;
	int		j;
	int		lenght_word;
	char	**res;

	i = 0;
	j = 0;
	if (!(res = (char **)malloc(ft_strlen(line) * sizeof(char*))))
		return (NULL);
	while (line[i] != '\0')
	{
		lenght_word = count_lenght_word(line, i, 0);
		if (line[i] != ' ')
		{
			if (!(res[j] = (char *)malloc(lenght_word + 1)))
				return (clear_all(j, res));
			ft_strlcpy(res[j++], line + i, lenght_word + 1);
		}
		i = i + lenght_word;
	}
	res[j] = NULL;
	return (res);
}
