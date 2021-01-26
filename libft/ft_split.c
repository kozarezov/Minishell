/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgarth <cgarth@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:53:58 by cgarth            #+#    #+#             */
/*   Updated: 2020/05/06 13:53:59 by cgarth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	delete_characters(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	lenght_word(char const *s, char c, size_t i)
{
	size_t y;

	y = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i - y);
}

static char		**return_res(char **res, size_t j)
{
	res[j] = NULL;
	return (res);
}

static char		**split_it(char const *s, char c, size_t word_count, size_t j)
{
	size_t	i;
	size_t	k;
	char	**res;

	i = 0;
	k = 0;
	if (!(res = (char **)malloc((word_count + 1) * (sizeof((char*)s)))))
		return (NULL);
	i = delete_characters(s, c, i);
	while (s[i] != '\0')
	{
		if (!(res[j] = (char *)malloc(lenght_word(s, c, i) + 1)))
		{
			while (j > 0)
				free(res[--j]);
			free(res);
			return (NULL);
		}
		k = 0;
		while (s[i] != c && s[i] != '\0')
			res[j][k++] = s[i++];
		i = delete_characters(s, c, i);
		res[j++][k] = '\0';
	}
	return (return_res(res, j));
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			i = delete_characters(s, c, i);
			if (lenght_word(s, c, i) > 0)
			{
				i = i + lenght_word(s, c, i);
				word_count++;
			}
		}
		return (split_it(s, c, word_count, 0));
	}
	return (NULL);
}
