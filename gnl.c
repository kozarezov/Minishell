/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 13:55:58 by cgarth            #+#    #+#             */
/*   Updated: 2020/09/08 12:18:04 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			free_all_and_out(char *buf_tmp, int i)
{
	free(buf_tmp);
	buf_tmp = NULL;
	return (i);
}

char		*my_realloc(char *buf, char *buf_tmp, int i, int j)
{
	char	*str_tmp;

	while (i < 1 && (buf[i] != '\n' || buf[i] == 0))
		i++;
	while (buf_tmp[j] != '\0')
		j++;
	j = i + j + 1;
	if (!(str_tmp = (char *)malloc(j)))
		return (NULL);
	while (--j >= 0)
		str_tmp[j] = '\0';
	while (buf_tmp[++j] != '\0')
		str_tmp[j] = buf_tmp[j];
	free_all_and_out(buf_tmp, 0);
	buf_tmp = str_tmp;
	return (buf_tmp);
}

char		*add_line(char *buf_tmp, char *buf, char **line, int i)
{
	int	j;

	j = 0;
	while (buf_tmp[j] != '\0')
		j++;
	while (i < 1)
	{
		if (buf[i] == '\n')
		{
			buf_tmp[j + i++] = '\0';
			*line = buf_tmp;
			j = 0;
			while (i != 1)
				buf[j++] = buf[i++];
			i = j;
			while (i != 1)
				buf[i++] = '\0';
			return (NULL);
		}
		buf_tmp[j + i] = buf[i];
		buf[i++] = '\0';
	}
	return (buf_tmp);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	buf[2];
	char		*buf_tmp;

	if (!line)
		return (-1);
	ret = 1;
	buf_tmp = malloc(1);
	buf_tmp[0] = '\0';
	while (ret > 0)
	{
		if (buf[0] == '\0')
			ret = read(fd, buf, 1);
		if (buf[0] == 0)
			write(0, "  \b\b", 4);
		if (ret == -1 || !(buf_tmp = my_realloc(buf, buf_tmp, 0, 0)))
			return (free_all_and_out(buf_tmp, -1));
		if ((buf_tmp = add_line(buf_tmp, buf, line, 0)) == NULL)
			return (1);
		if (ret == 0 && ft_strlen(buf_tmp) != 0)
			ret = 1;
	}
	*line = buf_tmp;
	buf_tmp = NULL;
	return (free_all_and_out(buf_tmp, 0));
}
